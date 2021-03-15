#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include <map>

#define my_err(format)      { \
                                    fprintf(stderr, "(File:%s, Line:%d) ", __FILE__, __LINE__); \
                                    perror(format); \
                                    exit(1); \
                            } \

const int completed_option_nums = 2;
const double double_min_interval = 1e-6;

long int diff_item_num = 0, same_item_num = 0,
		 added_item_num = 0, deleted_item_num = 0;

// parse from a filename to a json object
struct cJSON *cJSON_ParseFilename(const char *filename) {
  int fd = open(filename, O_RDONLY);
  if (fd == -1)
  my_err("open error");

  // obtain file size
  struct stat file_stat;
  if (fstat(fd, &file_stat) == -1)
  my_err("fstat error");
  __off_t size = file_stat.st_size;

  // read file by size
  char read_buf[size + 1];
  read(fd, (void*)read_buf, size);
  read_buf[size] = '\0';

  if (close(fd) == -1)
  my_err("close error");
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
	  if (!(strlen(dst_str) == 1 && isdigit(*dst_str)))
		printf("%s : \n", dst_str);
	  printf("('%s', '%s')\n", str1, str2);
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
	  printf("('%.0lf', '%.0lf')\n", d1, d2);
	} else {
	  same_item_num++;
	}
  } else if (cJSON_IsObject(json1) && cJSON_IsObject(json2)){
	// for cJSON Object like "Version":      {
	//                         "0":    1,
	//                         "1":    "(current)"
	//                 },
	char nk_buf[2] = {'0', '\0'};	// number key buffer (0, 1, ...)
									// INT_MAX is 2147483647
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
  if (array_size != cJSON_GetArraySize(temp2_array_cJSON))
  my_err("cJSON_GetArraySize error");

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
  if (array_size != cJSON_GetArraySize(temp2_array_cJSON))
  my_err("cJSON_GetArraySize error");

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
  if (array_size != cJSON_GetArraySize(temp2_array_cJSON))
  my_err("cJSON_GetArraySize error");

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
  std::map<const char*, struct cJSON*> s_map;

  printf("*%d*", array1_size);
  // create a map of sections
  for (int i = 0; i < array1_size; ++i) {
	temp1_cJSON = cJSON_GetArrayItem(temp1_array_cJSON, i);
	section_name = cJSON_GetStringValue(temp1_cJSON);
	s_map[section_name] = temp1_cJSON;
  }

  // compare and update related variables
  for (int i = 0; i < array2_size; ++i) {
	temp2_cJSON = cJSON_GetArrayItem(temp2_array_cJSON, i);
	section_name = cJSON_GetStringValue(temp2_cJSON);
	if (s_map.find(section_name) != s_map.end()) {
	  // there are same sections in two file
	  // compare them
	  cJSON_ComparePrintNormal(s_map[section_name], temp2_cJSON, section_name);
	  // after comparison, erase element
	  s_map.erase(section_name);
	} else {
	  // otherwise output individually
	  char *temp_str;
	  printf("added : %s\n", cJSON_PrintUnformatted(temp2_cJSON));
	  added_item_num++;
	}

	s_map[cJSON_GetStringValue(temp2_array_cJSON)] = temp1_cJSON;
  }
  // updating deleted_item_num must be here
  deleted_item_num += s_map.size();
  
  cJSON_Delete(object1);
  cJSON_Delete(object2);
}

int main(int argc, char *argv[]) {
//  if (argc != completed_option_nums * 2 + 1) {
//	printf("Usage : %s <filename-h-1> <filename-h-2> "
//		   "<filename-S-1> <filename-S-2> "
//           "<filename-l-1> <filename-l-2> ", argv[0]);
//	return -1;
//  }

//  compare_option_h("/home/nigo/桌面/codes/project/abi/h1.json", "/home/nigo/桌面/codes/project/abi/h2.json");
//  compare_option_S("/home/nigo/桌面/codes/project/abi/S1.json", "/home/nigo/桌面/codes/project/abi/S2.json");
//  compare_option_l("/home/nigo/桌面/codes/project/abi/l1.json", "/home/nigo/桌面/codes/project/abi/l2.json");
//  compare_option_r("/home/nigo/桌面/codes/project/abi/r1.json", "/home/nigo/桌面/codes/project/abi/r2.json");
//  compare_option_x_i("/home/nigo/桌面/codes/project/abi/x1.json", "/home/nigo/桌面/codes/project/abi/x2.json");

  printf("different items number : %d\n", diff_item_num);
  printf("same items number : %d\n", same_item_num);
  printf("added items number : %d\n", added_item_num);
  printf("deleted items number : %d\n", deleted_item_num);

  return 0;
}

