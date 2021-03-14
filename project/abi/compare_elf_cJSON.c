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
