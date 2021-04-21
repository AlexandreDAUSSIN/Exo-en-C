#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "caps.h"

#define STR(x)  #x
#define XSTR(x) STR(x)

#define NORMAL()  printf("\x1b[0m")
#define OTHER()   printf("\x1b[5m\x1b[3;37m")

int main(void) {
  srand((unsigned int) time(NULL));
  caps x;
  caps_rand(&x);
  printf("J'ai tiré une suite de " XSTR(CAPS_LEN) " lettres capitales"
      " au hasard.\nTu dois la deviner.\n");
#if CAPS_COMPAR_LEN < CAPS_LEN
  OTHER();
  printf("(Psst ! Il ne fera la comparaison que sur %s !)\n",
      CAPS_COMPAR_LEN == 1
      ? "la première lettre"
      : "les " XSTR(CAPS_COMPAR_LEN) " premières lettres");
  NORMAL();
#endif
  while (1) {
    printf("\nTa proposition ? ");
    caps y;
    if (caps_fget(&y, stdin) != 1) {
      printf("\nTu arrêtes ? Dommage...\nJ'avais choisi ");
      caps_fput(&x, stdout);
      printf(".\nÀ une autre fois peut-être ?\n");
      OTHER();
      printf("(Petit joueur !!!)\n");
      NORMAL();
      printf("\n");
      return EXIT_FAILURE;
    }
    int c = caps_compar(&x, &y);
    if (c == 0) {
      printf("Tu as gagné !\nTu as découvert que j'avais choisi ");
      caps_fput(&x, stdout);
      printf(".\nBravo !\n");
      OTHER();
      printf("(Merci qui ??\?)\n");
      NORMAL();
      printf("\n");
      return EXIT_SUCCESS;
    }
    printf("Loupé !\n");
    OTHER();
    printf("(Psst ! Vise plus %s...)\n", c < 0 ? "bas" : "haut");
    NORMAL();
  }
}
