#include <stdio.h>

#define min(x, y)                  \
  ({                               \
    typeof(x) _min1 = (x);         \
    typeof(y) _min2 = (y);         \
    (void)(&_min1 == &_min2);      \
    _min1 < _min2 ? _min1 : _min2; \
  })

int main(int argc, char *argv[]) {
  int _min1 = 0, _min2 = 1;
  printf("min(_min1, _min2) is %d\n", min(_min1, _min2));
  return 0;
}

// After pretreatment
// int main(int argc, char *argv[]) {
//   int _min1 = 0, _min2 = 1;
//   printf("min(_min1, _min2) is %d\n", ({
//            typeof(_min1) _min1 = (_min1);
//            typeof(_min2) _min2 = (_min2);
//            (void)(&_min1 == &_min2);
//            _min1 < _min2 ? _min1 : _min2;
//          }));
//   printf("After pretreatment: _min1 is %d, _min2 is %d\n", _min1, _min2);
// }