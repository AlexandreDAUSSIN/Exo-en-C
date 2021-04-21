#include <stdlib.h>
#include "lcaps.h"

typedef struct clcaps clcaps;

struct clcaps {
  caps value;
  clcaps *next;
};

struct lcaps {
  clcaps *head;
};

lcaps *lcaps_empty(void) {
  lcaps *s = malloc(sizeof *s);
  if (s == NULL) {
    return NULL;
  }
  s->head = NULL;
  return s;
}

bool lcaps_is_empty(const lcaps *s) {
  return s->head == NULL;
}

int lcaps_head_value(const lcaps *s, caps *ptr) {
  if (lcaps_is_empty(s)) {
    return -1;
  }
  *ptr = s->head->value;
  return 0;
}

int lcaps_insert_head(lcaps *s, caps *ptr) {
  clcaps *p = malloc(sizeof *p);
  if (p == NULL) {
    return -1;
  }
  p->value = *ptr;
  p->next = s->head;
  s->head = p;
  return 0;
}

void lcaps_dispose(lcaps **sptr) {
  if (*sptr == NULL) {
    return;
  }
  clcaps *p = (*sptr)->head;
  while (p != NULL) {
    clcaps *t = p;
    p = p->next;
    free(t);
  }
  free(*sptr);
  *sptr = NULL;
}

int lcaps_fput(const lcaps *s, FILE *stream) {
  const clcaps *p = s->head;
  while (p != NULL) {
    if (p != s->head) {
      fputc(' ', stream);
    }
    caps_fput(&p->value, stream);
    p = p->next;
  }
  fputc('\n', stream);
  return 0;
}

int lcaps_move_head_head(lcaps *src, lcaps *dest) {
  if (lcaps_is_empty(src) == true) {
    return -1;
  }
  clcaps *p = src->head;
  src->head = p->next;
  p->next = dest->head;
  dest->head = p;
  return 0;
}
