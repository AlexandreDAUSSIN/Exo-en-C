#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "lcaps.h"

//  stop : lit des caractères sur l'entrée standard jusqu'à détecter la fin de
//    l'entrée ou obtenir 'q', 'Q' ou '\n'. Renvoie zéro si '\n' est obtenu, une
//    valeur non nulle sinon
int stop(void);

//lcaps_move_all_head: déplace en tête de la liste associée à dest la liste
//associée à src. En cas de succès, la liste associée à src est vide à la
//terminaison et la fonction renvoie zéro. En cas d’échec, en particulier
//parceque src == dest, renvoie une valeur non nulle
int lcaps_move_all_head(lcaps *src, lcaps *dest);

int main(void) {
  printf("--- Trials on lcaps module\n"
      "--- Type ctrl-d or enter 'q' or 'Q' to exit\n\n");
  srand(0);
  lcaps *s1;
  lcaps *s2;
  while (1) {
    s1 = lcaps_empty();
    s2 = lcaps_empty();
    for (int k = 0; k < 15; ++k) {
      caps ds1;
      caps ds2;
      caps_rand(&ds1);
      caps_rand(&ds2);
      lcaps_insert_head(s1, &ds1);
      lcaps_insert_head(s2, &ds2);
    }
    //caps d1;
    //caps d2;
    //lcaps_fput(s1, stdout);
    //lcaps_fput(s2, stdout);
    //lcaps_move_head_head(s1, s2);
    //lcaps_fput(s1, stdout);
    //lcaps_fput(s2, stdout);
    //lcaps_head_value(s1, &d1);
    //lcaps_head_value(s2, &d2);
    lcaps_move_all_head(s1, s2);
    lcaps_fput(s1, stdout);
    lcaps_fput(s2, stdout);
    lcaps_dispose(&s1);
    lcaps_dispose(&s2);
    printf("\n> ");
    if (stop()) {
      return EXIT_SUCCESS;
    }
  }
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

int lcaps_move_all_head(lcaps *src, lcaps *dest) {
  if (src == dest) {
    return -1;
  }
  lcaps *inter = lcaps_empty();
  while (lcaps_is_empty(src) != true) {
    lcaps_move_head_head(src, inter);
  }
  while (lcaps_is_empty(inter) != true) {
    lcaps_move_head_head(inter, dest);
  }
  return 0;
}



