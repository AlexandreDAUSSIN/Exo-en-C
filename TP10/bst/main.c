#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "addr.h"
#include "opstruct.h"
#include "bst.h"

#define VALUE_MIN -9999
#define VALUE_MAX 9999

ADDR(value, VALUE_MIN, VALUE_MAX)

#define VALUE_LITT "X"

#define STR(s)  #s
#define XSTR(s) STR(s)

enum {
  OP_ADD, OP_REMOVE,
  OP_NUMBER, OP_PRESENCE, OP_RANK, OP_SIZE, OP_GRAPHIC,
  OP_VERBOSE,
  OP_HELP, OP_QUIT,
};

opstruct oparray[] = {
  [OP_ADD] = {
    .op = '+',
    .arity = BINARY,
    .help = "add " VALUE_LITT " to the bst",
  },
  [OP_REMOVE] = {
    .op = '-',
    .arity = BINARY,
    .help = "remove " VALUE_LITT " from the bst",
  },
  [OP_NUMBER] = {
    .op = 'n',
    .arity = BINARY,
    .help = "display the number of " VALUE_LITT " in the bst",
  },
  [OP_PRESENCE] = {
    .op = 'p',
    .arity = BINARY,
    .help = "display if " VALUE_LITT " is in the bst or not",
  },
  [OP_RANK] = {
    .op = 'r',
    .arity = BINARY,
    .help = "display the rank of " VALUE_LITT " in the bst",
  },
  [OP_SIZE] = {
    .op = 's',
    .arity = UNARY,
    .help = "display the size of the the bst",
  },
  [OP_GRAPHIC] = {
    .op = 'g',
    .arity = UNARY,
    .help = "display a graphic representation of the bst obtained by a"
        " right-left infix depth-first traversal displayed from top to bottom."
        " Each non empty subtree is displayed with"
        " its value and its size",
  },
  [OP_VERBOSE] = {
    .op = 'v',
    .arity = UNARY,
    .help = "verbose switch. When on, each successful add or remove is followed"
        " by a graphic representation of the bst. The switch is off initially",
  },
  [OP_HELP] = {
    .op = 'h',
    .arity = UNARY,
    .help = "display this help",
  },
  [OP_QUIT] = {
    .op = 'q',
    .arity = UNARY,
    .help = "quit",
  },
};

const char *notes[] = {
  "Values " VALUE_LITT " are integers"
  " from " XSTR(VALUE_MIN) " to " XSTR(VALUE_MAX) ".",
  //"When " VALUE_LITT " is not in the bst, the number and the rank displayed"
  //" are those " VALUE_LITT " would have if added to the bst.",
  NULL
};

#define PRINT_MSG(format, ...)  \
  printf("--- " format "\n", __VA_ARGS__)

#define PRINT__STDERR(class, format, ...) \
  fprintf(stderr, "*** " class ": " format "\n", __VA_ARGS__)

#define PRINT_ERR(format, ...)  PRINT__STDERR("Error", format, __VA_ARGS__)
#define PRINT_WRN(format, ...)  PRINT__STDERR("Warning", format, __VA_ARGS__)

#define OPT__SHORT  "-"
#define OPT__LONG   "--"
#define OPT_HELP_L  OPT__LONG "help"

#define NMEMB(a) (sizeof(a) / sizeof *(a))

int main(int argc, char *argv[]) {
  for (int k = 1; k < argc; ++k) {
    char *a = argv[k];
    if (strcmp(a, OPT__SHORT) == 0 || strcmp(a, OPT__LONG) == 0) {
      ++k;
    } else if (strlen(a) > strlen(OPT__LONG)
        && strncmp(a, OPT_HELP_L, strlen(a)) == 0) {
      printf("Usage: %s\n", argv[0]);
      printf("Binary search tree on integers game.\n");
      return EXIT_SUCCESS;
    }
  }
  if (argc != 1) {
    fprintf(stderr, "Illegal number of parameters or unrecognized option.\n");
    fprintf(stderr, "Try '%s %s'.\n", argv[0], OPT_HELP_L);
    return EXIT_FAILURE;
  }
  bst *t = bst_empty(value_addr_compar);
  if (t == NULL) {
    goto error_capacity;
  }
  int error = 0;
  int graphic = 0;
  int verbose = 0;
  int c = '\n';
  while (1) {
    if (error) {
      while ((c = getchar()) != EOF && c != '\n') {
      }
      error = 0;
    }
    if (graphic) {
      printf("\n");
      bst_repr_graphic(t, value_addr_put);
      printf("\n");
      graphic = 0;
    }
    if (c == '\n') {
      printf("> ");
    }
    c = getchar();
    if (c == EOF) {
      goto error_interrupt;
    } else if (isspace(c)) {
      continue;
    }
    void *xptr = NULL;
    size_t k = (size_t) opstruct_search(c, oparray, NMEMB(oparray));
    if (opstruct_arity(oparray, NMEMB(oparray), k) == BINARY) {
      int r = value_addr_get(&xptr);
      if (r == EOF) {
        goto error_interrupt;
      }
      if (r == 0) {
        PRINT_WRN("Illegal value for command '%c'", c);
        error = 1;
        continue;
      }
    }
    long long int x = value_addr_value(xptr);
    switch (k) {
      case OP_ADD:
        PRINT_MSG("Add '%lld' to the bst", x);
        if (bst_search(t, xptr) != NULL) {
        PRINT_WRN("'%lld' already in the bst", x);
        } else {
        if (bst_add_endofpath(t, xptr) == NULL) {
        goto error_capacity;
        }
        graphic = verbose;
        }
        break;
      case OP_REMOVE:
        PRINT_MSG("Remove '%lld' to the bst", x);
        //if (bst_remove_climbup_left(t, xptr) == NULL) {
        //PRINT_WRN("'%lld' not in the bst", x);
        //} else {
        //graphic = verbose;
        //}
        break;
      case OP_NUMBER:
        //PRINT_MSG("Number of '%lld' in the bst = %zu", x,
        //bst_number(t, xptr));
        break;
      case OP_PRESENCE:
        PRINT_MSG("Presence of '%lld' in the bst = %s", x,
        bst_search(t, xptr) == NULL ? "false" : "true");
        break;
      case OP_RANK:
        //PRINT_MSG("Rank of '%lld' in the bst = %zu", x,
        //bst_rank(t, xptr));
        break;
      case OP_SIZE:
        PRINT_MSG("Size of the bst = %zu", bst_size(t));
        break;
      case OP_GRAPHIC:
        graphic = 1;
        break;
      case OP_VERBOSE:
        verbose = !verbose;
        break;
      case OP_HELP:
        opstruct_print_help(oparray, NMEMB(oparray),
            notes,
            2, 8,
            2, 0,
            VALUE_LITT);
        break;
      case OP_QUIT:
        goto dispose;
        break;
      default:
        if (isgraph(c)) {
          PRINT_WRN("Unknow '%c' operation", c);
        } else {
          PRINT_WRN("Unknow '[%d]' operation", c);
        }
        error = 1;
        break;
    }
  }
  int r = EXIT_SUCCESS;
  goto dispose;
error_capacity:
  PRINT_ERR("%s", "Ask a wizard to enlarge me");
  r = EXIT_FAILURE;
  goto dispose;
error_interrupt:
  PRINT_WRN("%s", "Inelegant quit");
  goto dispose;
dispose:
  bst_dispose(&t);
  PRINT_MSG("%s", "May the BST-force be with you!");
  return r;
}
