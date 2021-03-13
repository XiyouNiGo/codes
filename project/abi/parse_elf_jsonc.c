#include <stdio.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "json-c/json.h"

#define my_err(format)      { \
                                    fprintf(stderr, "(File:%s, Line:%d) ", __FILE__, __LINE__); \
                                    perror(format); \
                                    exit(1); \
                            } \


void read_file_header(int fd, struct json_object *elf_json_object) {
  if (lseek(fd, 0, SEEK_SET) == -1)
    my_err("lseek error");
  Elf64_Ehdr file_header;
  if (read(fd, (void*)&file_header, sizeof(file_header)) == -1)
    my_err("read error");

  struct json_object *file_header_json_obeject = json_object_new_object();

  unsigned char magic_string[17] = {0};
  for (int i = 0; i < 16; i++)
    magic_string[i] = file_header.e_ident[i] + '0';
  json_object_object_add(file_header_json_obeject, "Magic", json_object_new_string(magic_string));
  json_object_object_add(file_header_json_obeject, "Type", json_object_new_int64(file_header.e_type));
  json_object_object_add(file_header_json_obeject, "Machine", json_object_new_int64(file_header.e_machine));
  json_object_object_add(file_header_json_obeject, "Version", json_object_new_int64(file_header.e_version));
  json_object_object_add(file_header_json_obeject, "Entry point address", json_object_new_int64(file_header.e_entry));
  json_object_object_add(file_header_json_obeject, "Start of program headers", json_object_new_int64(file_header.e_phoff));
  json_object_object_add(file_header_json_obeject, "Start of section headers", json_object_new_int64(file_header.e_shoff));
  json_object_object_add(file_header_json_obeject, "Flags", json_object_new_int64(file_header.e_flags));
  json_object_object_add(file_header_json_obeject, "Size of this header", json_object_new_int64(file_header.e_ehsize));
  json_object_object_add(file_header_json_obeject, "Size of program headers", json_object_new_int64(file_header.e_phentsize));
  json_object_object_add(file_header_json_obeject, "Number of program headers", json_object_new_int64(file_header.e_phnum));
  json_object_object_add(file_header_json_obeject, "Size of section header", json_object_new_int64(file_header.e_shentsize));
  json_object_object_add(file_header_json_obeject, "Number of section headers", json_object_new_int64(file_header.e_shnum));
  json_object_object_add(file_header_json_obeject, "Section header string table index", json_object_new_int64(file_header.e_shstrndx));

  json_object_object_add(elf_json_object, "File Header", file_header_json_obeject);
}

void read_program_header(int fd, struct json_object *elf_json_object) {
  if (lseek(fd, offsetof(Elf64_Ehdr, e_phoff), SEEK_SET) == -1)
    my_err("lseek error");
  Elf64_Off e_phoff;
  if (read(fd, (void*)&e_phoff, sizeof(e_phoff)) == -1)
  	my_err("read error");

  if (lseek(fd, offsetof(Elf64_Ehdr, e_phnum), SEEK_SET) == -1)
  	my_err("lseek error");
  Elf64_Half e_phnum;
  if (read(fd, (void*)&e_phnum, sizeof(e_phnum)) == -1)
    my_err("read error");

  if (lseek(fd, e_phoff, SEEK_SET) == -1)
  	my_err("lseek error");
  Elf64_Phdr program_headers[e_phnum];
  struct json_object *program_header_json_array = json_object_new_array();
  for (Elf64_Half i = 0; i < e_phnum; i++) {
	if (read(fd, (void *)&(program_headers[i]), sizeof(program_headers[i])) == -1)
		my_err("read error");

	struct json_object *program_header_json_array_i = json_object_new_object();

	json_object_object_add(program_header_json_array_i, "Type", json_object_new_int64(program_headers[i].p_type));
	json_object_object_add(program_header_json_array_i, "Offset", json_object_new_int64(program_headers[i].p_offset));
	json_object_object_add(program_header_json_array_i, "VirtAddr", json_object_new_int64(program_headers[i].p_vaddr));
	json_object_object_add(program_header_json_array_i, "PhysAddr", json_object_new_int64(program_headers[i].p_paddr));
	json_object_object_add(program_header_json_array_i, "FileSiz", json_object_new_int64(program_headers[i].p_filesz));
	json_object_object_add(program_header_json_array_i, "MemSiz", json_object_new_int64(program_headers[i].p_memsz));
	json_object_object_add(program_header_json_array_i, "Flg", json_object_new_int64(program_headers[i].p_flags));
	json_object_object_add(program_header_json_array_i, "Align", json_object_new_int64(program_headers[i].p_align));

	json_object_array_add(program_header_json_array, program_header_json_array_i);
  }
  
  json_object_object_add(elf_json_object, "Program Headers", program_header_json_array);
}

void read_section_header(int fd, struct json_object *elf_json_object) {
  if (lseek(fd, offsetof(Elf64_Ehdr, e_shoff), SEEK_SET) == -1)
  	my_err("lseek error");
  Elf64_Off e_shoff;
  if (read(fd, (void*)&e_shoff, sizeof(e_shoff)) == -1)
  	my_err("read error");
  
  if (lseek(fd, offsetof(Elf64_Ehdr, e_shnum), SEEK_SET) == -1)
  	my_err("lseek error");
  Elf64_Half e_shnum;
  if (read(fd, (void*)&e_shnum, sizeof(e_shnum)) == -1)
  	my_err("read error");

  if (lseek(fd, e_shoff, SEEK_SET) == -1)
  	my_err("lseek error");
  Elf64_Shdr section_headers[e_shnum];
  struct json_object *section_header_json_array = json_object_new_array();
  for (Elf64_Half i = 0; i < e_shnum; i++) {
	if (read(fd, (void *)&(section_headers[i]), sizeof(section_headers[i])) == -1)
	  my_err("read error");

	struct json_object *section_header_json_array_i = json_object_new_object();

	json_object_object_add(section_header_json_array_i, "Name", json_object_new_int64(section_headers[i].sh_name));
	json_object_object_add(section_header_json_array_i, "Type", json_object_new_int64(section_headers[i].sh_type));
	json_object_object_add(section_header_json_array_i, "Addr", json_object_new_int64(section_headers[i].sh_addr));
	json_object_object_add(section_header_json_array_i, "Off", json_object_new_int64(section_headers[i].sh_offset));
	json_object_object_add(section_header_json_array_i, "Size", json_object_new_int64(section_headers[i].sh_size));
	json_object_object_add(section_header_json_array_i, "ES", json_object_new_int64(section_headers[i].sh_entsize));
	json_object_object_add(section_header_json_array_i, "Flg", json_object_new_int64(section_headers[i].sh_flags));
	json_object_object_add(section_header_json_array_i, "Lk", json_object_new_int64(section_headers[i].sh_link));
	json_object_object_add(section_header_json_array_i, "Inf", json_object_new_int64(section_headers[i].sh_info));
	json_object_object_add(section_header_json_array_i, "Al", json_object_new_int64(section_headers[i].sh_addralign));

	json_object_array_add(section_header_json_array, section_header_json_array_i);
  }

  json_object_object_add(elf_json_object, "Program Headers", section_header_json_array);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage : %s <filename>\n", argv[0]);
    return -1;
  }

  int fd = open(argv[1], O_RDONLY);
//  int fd = open("/home/nigo/桌面/try", O_RDONLY);
  if (fd == -1)
    my_err("open error");
  struct json_object *elf_json_object = json_object_new_object();

  read_file_header(fd, elf_json_object);
  read_program_header(fd, elf_json_object);
  read_section_header(fd, elf_json_object);

  printf("%s\n", json_object_to_json_string(elf_json_object));
  json_object_put(elf_json_object);
  if (close(fd) == -1)
    my_err("close error");
  return 0;
}
