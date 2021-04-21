#define LOW   1
#define HIGH  2

#ifndef NATMODEL
#define NATMODEL LOW
#endif

//------------------------------------------------------------------------------
#if NATMODEL == LOW

#include <stddef.h>
#include "nat.h"

#define MAX 31

char natscale[MAX];

#define NATZERO (natscale + MAX)
#define NATMAX  (natscale + 0)
#define NATERR  NULL

nat zero(void) {
  return NATZERO;
}

nat invalid(void) {
  return NATERR;
}

nat succ(nat x) {
  if (is_invalid(x) || x == NATMAX) {
    return NATERR;
  }
  return (const char *) x - 1;
}

nat pred(nat x) {
  if (is_invalid(x) || x == NATZERO) {
    return NATERR;
  }
  return (const char *) x + 1;
}

bool is_zero(nat x) {
  return x == NATZERO;
}

bool is_invalid(nat x) {
  return x == NATERR;
}

//------------------------------------------------------------------------------
#elif NATMODEL == HIGH

#include <stdlib.h>
#include "nat.h"

typedef struct natitem natitem;

struct natitem {
  natitem *prev;
  natitem *next;
};

natitem natbase;

natitem *natmax = &natbase;

#define NATERR  NULL

nat zero(void) {
  return &natbase;
}

nat invalid(void) {
  return NATERR;
}

nat succ(nat x) {
  if (is_invalid(x)) {
    return NATERR;
  }
  if (x != natmax) {
    return ((natitem *) x)->next;
  }
  natitem *p = malloc(sizeof *p);
  if (p == NULL) {
    return NATERR;
  }
  p->prev = natmax;
  natmax->next = p;
  natmax = p;
  return p;
}

nat pred(nat x) {
  if (is_invalid(x) || is_zero(x)) {
    return NATERR;
  }
  return ((natitem *) x)->prev;
}

bool is_zero(nat x) {
  return x == &natbase;
}

bool is_invalid(nat x) {
  return x == NATERR;
}

//------------------------------------------------------------------------------
#else
#error illegal value of NATMODEL
#endif
