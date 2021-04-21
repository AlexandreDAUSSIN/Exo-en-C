//  Affiche sur la sortie standard :
//  - le nombre de mots lus sur l'entrée standard ;
//  - la liste de ces mots, dans l'ordre lexicographique, chaque mot étant
//    précédé de son nombre d'occurrences ;
//  - zéro.
//  Limitations :
//  - les mots sont obtenus par lecture sur l'entrée des suites consécutives
//    de longueur maximale mais majorée WORD_LENGTH_MAX de caractères qui ne
//    sont pas de la catégorie isspace ;
//  - toute suite de tels caractères de longueur strictement supérieure à
//    WORD_LENGTH_MAX se retrouve ainsi découpée en plusieurs mots.
//  Attention ! Le point suivant est à retravailler. Le laisser en l'état est
//    contraire aux exigences prônées :
//  - l'avertissement qui figure ligne 41 est une nuisance si le mot lu a
//    exactement la longueur WORD_LENGTH_MAX.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mset.h"
#include "holdall.h"

#define STR(x)  #x
#define XSTR(x) STR(x)

#define WORD_LENGTH_MAX 31

//  rfree : libère la zone mémoire pointée par ptr et renvoie zéro
static int rfree(void *ptr);

int main(void) {
  mset *ms = mset_empty((int (*)(const void *, const void *))strcmp);
  holdall *ha = holdall_empty();
  if (ms == NULL || ha == NULL) {
    goto error_capacity;
  }
  //
  char w[WORD_LENGTH_MAX + 1];
  while (scanf("%" XSTR(WORD_LENGTH_MAX) "s", w) == 1) {
    if (strlen(w) == WORD_LENGTH_MAX) {
      fprintf(stderr, "*** Warning: Word '%s...' possibly sliced.\n", w);
    }
    if (mset_mult(ms, w) != 0) {
      if (mset_add(ms, w) == NULL) {
        goto error_capacity;
      }
    } else {
      char *t = malloc(strlen(w) + 1);
      if (t == NULL) {
        goto error_capacity;
      }
      strcpy(t, w);
      if (holdall_put(ha, t) != 0) {
        free(t);
        goto error_capacity;
      }
      if (mset_add(ms, t) == NULL) {
        goto error_capacity;
      }
    }
  }
  //
  printf("%zu\n", mset_card(ms));
  //
#if 0
  while (!mset_is_empty(ms)) {
    char *t = (char *) mset_min(ms);
    printf("%zu\t%s\n", mset_mult(ms, t), t);
#if 1
    while (mset_remove(ms, t) != NULL) {
    }
#else
    mset_remove_all(ms, t);
#endif
  }
#endif
  //
  printf("%zu\n", mset_card(ms));
  //
  int r = EXIT_SUCCESS;
  goto dispose;
  //
error_capacity:
  fprintf(stderr, "*** Error: Ask wizard to enlarge me.\n");
  r = EXIT_FAILURE;
  goto dispose;
  //
dispose:
  mset_dispose(&ms);
  if (ha != NULL) {
    holdall_apply(ha, rfree);
  }
  holdall_dispose(&ha);
  //
  return r;
}

int rfree(void *ptr) {
  free(ptr);
  return 0;
}
