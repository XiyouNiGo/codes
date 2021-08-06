#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/capability.h>

void print_caps() {
  cap_t caps = cap_get_proc();
  ssize_t y = 0;
  printf("The process %d was give capabilities %s\n", (int)getpid(),
         cap_to_text(caps, &y));
  cap_free(caps);
}

int main(int argc, char **argv) {
  cap_t caps = cap_init();

  unsigned num_caps = 5;
  cap_value_t capList[5] = {CAP_NET_RAW, CAP_NET_BIND_SERVICE, CAP_SETUID,
                            CAP_SETGID, CAP_SETPCAP};
  cap_set_flag(caps, CAP_EFFECTIVE, num_caps, capList, CAP_SET);
  cap_set_flag(caps, CAP_INHERITABLE, num_caps, capList, CAP_SET);
  cap_set_flag(caps, CAP_PERMITTED, num_caps, capList, CAP_SET);

  if (cap_set_proc(caps)) {
    perror("capset()");
    return EXIT_FAILURE;
  }
  print_caps();

  printf("dropping caps\n");
  cap_clear(caps);

  if (cap_set_proc(caps)) {
    perror("capset()");
    return EXIT_FAILURE;
  }
  print_caps();

  cap_free(caps);
  return EXIT_SUCCESS;
}