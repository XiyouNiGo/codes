#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#define __min(t1, t2, min1, min2, x, y) \
  ({                                    \
    t1 min1 = (x);                      \
    t2 min2 = (y);                      \
    (void)(&min1 == &min2);             \
    min1 < min2 ? min1 : min2;          \
  })

#define ___PASTE(a, b) a##b
#define __PASTE(a, b) ___PASTE(a, b)

#define __UNIQUE_ID(prefix) __PASTE(__PASTE(__UNIQUE_ID_, prefix), __COUNTER__)

#define min(x, y) \
  __min(typeof(x), typeof(y), __UNIQUE_ID(min1_), __UNIQUE_ID(min2_), x, y)

#define min_t(type, x, y) \
  __min(type, type, __UNIQUE_ID(min1_), __UNIQUE_ID(min2_), x, y)

static int __init lkm_min(void) {
  int smaller = 0, bigger = 1;
  printf("The value of smaller one is %d\n", min(bigger, smaller));
  return 0;
}

static void __exit lk_exit(void) { printk("Moudle lkm_min has exited!\n"); }

module_init(lkm_min);
module_exit(lk_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Get minner one between two numbers");