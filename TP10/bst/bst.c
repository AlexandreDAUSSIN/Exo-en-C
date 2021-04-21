//  Implantation polymorphe pour la spécification ABINR du TDA ABinR(T)

#include "bst.h"

//--- Types bst et cbst --------------------------------------------------------

typedef struct cbst cbst;

struct cbst {
  cbst *next[2];
  const void *value;
};

struct bst {
  int (*compar)(const void *, const void *);
  cbst *root;
};

//--- Raccourcis ---------------------------------------------------------------

#define EMPTY()     NULL
#define IS_EMPTY(p) ((p) == NULL)
#define LEFT(p)     ((p)->next[0])
#define RIGHT(p)    ((p)->next[1])
#define VALUE(p)    ((p)->value)
#define NEXT(p, c)  ((p)->next[(c) > 0])

//--- Fonctions cbst -----------------------------------------------------------

static void cbst__dispose(cbst *p) {
  if (!IS_EMPTY(p)) {
    cbst__dispose(LEFT(p));
    cbst__dispose(RIGHT(p));
    free(p);
  }
}

static size_t cbst__size(const cbst *p) {
  return IS_EMPTY(p) ? 0 : 1 + cbst__size(LEFT(p)) + cbst__size(RIGHT(p));
}
  
//--- Fonctions bst ------------------------------------------------------------

bst *bst_empty(int (*compar)(const void *, const void *)) {
  bst *t = malloc(sizeof *t);
  if (t == NULL) {
    return NULL;
  }
  t->compar = compar;
  t->root = EMPTY();
  return t;
}

void bst_dispose(bst **tptr) {
  if (*tptr == NULL) {
    return;
  }
  cbst__dispose((*tptr)->root);
  free(*tptr);
  *tptr = NULL;
}

size_t bst_size(bst *t) {
  return cbst__size(t->root);
}

void bst_repr_graphic(bst *t, void (*put)(const void *xptr)){
  if (IS_EMPTY(t)){
    printf("O");
  }else{
    put(*t);
  }
  printf("%t \n", bst_size(t));
}

void put(const void *xptr){
  printf("%d \n", *xptr);
}

const void *bst_search(bst *t, const void *xptr){
  if(IS_EMPTY(*xptr)){
    return NULL;
  }else{
    if(compar(*xptr, *t) == 0){
      return t;
    }
  }
  return NULL;
}

const void *bst_add_endofpath(bst *t, const void *xptr){
  /*static*/ const void *cbst__add_endofpath(cbst **pp, const void *xptr,
  int (*compar)(const void *, const void *)){
    if(IS_EMPTY(xptr) || (strlen(*pp) + strlen(*xptr)) > STR_MAX){
      return NULL;
    }else{
      if(compar(*xptr, VALUE(*pp)) == 0){
        return *pp;
      }
      cbst__add_endofpath(NEXT(*pp, LEFT(*pp)), *xptr, *compar);
      cbst__add_endofpath(NEXT(*pp, RIGHT(*pp)), *xptr, *compar);
    }
    if(LEFT(*pp) == NULL){
      VALUE(LEFT(*pp)) = *xptr;
      return xptr;
    }else{
      VALUE(RIGHT(*pp)) = *xptr;
      return xptr;
    }
  }
}

const void *bst_remove_climbup_left(bst *t, const void *xptr){
  static const void *cbst__remove_max(cbst **pp){
    
  }
  static void cbst__remove_root(cbst **pp){
    
  }
  static const void *cbst__remove_climbup_left(cbst **pp, const void *xptr,
  int (*compar)(const void *, const void *)){
    
  }
}
