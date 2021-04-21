#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rank.h"

#define TRIAL(base, type, compar, format)                                      \
  {                                                                            \
    size_t nmemb = sizeof(base) / sizeof(*(base));                             \
    for (size_t k = 0; k < nmemb; ++k) {                                       \
      printf(format "[%zu] ", base[k], k);                                     \
    }                                                                          \
    printf("\n");                                                              \
    void **r = rank(base, nmemb, sizeof(type),                                 \
            (int (*)(const void *, const void *))compar);                      \
    if (r == NULL) {                                                           \
      fprintf(stderr, "*** Error: Capacity exceeded.\n");                      \
    } else {                                                                   \
      for (size_t k = 0; k < nmemb; ++k) {                                     \
        printf(format "[%zu] ", *((type *) r[k]), (type *) r[k] - base);       \
      }                                                                        \
      printf("\n");                                                            \
      free(r);                                                                 \
    }                                                                          \
  }

static int int_compar(const int *ptr1, const int *ptr2);
static int strptr_compar(const char **strptr1, const char **strptr2);

int main(void) {
  {
    int a[] = {
      3, 5, 7, 1, 2, 0, 9, 8, 4, 6, 4, 2, 7, 5, 4,
    };
    TRIAL(a, int, int_compar, "%d");
  }
  {
    typedef char str2[2];
    str2 a[] = {
      "R", "E", "C", "U", "P", "E", "R", "E", "R", "O", "N", "T",
    };
    TRIAL(a, str2, strcmp, "%s");
  }
  {
    const char *a[] = {
      "R", "E", "C", "U", "P", "E", "R", "E", "R", "O", "N", "T",
    };
    TRIAL(a, const char *, strptr_compar, "%s");
  }
  return EXIT_SUCCESS;
}

int int_compar(const int *ptr1, const int *ptr2) {
  return (*ptr1 > *ptr2) - (*ptr1 < *ptr2);
}

int strptr_compar(const char **strptr1, const char **strptr2) {
  return strcmp(*strptr1, *strptr2);
}
