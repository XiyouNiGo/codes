#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wordexp.h>

int expand_and_execute(const char *program, const char **options) {
  wordexp_t result;
  pid_t pid;
  int status, i;

  /* Expand the string for the program to run.  */
  switch (wordexp(program, &result, 0)) {
    case 0: /* Successful.  */
      break;
    case WRDE_NOSPACE:
      /* If the error was WRDE_NOSPACE,
         then perhaps part of the result was allocated.  */
      wordfree(&result);
    default: /* Some other error.  */
      printf("program %s wordexp failed", program);
      return -1;
  }

  /* Expand the strings specified for the arguments.  */
  for (i = 0; options[i] != NULL; i++) {
    if (wordexp(options[i], &result, WRDE_APPEND)) {
      wordfree(&result);
      printf("options %s wordexp failed", options[i]);
      return -1;
    }
  }

  pid = fork();
  if (pid == 0) {
    /* This is the child process.  Execute the command. */
    for (i = 0; result.we_wordv[i] != NULL; i++) {
      printf("%s\n", result.we_wordv[i]);
    }
    execv(result.we_wordv[0], result.we_wordv);
    exit(EXIT_FAILURE);
  } else if (pid < 0)
    /* The fork failed.  Report failure.  */
    status = -1;
  else
    /* This is the parent process.  Wait for the child to complete.  */
    if (waitpid(pid, &status, 0) != pid) status = -1;

  wordfree(&result);
  return status;
}

int main() {
  const char *options[] = {"$PATH", NULL};
  if (expand_and_execute("echo", options) != 0) {
    printf("execute failed\n");
  }
}