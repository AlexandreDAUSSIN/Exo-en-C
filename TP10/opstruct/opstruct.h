#ifndef OPSTRUCT__H
#define OPSTRUCT__H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int op;
  enum {
    UNARY, BINARY
  } arity;
  const char *help;
} opstruct;

#ifdef OPSTRUCT_CHECK

extern void opstruct_check(const opstruct *oparray, size_t nelem);

#endif

extern size_t opstruct_search(int c, const opstruct *oparray, size_t nelem);

extern int opstruct_arity(const opstruct *oparray, size_t nelem, size_t k);

extern void opstruct_print_help(const opstruct *oparray, size_t nelem,
    const char *notes[],
    int tab1, int tab2,
    int spaces_before_tab2, int spaces_after_tab2,
    const char *valuelabel);

#endif
