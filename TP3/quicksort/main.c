#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#ifdef QSORT

void (*quicksort)(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *)) = qsort;

#define QUICKSORT_LABEL "GCC qsort"

#else

#include "quicksort.h"

#define QUICKSORT_LABEL "a homemade quicksort"

#endif

#define LENGTH  25

int int_compar(const int *p1, const int *p2);

//  stop : lit des caractères sur l'entrée standard jusqu'à détecter la fin de
//    l'entrée ou obtenir 'q', 'Q' ou '\n'. Renvoie zéro si '\n' est obtenu, une
//    valeur non nulle sinon
int stop(void);

int main(void) {
  printf("--- Trials on " QUICKSORT_LABEL "\n"
      "--- Type ctrl+d or enter 'q' or 'Q' to exit\n\n");
  srand(0);
  while (1) {
    int a[LENGTH];
    for (size_t k = 0; k < sizeof a / sizeof *a; ++k) {
      a[k] = rand() % 100;
    }
    for (size_t k = 0; k < sizeof a / sizeof *a; ++k) {
      printf("%3d", a[k]);
    }
    printf("\n");
    quicksort(a, sizeof a / sizeof *a, sizeof *a,
        (int (*)(const void *, const void *))int_compar);
    for (size_t k = 0; k < sizeof a / sizeof *a; ++k) {
      printf("%3d", a[k]);
    }
    printf("\n> ");
    if (stop()) {
      printf("\n");
      return EXIT_SUCCESS;
    }
  }
}

int int_compar(const int *p1, const int *p2) {
  return (*p1 > *p2) - (*p1 < *p2);
}

int stop(void) {
  while (1) {
    int c = getchar();
    if (c == EOF || toupper(c) == 'Q') {
      return 1;
    }
    if (c == '\n') {
      return 0;
    }
  }
}
