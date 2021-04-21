//  Affiche sur la sortie standard la liste des mots lus sur l'entrée standard
//    dans l'ordre inverse de celui de leur lecture.
//  Limitations :
//  - les mots sont obtenus par lecture sur l'entrée des suites consécutives
//    de longueur maximale mais majorée WORD_LENGTH_MAX de caractères qui ne
//    sont pas de la catégorie isspace ;
//  - toute suite de tels caractères de longueur strictement supérieure à
//    WORD_LENGTH_MAX se retrouve ainsi découpée en plusieurs mots.
//  Attention ! Le point suivant est à retravailler. Le laisser en l'état est
//    contraire aux exigences prônées :
//  - l'avertissement qui figure ligne 32 est une nuisance si le mot lu a
//    exactement la longueur WORD_LENGTH_MAX.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

#define STR(s)  #s
#define XSTR(s) STR(s)

#define WORD_LENGTH_MAX 31

int main(void) {
  stack *s1 = stack_empty();
  stack *s2 = stack_empty();
  if (s1 == NULL) {
    goto error_capacity;
  }
  char w[WORD_LENGTH_MAX + 1];
  while (scanf("%" XSTR(WORD_LENGTH_MAX) "s", w) == 1) {
    if (strlen(w) > WORD_LENGTH_MAX) {
      fprintf(stderr, "*** Warning: Word '%s...' possibly sliced.\n", w);
    }
    char *t = malloc(strlen(w) + 1);
    if (t == NULL) {
      goto error_capacity;
    }
    strcpy(t, w);
    if (stack_push(s1, t) == NULL) {
      free(t);
      goto error_capacity;
    }
  }
  while (!stack_is_empty(s1) || strcmp(t, stack_top(s1)) > 0) {
    stack_move(s2, s1);
  }
  while (!stack_is_empty(s2)) {
    stack_move(s1, s2);
  }
  while (!stack_is_empty(s1)) {
    char *t = (char *) stack_pop(s1);
    printf("%s\n", t);
    free(t);
  }
  int r = EXIT_SUCCESS;
  goto dispose;
error_capacity:
  fprintf(stderr, "*** Error: Ask wizard to enlarge me.\n");
  r = EXIT_FAILURE;
  goto dispose;
dispose:
  stack_dispose(&s);
  return r;
}
