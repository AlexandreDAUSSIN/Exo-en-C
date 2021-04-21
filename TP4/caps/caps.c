#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "caps.h"

#define CAPS  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NCAPS strlen(CAPS)

#define RANDCAP() *(CAPS + (size_t) ((double) NCAPS * rand() / RAND_MAX))

int caps_fget(caps *ptr, FILE *stream) {
  int c;
  while ((c = fgetc(stream)) != EOF && isspace(c)) {
  }
  if (c == EOF || ungetc(c, stream) == EOF) {
    return EOF;
  }
  caps s;
  size_t k = 0;
  while (k < CAPS_LEN
      && (c = fgetc(stream)) != EOF
      && memchr(CAPS, c, NCAPS) != NULL) {
    s.reserved__usage[k] = (char) c;
    ++k;
  }
  if (k != CAPS_LEN) {
    return 0;
  }
  *ptr = s;
  return 1;
}

int caps_fput(const caps *ptr, FILE *stream) {
  for (size_t k = 0; k < CAPS_LEN; ++k) {
    if (fputc(ptr->reserved__usage[k], stream) == EOF) {
      return EOF;
    }
  }
  return 0;
}

void caps_rand(caps *ptr) {
  for (size_t k = 0; k < CAPS_LEN; ++k) {
    ptr->reserved__usage[k] = RANDCAP();
  }
}

int caps_compar(const caps *ptr1, const caps *ptr2) {
  for (size_t k = 0; k < CAPS_COMPAR_LEN; ++k) {
    int d = ptr1->reserved__usage[k] - ptr2->reserved__usage[k];
    if (d != 0) {
      return d;
    }
  }
  return 0;
}
