//  Test de toutes les fonctions du module bt

#include <stdlib.h>
#include <stdio.h>
#include "bt.h"

#define INITIALIZE(t, fun, size)                                               \
  t = fun(size);                                                               \
  if (t == NULL) {                                                             \
    fprintf(stderr, "*** Not enough memory\n");                                \
    exit(EXIT_FAILURE);                                                        \
  }                                                                            \
  printf("\x1b[0;1m");                                                         \
  printf("with %s = %s(%zu)\n", #t, #fun, (size_t) size);                      \
  printf("\x1b[0m")

#define DISPLAY_SIZE_T(t, fun) \
  printf("%20s(%s) = %zu\n", #fun, #t, fun(t))

#define DISPLAY_BOOL(t, fun) \
  printf("%20s(%s) = %s\n", #fun, #t, fun(t) ? "true" : "false")

#define DISPLAY_VOID(t, fun, pre)                                              \
  printf("%20s(%s) = " pre, #fun, #t);                                         \
  fun(t);                                                                      \
  printf("\n")

#define DISPLAY_BOOL2(t1, t2, fun) \
  printf("%20s(%s, %s) = %s\n", #fun, #t1, #t2, fun(t1, t2) ? "true" : "false")

#define RAND_SEED           20201126
#define CHECK_SIZE          4
#define RANDOM_BT_MAX       4
#define SIMILAR_BT_SIZE_MAX 5

int main(void) {
  srand(RAND_SEED);
  {
    bt *t = NULL;
    INITIALIZE(t, bt_comb_left, CHECK_SIZE);
    //DISPLAY_VOID(t, bt_repr_graphic, "\n");
    DISPLAY_VOID(t, bt_repr_formal, );
    DISPLAY_SIZE_T(t, bt_size);
    DISPLAY_SIZE_T(t, bt_height);
    DISPLAY_SIZE_T(t, bt_distance);
    bt_dispose(&t);
  }
  {
    bt *t = NULL;
    //INITIALIZE(t, bt_comb_right, CHECK_SIZE);
    //DISPLAY_VOID(t, bt_repr_graphic, "\n");
    //DISPLAY_VOID(t, bt_repr_formal, );
    //DISPLAY_SIZE_T(t, bt_size);
    //DISPLAY_SIZE_T(t, bt_height);
    //DISPLAY_SIZE_T(t, bt_distance);
    bt_dispose(&t);
  }
  {
    for (int k = 0; k < RANDOM_BT_MAX; ++k) {
      bt *t = NULL;
      //INITIALIZE(t, bt_random, CHECK_SIZE);
      //DISPLAY_VOID(t, bt_repr_graphic, "\n");
      //DISPLAY_VOID(t, bt_repr_formal, );
      //DISPLAY_VOID(t, bt_repr_lukas, );
      //DISPLAY_VOID(t, bt_repr_subtrees, );
      //DISPLAY_SIZE_T(t, bt_size);
      //DISPLAY_SIZE_T(t, bt_height);
      //DISPLAY_SIZE_T(t, bt_distance);
      //DISPLAY_BOOL(t, bt_is_skinny);
      //DISPLAY_BOOL(t, bt_is_comb_left);
      //DISPLAY_BOOL(t, bt_is_comb_right);
      bt_dispose(&t);
    }
  }
  {
    for (size_t k = 0; k <= SIMILAR_BT_SIZE_MAX; ++k) {
      bt *t1 = NULL;
      bt *t2 = NULL;
      //INITIALIZE(t1, bt_random, k);
      //INITIALIZE(t2, bt_random, k);
      //DISPLAY_VOID(t1, bt_repr_graphic, "\n");
      //DISPLAY_VOID(t2, bt_repr_graphic, "\n");
      //DISPLAY_BOOL2(t1, t2, bt_is_similar);
      bt_dispose(&t1);
      bt_dispose(&t2);
    }
  }
  return EXIT_SUCCESS;
}
