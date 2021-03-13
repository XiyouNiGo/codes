#include <stdio.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define my_err(format)      { \
                                    fprintf(stderr, "(File:%s, Line:%d) ", __FILE__, __LINE__); \
                                    perror(format); \
                                    exit(1); \
                            } \

const int completed_option_nums = 2;
const double double_min_interval = 1e-6;

long int diff_item_num = 0, same_item_num = 0;

//parse from a filename to a json object
struct cJSON *cJSON_Parse_Filename(const char *filename) {
  int fd = open(filename, O_RDONLY);
  if (fd == -1)
  	my_err("open error");

  struct stat file_stat;
  if (fstat(fd, &file_stat) == -1)
    my_err("fstat error");
  __off_t size = file_stat.st_size;

  char read_buf[size + 1];
  read(fd, (void*)read_buf, size);
  read_buf[size] = '\0';

  if (close(fd) == -1)
  	my_err("close error");
  return cJSON_Parse(read_buf);
}

//compare cJSON String or Number Object and print
void cJSON_Compare_String_Number(struct cJSON *object1, struct cJSON *object2, const char *dst_str) {
  const struct cJSON *json1, *json2;
  json1 = cJSON_GetObjectItem(object1, dst_str);
  json2 = cJSON_GetObjectItem(object2, dst_str);

  if (cJSON_IsString(json1) && cJSON_IsString(json2)) {
	const char *str1, *str2;
	str1 = cJSON_GetStringValue(json1);
	str2 = cJSON_GetStringValue(json2);

	if (strcmp(str1, str2) != 0) {
	  diff_item_num++;
	  printf("%s : %s %s\n", dst_str, str1, str2);
	} else {
	  same_item_num++;
	  printf("%s : %s %s\n", dst_str, str1, str2);
	}
  } else if (cJSON_IsNumber(json1) && cJSON_IsNumber(json2)) {
    double d1, d2;
    d1 = cJSON_GetNumberValue(json1);
    d2 = cJSON_GetNumberValue(json2);
    printf("**%d**", d2);

    if (d1 - d2 > double_min_interval) {
      diff_item_num++;
	  printf("%s : %d %d\n", dst_str, d1, d2);
	} else {
      same_item_num++;
	  printf("%s : %d %d\n", dst_str, d1, d2);
	}
  } else {
    printf("%s\n", dst_str);
    my_err("cJSON_Compare_String_Number error");
  }
}

//compare option h then output
void compare_option_h(const char *filename1, const char *filename2) {
  struct cJSON *object1 = cJSON_Parse_Filename(filename1);
  struct cJSON *object2 = cJSON_Parse_Filename(filename2);
  struct cJSON *temp1_cJSON, *temp2_cJSON;
  temp1_cJSON = cJSON_GetObjectItem(object1, "ELF Header");
  temp2_cJSON = cJSON_GetObjectItem(object2, "ELF Header");

  printf("option h:\n");

  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "OS/ABI");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "ABI Version");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Type");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Machine");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Version");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Entry point address");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Start of program headers");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Start of section headers");

  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Size of this header");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Size of program headers");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Number of program headers");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Size of section headers");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Number of section headers");
  cJSON_Compare_String_Number(temp1_cJSON, temp2_cJSON, "Section header string table index");

  cJSON_Delete(temp1_cJSON);
  cJSON_Delete(temp2_cJSON);
  cJSON_Delete(object1);
  cJSON_Delete(object2);
}

//compare option S then output
void compare_option_S(const char *filename) {
  struct cJSON *sub_json_object = cJSON_Parse_Filename(filename);
  printf("option S:\n");
  cJSON_Delete(sub_json_object);
}

//compare option l then output
void compare_option_l(const char *filename) {
  struct cJSON *sub_json_object = cJSON_Parse_Filename(filename);
  printf("%s", cJSON_Print(sub_json_object));	//free
  printf("option l:\n");

  cJSON_Delete(sub_json_object);
}

int main(int argc, char *argv[]) {
//  if (argc != completed_option_nums * 2 + 1) {
//	printf("Usage : %s <filename-h-1> <filename-h-2> "
//		   "<filename-S-1> <filename-S-2> "
//           "<filename-l-1> <filename-l-2> ", argv[0]);
//	return -1;
//  }

  compare_option_h("/home/nigo/桌面/h1.json", "/home/nigo/桌面/h2.json");
//  compare_option_S("/home/nigo/桌面/h.json");
//  compare_option_l("/home/nigo/桌面/h.json");

  printf("different items number : %d\n", diff_item_num);
  printf("same items number : %d\n", same_item_num);
  return 0;
}
