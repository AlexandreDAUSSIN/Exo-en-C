//  Implantation pour la spécification ABIN du TDA ABin

#include <stdlib.h>
#include <stdio.h>
#include "bt.h"

//--- Types bt et cbt ----------------------------------------------------------

typedef struct cbt cbt;

struct cbt {
  cbt *next[2];
};

struct bt {
  cbt *root;
};

//--- Raccourcis ---------------------------------------------------------------

#define EMPTY()         NULL
#define IS_EMPTY(root)  ((root) == NULL)
#define LEFT(root)      ((root)->next[0])
#define RIGHT(root)     ((root)->next[1])

//--- Divers -------------------------------------------------------------------

static size_t add__size_t(size_t x1, size_t x2) {
  return x1 + x2;
}

static size_t max__size_t(size_t x1, size_t x2) {
  return x1 > x2 ? x1 : x2;
}

static size_t min__size_t(size_t x1, size_t x2) {
  return x1 < x2 ? x1 : x2;
}

//--- Fonctions cbt ------------------------------------------------------------

static void cbt__dispose(cbt *root) {
  if (!IS_EMPTY(root)) {
    cbt__dispose(LEFT(root));
    cbt__dispose(RIGHT(root));
    free(root);
  }
}

static cbt *cbt__root(cbt *left, cbt *right) {
  cbt *r = malloc(sizeof *r);
  if (r == NULL) {
    cbt__dispose(left);
    cbt__dispose(right);
    return EMPTY();
  }
  LEFT(r) = left;
  RIGHT(r) = right;
  return r;
}

static cbt *cbt__comb_left(size_t n) {
  return n == 0
         ? EMPTY()
         : cbt__root(cbt__comb_left(n - 1), EMPTY());
}

static cbt *cbt__comb_right(size_t n){
  return n == 0
         ? EMPTY()
         : cbt__root(EMPTY(), cbt__comb_right(n - 1));
}

static cbt *cbt__random(size_t n){
  size_t k = (size_t) rand() % n;
  return n == 0
         ? EMPTY()
         : cbt__root(cbt__comb_left(k), cbt__comb_right(n - k));
}
         

#define DEFUN_CBT__MEASURE(fun, oper)                                          \
  static size_t cbt__ ## fun(const cbt * root) {                               \
    return IS_EMPTY(root)                                                      \
           ? 0                                                                 \
           : 1 + oper(cbt__ ## fun(LEFT(root)), cbt__ ## fun(RIGHT(root)));    \
  }

DEFUN_CBT__MEASURE(size, add__size_t)
DEFUN_CBT__MEASURE(height, max__size_t)
DEFUN_CBT__MEASURE(distance, min__size_t)

static bool cbt__is_skinny(const cbt *root){
  if (DEFUN_CBT__MEASURE(size(root), add__size_t) ==
      DEFUN_CBT__MEASURE(height(root), max__size_t)){
    return true;
  }
  return false;
}
  
static bool cbt__is_comb_left(const cbt *root){
  if (RIGHT(root) != NULL){
    return false;
  }
  if (LEFT(root) != NULL){
    cbt__is_comb_left(LEFT(roo));
  }
  return true;
}

static bool cbt__is_comb_right(const cbt *root){
  if (LEFT(root) != NULL){
    return false;
  }
  if (RIGHT(root) != NULL){
    cbt__is_comb_right(RIGHT(roo));
  }
  return true;
}

static bool cbt__is_similar(const cbt *root1, const cbt *root2){
  if((DEFUN_CBT__MEASURE(size(root1), add__size_t) != 
     DEFUN_CBT__MEASURE(size(root2), add__size_t)) ||
     (DEFUN_CBT__MEASURE(height(root1), max__size_t) !=
     DEFUN_CBT__MEASURE(height(root2), max__size_t)) ||
     (DEFUN_CBT__MEASURE(distance(root1), min__size_t) !=
     DEFUN_CBT__MEASURE(distance(root2), min__size_t))){
       return false;
     }
     return true;
}

static void cbt__repr_graphic(const cbt *root, size_t level) {
  if (IS_EMPTY(root)) {
    printf("%*c\n", 4 * (int) level + 1, '|');
  } else {
    cbt__repr_graphic(RIGHT(root), level + 1);
    printf("%*c\n", 4 * (int) level + 1, '0'); 
    cbt__repr_graphic(LEFT(root), level + 1);
  }
}

static void cbt__repr_formal(const cbt *root) {
  printf("(");
  if (!IS_EMPTY(root)) {
    cbt__repr_formal(LEFT(root));
    printf(" ");
    cbt__repr_formal(RIGHT(root));
  }
  printf(")");
}

//  ICI, PROCHAINEMENT, LES DÉFINITIONS DE :
//    static void cbt__repr_lukas(const cbt *root);
//    static void cbt__repr_subtrees(const cbt *root);

//--- Fonctions bt -------------------------------------------------------------

bt *bt_comb_left(size_t n) {
  bt *t = malloc(sizeof *t);
  cbt *r = cbt__comb_left(n);
  if (t == NULL || cbt__size(r) != n) {
    free(t);
    cbt__dispose(r);
    return NULL;
  }
  t->root = r;
  return t;
}

bt *bt_comb_right(size_t n) {
  bt *t = malloc(sizeof *t);
  cbt *r = cbt__comb_right(n);
  if (t == NULL || cbt__size(r) != n) {
    free(t);
    cbt__dispose(r);
    return NULL;
  }
  t->root = r;
  return t;
}

bt *bt_random(size_t n) {
  bt *t = malloc(sizeof *t);
  cbt *r = cbt__random(n);
  if (t == NULL || cbt__size(r) != n) {
    free(t);
    cbt__dispose(r);
    return NULL;
  }
  t->root = r;
  return t;
}

void bt_dispose(bt **tptr) {
  if (*tptr == NULL) {
    return;
  }
  cbt__dispose((*tptr)->root);
  free(*tptr);
  *tptr = NULL;
}

#define DIMENSIONS =                                                          \\
taille (bt *t) = cbt__size(t->root);                                          \\
                                                                              \\
hauteur (bt *t) = cbt__height(t->root);                                       \\
                                                                              \\
distance (bt *t) = cbt__distance(t->root);                                    \\

bool bt_is_skinny(bt *t){
  if taille(t) = hauteur(t){
    return true;
  }
  return false;
}

bool bt_is_comb_left(bt *t){
  if (bt_comb_left(hauteur(t)) != NULL){
    return true;
  }
  return false;
}

bool bt_is_comb_right(bt *t){
  if (bt_comb_right(hauteur(t)) != NULL){
    return true;
  }
  return false;
}

bool bt_is_similar(bt *t1, bt *t2){
  if ((taille(t1) != taille(t2)) || (hauteur(t1) != hauteur(t2)) ||
      (distance(t1) != distance(t2))){
    return false;
  }
  return true;
}

void bt_repr_graphic(bt *t){
  if (IS_EMPTY(t)) {
    printf("%*c\n", 4 * (int) level + 1, '|');
  } else {
    cbt__repr_graphic(RIGHT(t), level + 1);
    printf("%*c\n", 4 * (int) level + 1, '0'); 
    cbt__repr_graphic(LEFT(t), level + 1);
  }
}

void bt_repr_formal(bt *t) {
  cbt__repr_formal(t->root);
}

//  ICI, PROCHAINEMENT, LES DÉFINITIONS DE :
//    void bt_repr_lukas(bt *t);
//    void bt_repr_subtrees(bt *t);
