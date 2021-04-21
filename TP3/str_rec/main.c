#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "str_rec.h"

#define TRIAL_PTR(fun, text, arg)                                              \
  {                                                                            \
    printf("--- " #fun "\n");                                                  \
    printf("%s\n", text);                                                      \
    char *p = fun(text, arg);                                                  \
    if (p == NULL) {                                                           \
      printf("*");                                                             \
    } else {                                                                   \
      printf("%*c", (int) (p - text + 1), '^');                                \
    }                                                                          \
    printf("%s\n", #arg);                                                      \
  }

#define TRIAL_SIZE(fun, text, arg)                                             \
  {                                                                            \
    printf("--- " #fun "\n");                                                  \
    printf("%s\n", text);                                                      \
    for (size_t n = fun(text, arg); n > 0; --n) {                              \
      printf(".");                                                             \
    }                                                                          \
    printf("%s\n", #arg);                                                      \
  }

int main(void) {
  printf("--- Trials on strings utilities\n"
      "--- Utilities prefixed by 'str_' are homemade\n\n");
  const char *s = "http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf";
  TRIAL_PTR(strchr, s, 'd');
  TRIAL_PTR(strchr, s, 'a');
  TRIAL_PTR(strchr, s, '\0');
  TRIAL_PTR(str_chr, s, 'd');
  TRIAL_PTR(str_chr, s, 'a');
  TRIAL_PTR(str_chr, s, '\0');
  //
  TRIAL_PTR(strrchr, s, 'd');
  TRIAL_PTR(strrchr, s, 'a');
  TRIAL_PTR(strrchr, s, '\0');
  //
  TRIAL_PTR(strpbrk, s, ".:/");
  TRIAL_PTR(strpbrk, s, "0123456789");
  TRIAL_PTR(strpbrk, s, "abiklmquvxyz");
  TRIAL_PTR(str_pbrk, s, ".:/");
  TRIAL_PTR(str_pbrk, s, "0123456789");
  TRIAL_PTR(str_pbrk, s, "abiklmquvxyz");
  //
  TRIAL_SIZE(strspn, s, "abcdefghijklmnopqrstuvwxyz");
  TRIAL_SIZE(strspn, s, ".:/");
  TRIAL_SIZE(str_spn, s, "abcdefghijklmnopqrstuvwxyz");
  TRIAL_SIZE(str_spn, s, ".:/");
  return EXIT_SUCCESS;
}
