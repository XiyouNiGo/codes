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

using namespace std;

#define my_err(format)      { \
                                    fprintf(stderr, "(File:%s, Line:%d) ", __FILE__, __LINE__); \
                                    perror(format); \
                                    exit(1); \
                            } \

enum MoveType {
  MoveType_None,
  MoveType_Down,
  MoveType_Right,
  MoveType_Diagonal
};

struct Point {
  Point(int x, int y) {
	this->x = x;
	this->y = y;
  }

  bool operator==(const Point &pt) const {
	return this->x == pt.x && this->y == pt.y;
  }

  bool operator!=(const Point &pt) const {
	return this->x != pt.x || this->y != pt.y;
  }

  MoveType operator>(const Point &pt2) {
	if (this->x == pt2.x && this->y + 1 == pt2.y) {
	  return MoveType_Down;
	} else if (this->y == pt2.y && this->x + 1 == pt2.x) {
	  return MoveType_Right;
	} else if (this->x + 1 == pt2.x && this->y + 1 == pt2.y) {
	  return MoveType_Diagonal;
	}

	return MoveType_None;
  }

  int x = 0;
  int y = 0;
};

const int completed_option_nums = 2;
const double double_min_interval = 1e-6;

long int diff_item_num = 0, same_item_num = 0,
	added_item_num = 0, deleted_item_num = 0;

map<MoveType, const char*> color = {
	{MoveType_Down, "\033[32m"},
	{MoveType_Right, "\033[31m"},
	{MoveType_Diagonal, "\033[39m"},
	{MoveType_None, "\033[0m"}
};

// myers' diff algorithm
template<typename T1, typename T2>
void myers_diff(const T1 &lhs, const T2 &rhs) {
  int N = lhs.size();
  int M = rhs.size();
  vector<map<int, int>> res_v;
  map<int, int> v;
  v[1] = 0;
  bool go_ahead = true;
  for (int d = 0; d <= N + M && go_ahead; d++) {
	for (int k = -d; k <= d; k = k + 2) {
	  bool down = (k == -d || (k != d && v[k - 1] < v[k + 1]));
	  int kPrev = down ? k + 1 : k - 1;
	  int xStart = v[kPrev];
	  int yStart = xStart - kPrev;
	  int xTmp = down ? xStart : xStart + 1;
	  int yTmp = xTmp - k;
	  int xEnd = xTmp;
	  int yEnd = yTmp;
	  while (xEnd < N && yEnd < M && lhs[xEnd] == rhs[yEnd]) {
		++xEnd;
		++yEnd;
	  }
	  v[k] = xEnd;

	  if (xEnd >= N && yEnd >= M) {
		go_ahead = false;
		break;
	  }
	}
	res_v.push_back(v);
  }

  vector<Point> path;
  Point pt(lhs.size(), rhs.size());
  path.push_back(pt);
  for (int d = res_v.size() - 1; pt.x > 0 || pt.y > 0; --d) {
	auto X = res_v[d];
	int k = pt.x - pt.y;

	int xEnd = X[k];
	int yEnd = pt.x - k;
	while (xEnd > 0 && yEnd > 0 && xEnd <= N && yEnd <= M && lhs[xEnd - 1] == rhs[yEnd - 1]) {
	  --xEnd;
	  --yEnd;
	  path.push_back(Point(xEnd, yEnd));
	}
	bool down = (k == -d || (k != d && X[k - 1] < X[k + 1]));
	int kPrev = down ? k + 1 : k - 1;
	int xStart = X[kPrev];
	int yStart = xStart - kPrev;
	path.push_back(Point(xStart, yStart));
	pt.x = xStart;
	pt.y = yStart;
  }

  path.pop_back();

  if (path.size() >= 2) {
	int size = path.size();
	for (int i = size - 2; i >= 0; --i) {
	  Point prev_point = path[i + 1];
	  MoveType type = prev_point > (path[i]);
	  switch (type) {
		case MoveType_Right: {
		  cout << color[MoveType_Right] << "-" << lhs[prev_point.x] << endl;
		  break;
		}
		case MoveType_Down: {
		  cout << color[MoveType_Down] << "+" << rhs[prev_point.y] << endl;
		  break;
		}
		case MoveType_Diagonal: {
		  cout << color[MoveType_Diagonal] << "=" << lhs[prev_point.x] << endl;
		  break;
		}
	  }
	}
  }
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
	  // number Key won't be printed
	  // atoi return 0 when error happens or string is "0"
//	  if ((atoi(dst_str) != 0) )
	  if (!(strlen(dst_str) == 1 && isdigit(*dst_str)))
		printf("%s : \n", dst_str);
	  cout << color[MoveType_Right] << "-" << str1 << endl << color[MoveType_None];
	  cout << color[MoveType_Down] << "+" << str2 << endl << color[MoveType_None];
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
	  if (!(strlen(dst_str) == 1 && isdigit(*dst_str)))
		printf("%s : \n", dst_str);
	  printf("%s-%.0lf\n%s+%.0lf\n%s",
		  color[MoveType_Right], d1, color[MoveType_Down], d2, color[MoveType_None]);
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
	  (*nk_buf)++;
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
  map<const char *, struct cJSON *> s_map;

  // create a map of sections
  for (int i = 0; i < array1_size; ++i) {
	temp1_cJSON = cJSON_GetArrayItem(temp1_array_cJSON, i);
	section_name = cJSON_GetStringValue(temp1_cJSON);
	s_map[section_name] = temp1_cJSON;
    printf("arr1:%s %s\n", temp1_cJSON->valuestring, cJSON_PrintUnformatted(temp1_cJSON));
  }

  // compare and update related variables
  for (int i = 0; i < array2_size; ++i) {
	temp2_cJSON = cJSON_GetArrayItem(temp2_array_cJSON, i);
	section_name = cJSON_GetStringValue(temp2_cJSON);
    printf("arr2:%s\n", section_name);
	if (s_map.find(section_name) != s_map.end()) {
	  // there are same sections in two file
	  // compare them
	  cJSON_ComparePrintNormal(s_map[section_name], temp2_cJSON, section_name);
	  // after comparison, erase element
	  s_map.erase(section_name);
	} else {
	  // otherwise output individually
	  char *temp_str;
	  printf("%s+%s\n%s",
		  color[MoveType_Down], cJSON_PrintUnformatted(temp2_cJSON), color[MoveType_None]);
	  added_item_num++;
	}

	s_map[cJSON_GetStringValue(temp2_array_cJSON)] = temp1_cJSON;
  }
  // updating deleted_item_num must be here
  deleted_item_num += s_map.size();
  for (auto s : s_map) {
	printf("%s-%s\n%s",
		   color[MoveType_Right], cJSON_PrintUnformatted(s.second), color[MoveType_None]);
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

