// c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
// cpp
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#define my_err(format)      { \
                                    fprintf(stderr, "(File:%s, Line:%d) ", __FILE__, __LINE__); \
                                    perror(format); \
                                    exit(1); \
                            } \

enum move_type {
  move_none,
  move_down,
  move_right,
  move_diagonal
};

map<move_type, const char*> color = {
	{move_down, "\033[32m"},
	{move_right, "\033[31m"},
	{move_diagonal, "\033[39m"},
	{move_none, "\033[0m"}
};

class Point {
  friend move_type compare(const Point &prev_point, const Point &point);
 public:
  Point(int x, int y) {
	this->x = x;
	this->y = y;
  }

  bool operator==(const Point &point) const {
	return this->x == point.x && this->y == point.y;
  }

  bool operator!=(const Point &point) const {
	return this->x != point.x || this->y != point.y;
  }

 public:
  int x = 0;
  int y = 0;
};

// compare previous point and point
move_type compare(const Point &prev_point, const Point &point) {
  if (prev_point.x == point.x && prev_point.y + 1 == point.y) {
	return move_down;
  } else if (prev_point.y == point.y && prev_point.x + 1 == point.x) {
	return move_right;
  } else if (prev_point.x + 1 == point.x && prev_point.y + 1 == point.y) {
	return move_diagonal;
  }
  return move_none;
}

// myers' diff algorithm:
// T1 and T2 should overload operator[] and size
// for example, T1 and T2 can be
// string to compare character
// or vector<T> to compare T
template<typename T1, typename T2>
void myers_diff(const T1 &lhs, const T2 &rhs) {
  int N = lhs.size();
  int M = rhs.size();
  // map to save v of every d
  vector<map<int, int>> res_v;
  // map to save x by k
  // k -> x
  map<int, int> v;
  // base point : (0,-1)
  v[1] = 0;
  bool go_ahead = true;
  // d: step(excludes move of diagonal)
  // k: x - y
  for (int d = 0; d <= N + M && go_ahead; d++) {
	for (int k = -d; k <= d; k = k + 2) {
	  // delete is preferred
	  // so move right is preferred
	  // so bigger x is preferred
	  bool down = (k == -d || (k != d && v[k - 1] < v[k + 1]));
	  int k_prev = down ? k + 1 : k - 1;
	  // start point
	  int x_start = v[k_prev];
	  int y_start = x_start - k_prev;
	  // temp(mid) point
	  int x_tmp = down ? x_start : x_start + 1;
	  int y_tmp = x_tmp - k;
	  // end point
	  int x_end = x_tmp;
	  int y_end = y_tmp;
	  // move along the diagonal
	  while (x_end < N && y_end < M && lhs[x_end] == rhs[y_end]) {
		++x_end;
		++y_end;
	  }
	  v[k] = x_end;
	  // the result is found
	  if (x_end >= N && y_end >= M) {
		go_ahead = false;
		break;
	  }
	}
	// store the result
	res_v.push_back(v);
  }

  // the fallback
  vector<Point> path;
  Point point(lhs.size(), rhs.size());
  path.push_back(point);
  for (int d = res_v.size() - 1; point.x > 0 || point.y > 0; --d) {
	auto X = res_v[d];
	int k = point.x - point.y;
	int x_end = X[k];
	int y_end = point.x - k;
	// whether move along the diagonal
	while (x_end > 0 && y_end > 0 && x_end <= N && y_end <= M && lhs[x_end - 1] == rhs[y_end - 1]) {
	  --x_end;
	  --y_end;
	  path.push_back(Point(x_end, y_end));
	}

	bool down = (k == -d || (k != d && X[k - 1] < X[k + 1]));
	int k_prev = down ? k + 1 : k - 1;

	int x_start = X[k_prev];
	int y_start = x_start - k_prev;

	path.push_back(Point(x_start, y_start));

	point.x = x_start;
	point.y = y_start;
  }

  // pop (0,-1)
  path.pop_back();

  // compare and print
  if (path.size() >= 2) {
	int size = path.size();
	for (int i = size - 2; i >= 0; --i) {
	  Point prev_point = path[i + 1];
	  move_type type = compare(prev_point, path[i]);
	  switch (type) {
		case move_right: {
		  cout << color[move_right] << "-" << lhs[prev_point.x] << endl;
		  break;
		}
		case move_down: {
		  cout << color[move_down] << "+" << rhs[prev_point.y] << endl;
		  break;
		}
		case move_diagonal: {
		  cout << color[move_diagonal] << "=" << lhs[prev_point.x] << endl;
		  break;
		}
	  }
	}
  }
}

const int completed_option_nums = 2;
const double double_min_interval = 1e-6;

long int diff_item_num = 0, same_item_num = 0,
	added_item_num = 0, deleted_item_num = 0;

// split std::string by sep
// then return a vector<string> to store the result
vector<string> split_string(const string &str, const string &sep) {
  vector<string> res;
  string temp_s = str + sep;
  size_t pos = temp_s.find(sep);
  size_t size = temp_s.size();

  while (pos != string::npos) {
    // escape empty string(when sep is in the end)
	if (pos == 0)
	  break;
	string s = temp_s.substr(0, pos);
	res.push_back(s);
	temp_s = temp_s.substr(pos + 1, size);
	pos = temp_s.find(sep);
  }
  return res;
}

// parse from a filename to a json object
struct cJSON *cJSON_ParseFilename(const char *filename) {
  int fd = open(filename, O_RDONLY);
  if (fd == -1) my_err("open error");

  // obtain file size
  struct stat file_stat;
  if (fstat(fd, &file_stat) == -1) my_err("fstat error");
  __off_t size = file_stat.st_size;

  // read file by size
  char read_buf[size + 1];
  read(fd, (void *)read_buf, size);
  read_buf[size] = '\0';

  if (close(fd) == -1) my_err("close error");
  return cJSON_Parse(read_buf);
}

// judge buf whether is number key
int is_number_key(const char *buf) {
  // number Key won't be printed
  // atoi return 0 when error happens or string is "0"
  if ((atoi(buf) != 0) && (!(*buf == '0' && (buf[1] == '\0'))))
    return 0;
  return 1;
}

// compare normal cJSON Object and print
int cJSON_ComparePrintNormal(const struct cJSON *object1, const struct cJSON *object2, const char *dst_str) {
  const struct cJSON *json1, *json2;
  json1 = cJSON_GetObjectItem(object1, dst_str);
  json2 = cJSON_GetObjectItem(object2, dst_str);

  // avoid null cJSON object
  if ((!json1) || (!json2))
	return -1;

  // classify and compare
  if (cJSON_IsString(json1) && cJSON_IsString(json2)) {
	// for cJSON String Object
	const char *str1, *str2;
	str1 = cJSON_GetStringValue(json1);
	str2 = cJSON_GetStringValue(json2);

	if (strcmp(str1, str2) != 0) {
	  diff_item_num++;
	  if (is_number_key(dst_str))
		printf("%s : \n", dst_str);
	  cout << color[move_right] << "-" << str1 << endl << color[move_none];
	  cout << color[move_down] << "+" << str2 << endl << color[move_none];
	} else {
	  same_item_num++;
	}
  } else if (cJSON_IsNumber(json1) && cJSON_IsNumber(json2)) {
	// for cJSON Number object
	double d1, d2;
	d1 = cJSON_GetNumberValue(json1);
	d2 = cJSON_GetNumberValue(json2);

	if (fabs(d1 - d2) > double_min_interval) {
	  diff_item_num++;
	  if (is_number_key(dst_str))
		  printf("%s : \n", dst_str);
	  printf("%s-%.0lf\n%s+%.0lf\n%s",
		  color[move_right], d1, color[move_down], d2, color[move_none]);
	} else {
	  same_item_num++;
	}
  } else if (cJSON_IsObject(json1) && cJSON_IsObject(json2)) {
	// for cJSON Object like "Version":      {
	//                         "0":    1,
	//                         "1":    "(current)"
	//                 },
	char nk_buf[11];    // number key buffer (0, 1, ...)
	// INT_MAX is 2147483647
	sprintf(nk_buf, "%d", 0);
	while (cJSON_ComparePrintNormal(json1, json2, nk_buf) != -1) {
	  // 0 to 1 to ...
	  int nk = atoi(nk_buf);
	  sprintf(nk_buf, "%d", ++nk);
	}
  } else {
	printf("%s\n", dst_str);
	my_err("cJSON_ComparePrintNormal error");
  }
  return 0;
}

// compare option h then output
void compare_option_h(const char *filename1, const char *filename2) {
  struct cJSON *object1 = cJSON_ParseFilename(filename1);
  struct cJSON *object2 = cJSON_ParseFilename(filename2);
  struct cJSON *temp1_cJSON, *temp2_cJSON;
  temp1_cJSON = cJSON_GetObjectItem(object1, "ELF Header");
  temp2_cJSON = cJSON_GetObjectItem(object2, "ELF Header");

  printf("<option h> : \n");

  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "OS/ABI");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "ABI Version");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Type");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Machine");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Version");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Entry point address");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Start of program headers");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Start of section headers");

  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Size of this header");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Size of program headers");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Number of program headers");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Size of section headers");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Number of section headers");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Section header string table index");

  // just delete root cJSON object
  // otherwise cause double-free
  cJSON_Delete(object1);
  cJSON_Delete(object2);
}

// compare option S then output
void compare_option_S(const char *filename1, const char *filename2) {
  struct cJSON *object1 = cJSON_ParseFilename(filename1);
  struct cJSON *object2 = cJSON_ParseFilename(filename2);
  struct cJSON *temp1_cJSON, *temp2_cJSON;
  temp1_cJSON = cJSON_GetObjectItem(object1, "Section Headers");
  temp2_cJSON = cJSON_GetObjectItem(object2, "Section Headers");

  printf("<option S> \n");

  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "elf_header.e_shnum");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "elf_header.e_shoff");

  // compare Section Headers
  struct cJSON *temp1_array_cJSON, *temp2_array_cJSON;
  temp1_array_cJSON = cJSON_GetObjectItem(temp1_cJSON, "Section Headers");
  temp2_array_cJSON = cJSON_GetObjectItem(temp2_cJSON, "Section Headers");

  printf("Section Headers : \n");

  int array_size = cJSON_GetArraySize(temp1_array_cJSON);
  if (array_size != cJSON_GetArraySize(temp2_array_cJSON)) my_err("cJSON_GetArraySize error");

  for (int i = 0; i < array_size; ++i) {
	temp1_cJSON = cJSON_GetArrayItem(temp1_array_cJSON, i);
	temp2_cJSON = cJSON_GetArrayItem(temp2_array_cJSON, i);

	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Name");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Type");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Off");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Size");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "ES");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Flg");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Lk");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Inf");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Al");
  }

  cJSON_Delete(object1);
  cJSON_Delete(object2);
}

// compare option l then output
void compare_option_l(const char *filename1, const char *filename2) {
  struct cJSON *object1 = cJSON_ParseFilename(filename1);
  struct cJSON *object2 = cJSON_ParseFilename(filename2);
  struct cJSON *temp1_cJSON, *temp2_cJSON;
  temp1_cJSON = cJSON_GetObjectItem(object1, "Program Header");
  temp2_cJSON = cJSON_GetObjectItem(object2, "Program Header");

  printf("<option l> : \n");

  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Elf file type\"");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Entry point");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "elf_header.e_phnum");
  cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "starting at offset");

  // compare Section Headers
  struct cJSON *temp1_array_cJSON, *temp2_array_cJSON;
  temp1_array_cJSON = cJSON_GetObjectItem(temp1_cJSON, "Program Headers");
  temp2_array_cJSON = cJSON_GetObjectItem(temp2_cJSON, "Program Headers");

  printf("Program Headers : \n");

  int array_size = cJSON_GetArraySize(temp1_array_cJSON);
  if (array_size != cJSON_GetArraySize(temp2_array_cJSON)) my_err("cJSON_GetArraySize error");

  for (int i = 0; i < array_size; ++i) {
	temp1_cJSON = cJSON_GetArrayItem(temp1_array_cJSON, i);
	temp2_cJSON = cJSON_GetArrayItem(temp2_array_cJSON, i);
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Type");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Offset");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "VirtAddr");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "PhysAddr");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "FileSiz");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "MemSiz");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Flg");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "Align");
  }

  cJSON_Delete(object1);
  cJSON_Delete(object2);
}

// compare option r then output
void compare_option_r(const char *filename1, const char *filename2) {
  struct cJSON *object1 = cJSON_ParseFilename(filename1);
  struct cJSON *object2 = cJSON_ParseFilename(filename2);
  struct cJSON *temp1_cJSON, *temp2_cJSON;
  temp1_cJSON = cJSON_GetObjectItem(object1, "Relocation");
  temp2_cJSON = cJSON_GetObjectItem(object2, "Relocation");

  printf("<option r> : \n");

  // compare .rel.dyn
  struct cJSON *temp1_array_cJSON, *temp2_array_cJSON;
  temp1_array_cJSON = cJSON_GetObjectItem(temp1_cJSON, ".rel.dyn");
  temp2_array_cJSON = cJSON_GetObjectItem(temp2_cJSON, ".rel.dyn");

  printf(".rel.dyn : \n");

  int array_size = cJSON_GetArraySize(temp1_array_cJSON);
  if (array_size != cJSON_GetArraySize(temp2_array_cJSON)) my_err("cJSON_GetArraySize error");

  for (int i = 0; i < array_size; ++i) {
	temp1_cJSON = cJSON_GetArrayItem(temp1_array_cJSON, i);
	temp2_cJSON = cJSON_GetArrayItem(temp2_array_cJSON, i);
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "offset");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "info");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "type");
	cJSON_ComparePrintNormal(temp1_cJSON, temp2_cJSON, "sym->value");
  }

  cJSON_Delete(object1);
  cJSON_Delete(object2);
}

// print section cJSON object like
// {"section_name":{"0":"address","1":"value"}
void cJSON_PrintSection(struct cJSON *section_object, const char *section_name, move_type type) {
  printf("%s", color[type]);
  if (type == move_right) {
   printf("-");
  } else if (type == move_down) {
	printf("+");
  }
  printf("%s : \n", section_name);
  auto temp_cJSON = cJSON_GetObjectItem(section_object, section_name);
  printf("address : %s\n", cJSON_GetObjectItem(temp_cJSON, "0")->valuestring);

  auto vec_s = split_string(cJSON_GetObjectItem(temp_cJSON, "1")->valuestring, " ");
  int i;
  for (i = 0; i < vec_s.size(); i++) {
    if (i == 4) {
	  i = 0;
	  printf("\n");
	}
    cout << vec_s[i] << " ";
  }
  if (i != 4)
	printf("\n");

  printf("%s", color[move_none]);
}

// compare section cJSON object like
// {"section_name":{"0":"address","1":"value"}
// return 0 when same, 1 when different
int cJSON_ComparePrintSection(const struct cJSON *object1, const struct cJSON *object2, const char *dst_str) {
  int is_diff = 0;
  int is_sname_print = 0;
  const struct cJSON *json1, *json2;
  json1 = cJSON_GetObjectItem(object1, dst_str);
  json2 = cJSON_GetObjectItem(object2, dst_str);

  auto temp1_cJSON = cJSON_GetObjectItem(json1, "0");
  auto temp2_cJSON = cJSON_GetObjectItem(json2, "0");
  auto temp1_str = cJSON_GetStringValue(temp1_cJSON);
  auto temp2_str = cJSON_GetStringValue(temp2_cJSON);
  if (strcmp(temp1_str, temp2_str)) {
    is_diff = is_sname_print = 1;
    printf("%s : \n", dst_str);
    printf("address : \n");
	printf("%s-%s\n%s",
		color[move_right], temp1_str, color[move_none]);
	printf("%s+%s\n%s",
		color[move_down], temp2_str, color[move_none]);
  }

  temp1_cJSON = cJSON_GetObjectItem(json1, "1");
  temp2_cJSON = cJSON_GetObjectItem(json2, "1");
  temp1_str = cJSON_GetStringValue(temp1_cJSON);
  temp2_str = cJSON_GetStringValue(temp2_cJSON);
  if (strcmp(temp1_str, temp2_str)) {
    if (!is_sname_print) {
      is_sname_print = 1;
	  printf("%s : \n", dst_str);
    }
	printf("value : \n");
    // myers' diff
    myers_diff(split_string(temp1_str, " "), split_string(temp2_str, " "));
  }
  return is_diff;
}

// compare option x(improved) then output
// show all section headers
void compare_option_x_i(const char *filename1, const char *filename2) {
  struct cJSON *object1 = cJSON_ParseFilename(filename1);
  struct cJSON *object2 = cJSON_ParseFilename(filename2);

  printf("<option x(improved)> : \n");

  // compare Hex dump of section
  struct cJSON *temp1_array_cJSON, *temp2_array_cJSON;
  temp1_array_cJSON = cJSON_GetObjectItem(object1, "Hex dump of section");
  temp2_array_cJSON = cJSON_GetObjectItem(object2, "Hex dump of section");

  printf("Hex dump of section : \n");

  int array1_size = cJSON_GetArraySize(temp1_array_cJSON);
  int array2_size = cJSON_GetArraySize(temp2_array_cJSON);

  struct cJSON *temp1_cJSON, *temp2_cJSON;
  const char *section_name;
  // the same string(const char*) may have different address
  // so the key must be std::string
  map<string, struct cJSON *> s_map;

  // create a map of sections
  for (int i = 0; i < array1_size; ++i) {
	temp1_cJSON = cJSON_GetArrayItem(temp1_array_cJSON, i);
	section_name = temp1_cJSON->child->string;
	s_map[section_name] = temp1_cJSON;
  }

  // compare and update related variables
  for (int i = 0; i < array2_size; ++i) {
	temp2_cJSON = cJSON_GetArrayItem(temp2_array_cJSON, i);
	section_name = temp2_cJSON->child->string;
	if (s_map.find(section_name) != s_map.end()) {
	  // there are same sections in two file
	  // compare them
	  int is_diff = cJSON_ComparePrintSection(s_map[section_name], temp2_cJSON, section_name);
	  // after comparison, erase element
	  if (is_diff)
	    diff_item_num++;
	  else
	    same_item_num++;
	  s_map.erase(section_name);
	} else {
	  // otherwise output individually
	  char *temp_str;
	  cJSON_PrintSection(temp2_cJSON, section_name, move_down);
	  added_item_num++;
	}
  }
  // updating deleted_item_num must be here
  deleted_item_num += s_map.size();
  for (auto s : s_map) {
	cJSON_PrintSection(s.second, s.first.c_str(), move_right);
//	printf("%s-%s\n%s",
//		   color[move_right], cJSON_PrintUnformatted(s.second), color[move_none]);
  }

  cJSON_Delete(object1);
  cJSON_Delete(object2);
}

int main(int argc, char *argv[]) {
//  if (argc != completed_option_nums * 2 + 1) {
//	printf("Usage : %s <filename-h-1> <filename-h-2> "
//		   "<filename-S-1> <filename-S-2> "
//		   "<filename-l-1> <filename-l-2> "
//		   "<filename-r-1> <filename-r-2> "
//           "<filename-x-i-1> <filename-x-i-2> ", argv[0]);
//	return -1;
//  }

  compare_option_h("h1.json", "h2.json");
  compare_option_S("S1.json", "S2.json");
  compare_option_l("l1.json", "l2.json");
  compare_option_r("r1.json", "r2.json");
  compare_option_x_i("x1.json", "x2.json");

//  compare_option_h(argv[1], argv[2]);
//  compare_option_S(argv[3], argv[4]);
//  compare_option_l(argv[5], argv[6]);
//  compare_option_r(argv[7], argv[8]);
//  compare_option_x_i(argv[9], argv[10]);

  printf("different items number : %d\n", diff_item_num);
  printf("same items number : %d\n", same_item_num);
  printf("added items number : %d\n", added_item_num);
  printf("deleted items number : %d\n", deleted_item_num);

  return 0;
}

