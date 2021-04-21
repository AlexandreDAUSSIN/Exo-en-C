#include <stdlib.h>
#include "lcaps.h"

typedef struct clcaps clcaps;

struct clcaps {
  caps value;
  clcaps *next;
};

struct lcaps {
  clcaps *head;
  clcaps *tail;
};

lcaps *lcaps_empty(void) {
  lcaps *s = malloc(sizeof *s);
  if (s == NULL) {
    return NULL;
  }
  s->head = NULL;
  s->tail = NULL;
  return s;
}

bool lcaps_is_empty(const lcaps *s) {
  return s->head == NULL;
}

size_t lcaps_length(const lcaps *s) {
  if (lcaps_is_empty(s)) {
    return 0;
  }
  clcaps *p = s->head;
  size_t k = 1;
  while (p != NULL) {
    p = p->next;
    k++;
  }
  return k;
}

int lcaps_head_value(const lcaps *s, caps *ptr) {
  if (lcaps_is_empty(s)) {
    return -1;
  }
  *ptr = s->head->value;
  return 0;
}

int lcaps_tail_value(const lcaps *s, caps *ptr) {
  if (lcaps_is_empty(s)) {
    return -1;
  }
  *ptr = s->tail->value;
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

int lcaps_insert_tail(lcaps *s, caps *ptr) {
  clcaps *p = malloc(sizeof *p);
  if (p == NULL) {
    return -1;
  }
  p->value = *ptr;
  clcaps *q = s->tail;
  q->next = p;
  s->tail = p;
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

int lcaps_move_head_tail(lcaps *src, lcaps *dest) {
  if (lcaps_is_empty(src) == true) {
    return -1;
  }
  clcaps *p = src->head;
  src->head = p->next;
  p->next = NULL;
  clcaps *q = dest->tail;
  q->next = p;
  dest->tail = p;
  return 0;
}

int lcaps_move_all_head(lcaps *src, lcaps *dest){
  if (src == dest) {
    return -1;
  }
  clcaps *p = src->head;
  clcaps *q = src->tail;
  q->next = dest->head;
  dest->head = p;
  src->head = NULL;
  return 0;
}

int lcaps_move_all_tail(lcaps *src, lcaps *dest){
  if (src == dest) {
    return -1;
  }
  dest->tail->next = src->head;
  dest->tail = src->tail;
  src->head = NULL;
  src->tail = NULL;
  return 0;
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

