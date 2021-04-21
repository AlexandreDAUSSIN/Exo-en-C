#include "opstruct.h"
#include <ctype.h>
#include <sys/ioctl.h>

#ifdef OPSTRUCT_CHECK

void opstruct_check(const opstruct *oparray, size_t nelem) {
  for (size_t k = nelem; k > 1;) {
    --k;
    if (opstruct_search(oparray[k].op, oparray, k) != (size_t) (-1)) {
      fprintf(stderr, "Internal error: %s: duplicate operator '[%d]'\n",
          __func__, oparray[k].op);
      abort();
    }
    if (!(oparray[k].arity == UNARY || oparray[k].arity == BINARY)) {
      fprintf(stderr, "Internal error: %s: invalid arity value '%d'\n",
          __func__, oparray[k].arity);
      abort();
    }
  }
}

#endif

size_t opstruct_search(int c, const opstruct *oparray, size_t nelem) {
  for (size_t k = nelem; k != 0;) {
    --k;
    if (oparray[k].op == c) {
      return k;
    }
  }
  return (size_t) (-1);
}

int opstruct_arity(const opstruct *oparray, size_t nelem, size_t k) {
  if (k >= nelem) {
    return -1;
  }
  return oparray[k].arity;
}

#define PUTC(x, c)        { putchar(c); ++x; }
#define ADVANCE_TO(x, n)  { while (x < n) { PUTC(x, ' '); } }
#define NEW_LINE(x)       { putchar('\n'); x = 0; }

static void optstruct__print_line(const char *s, int x, int indent, int width) {
  const char *p = s;
  while (*p != '\0') {
    const char *q = p;
    while (*q != '\0' && !isspace(*q)) {
      ++q;
    }
    if (x + q - p < width) {
      if (x > indent) {
        PUTC(x, ' ');
      }
    } else {
      NEW_LINE(x);
    }
    ADVANCE_TO(x, indent);
    while (p < q) {
      PUTC(x, *p);
      ++p;
    }
    while (isspace(*p)) {
      ++p;
    }
  }
  NEW_LINE(x);
}

void opstruct_print_help(const opstruct *oparray, size_t nelem,
    const char *notes[],
    int tab1, int tab2,
    int spaces_before_tab2, int spaces_after_tab2,
    const char *valuelabel) {
  struct winsize ws;
  if (ioctl(0, TIOCGWINSZ, &ws) == -1) {
    ws.ws_col = 80;
  }
  optstruct__print_line("List of commands:", 0, 0, ws.ws_col);
  for (size_t k = 0; k < nelem; ++k) {
    int x = 0;
    ADVANCE_TO(x, tab1);
    PUTC(x, oparray[k].op);
    PUTC(x, ' ');
    if (oparray[k].arity == BINARY) {
      const char *q = valuelabel;
      while (*q != '\0') {
        PUTC(x, *q);
        ++q;
      }
    }
    if (x > spaces_before_tab2 && x > tab2 - spaces_before_tab2) {
      if (spaces_after_tab2 < spaces_before_tab2) {
        NEW_LINE(x);
      } else {
        ADVANCE_TO(x, tab2 + spaces_after_tab2 - 1);
      }
    }
    const char *p = oparray[k].help;
    optstruct__print_line(p == NULL ? "" : p, x, tab2, ws.ws_col);
  }
  if (notes != NULL) {
    const char **pp = notes;
    while (*pp != NULL) {
      putchar('\n');
      optstruct__print_line(*pp, 0, 0, ws.ws_col);
      ++pp;
    }
  }
}
