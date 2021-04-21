#ifndef ADDR__H
#define ADDR__H

#include <stdio.h>
#include <errno.h>

#define ADDR(prefix, min, max)                                                 \
  ADDR_INTERFACE(prefix)                                                       \
  ADDR_IMPLEMENTATION(prefix, min, max)

#define ADDR_INTERFACE(prefix)                                                 \
                                                                               \
  int prefix ## _addr_compar(const void *p1, const void *p2);                  \
  int prefix ## _addr_get(void **pp);                                          \
  void prefix ## _addr_put(const void *p);                                     \
  long long int prefix ## _addr_value(const void *p);

#define ADDR_IMPLEMENTATION(prefix, min, max)                                  \
                                                                               \
  char prefix ## __addr[max - min + 1];                                        \
                                                                               \
  int prefix ## _addr_compar(const void *p1, const void *p2) {                 \
    return (p1 > p2) - (p1 < p2);                                              \
  }                                                                            \
                                                                               \
  int prefix ## _addr_get(void **pp) {                                                    \
    long long int x;                                                           \
    errno = 0;                                                                 \
    int r = scanf("%lld", &x);                                                 \
    if (r == EOF) {                                                            \
      return EOF;                                                              \
    }                                                                          \
    if (r == 0 || errno != 0 || !(min <= x && x <= max)) {                     \
      return 0;                                                                \
    }                                                                          \
    *pp = prefix ## __addr + (x - min);                                                \
    return 1;                                                                  \
  }                                                                            \
                                                                               \
  void prefix ## _addr_put(const void *p) {                                               \
    printf("%lld", prefix ## _addr_value(p));                                             \
  }                                                                            \
                                                                               \
  long long int prefix ## _addr_value(const void *p) {                                    \
    return min + ((const char *) p - prefix ## __addr);                                \
  }

#endif
