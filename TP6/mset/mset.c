//  Implantation polymorphe pour la spécification MENS du TDA MEns(T) et son
//    extension MENSMIN. L'accès à l'extension MENSMIN requiert la définition de
//    la macroconstante MSETMIN

#include "mset.h"

//  struct mset, mset : gestion des adresses des éléments dans le multi-ensemble
//    à l'aide d'une liste dynamique simplement chainée. Le composant compar
//    mémorise la fonction de comparaison des éléments à partir de leurs
//    adresses, le composant head a pour valeur le pointeur de tête de la liste,
//    le composant card mémorise le cardinal du multi-ensemble

typedef struct cmset cmset;

struct cmset {
  const void *value;
  //size_t mult;
  cmset *next;
};

struct mset {
  int (*compar)(const void *, const void *);
  cmset *head;
  size_t card;
};

mset *mset_empty(int (*compar)(const void *, const void *)) {
  mset *ms = malloc(sizeof *ms);
  if (ms == NULL) {
    return NULL;
  }
  ms->compar = compar;
  ms->head = NULL;
  ms->card = 0;
  return ms;
}

void mset_dispose(mset **msptr){
  if (*msptr == NULL) {
    return;
  }
  cmset *p = (*msptr)->head;
  while (p != NULL) {
    cmset *t = p;
    p = p->next;
    free(t);
  }
  free(*msptr);
  *msptr = NULL;
}

}

const void *mset_add(mset *ms, const void *xptr){
  if (*ms == NULL){
    *ms->value = *xptr;
  }
  cmset *p = (*ms)->head;
  int k = 0;
  while (p != NULL){
    if ((p->value) == *xptr){
      k = k + 1;
      return *p;
    }
      p = p->next;
  }
  p->value = *xptr,
  return xptr;
}

size_t mset_mult(mset *ms, const void *xptr) {
  if (xptr == NULL) {
    return 0;
  }
  cmset *p = ms->head;
  size_t mult = 0;
  while (p != NULL) {
    if (ms->compar(xptr, p->value) == 0) {
      ++mult;
    }
    p = p->next;
  }
  return mult;
}

size_t mset_card(mset *ms){
  if (ms == NULL){
    return 0
  }
  size_t k = 0;
  cmset *p = ms->head;
  while (p != NULL){
    k = k + 1;
    p = p->next;
  }
  return k;
}

bool mset_is_empty(mset *ms){
  return ms->head = NULL;
}

//const void *mset_min(mset *ms){
  
//}

const void *mset_remove(mset *ms, const void *xptr){
if (xptr == NULL) {
    return NULL;
  }
cmset **pp = &(ms->head);
while (*pp != NULL && ms->compar(xptr, (*pp)->value) != 0) {
      pp = &((*pp)->next);
  }
  if (*pp == NULL) {
    return NULL;
  }
  const void *yptr = (*pp)->value;
  cmset *t = *pp;
  *pp = t->next;
  free(t);
  ms->card -= 1;
  return yptr;
}

//const void *mset_remove_all(mset *ms, const void *xptr){
  
//}

//mset *mset_duplicate(mset *ms){
  
//}

