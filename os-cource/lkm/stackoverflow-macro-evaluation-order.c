#include <stdio.h>
#define f(a, b) a##b
#define g(a) #a
#define h(a) g(a)

int main() {
  // Macro arguments are completely macro-expanded before they are substituted into a macro body, unless they are stringified or pasted with other tokens. After substitution, the entire macro body, including the substituted arguments, is scanned again for macros to be expanded. The result is that the arguments are scanned twice to expand macro calls in them.
  printf("%s\n", h(f(1, 2)));
  printf("%s\n", g(f(1, 2)));
  return 0;
}