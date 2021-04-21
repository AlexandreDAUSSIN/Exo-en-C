#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "lcaps.h"

//  stop : lit des caractères sur l'entrée standard jusqu'à détecter la fin de
//    l'entrée ou obtenir 'q', 'Q' ou '\n'. Renvoie zéro si '\n' est obtenu, une
//    valeur non nulle sinon
int stop(void);

//lcaps_partition_pivot_tail :déplace respectivement en queue des listes
//associées à slth, seq et sgth, les éléments de la liste associée à s qui
//sont strictement inférieurs, égaux et strictement supérieurs au premier
//élément de la liste associée à s. Si la liste associée à s est vide, les
//quatre listes demeurent inchangées. À la terminaison, la liste associée à
//s est vide, les éléments des listes associées à slth, seq et sgth sont
//dans le même ordre que celui avec lequel ils figuraient originellement
//dans s 
void lcaps_partition_pivot_tail(lcaps *s, lcaps *slth, lcaps *seq, lcaps *sgth);

int main(void) {
  printf("--- Trials on lcaps module\n"
      "--- Type ctrl-d or enter 'q' or 'Q' to exit\n\n");
  srand(0);
  lcaps *s1;
  //lcaps *s1_2;
  lcaps *s2;
  //lcaps *s2_2;
  //lcaps *slth;
  //lcaps *seq;
  //lcaps *sgth;
 
  while (1) {
    //chaines avec opérations sur head
    s1 = lcaps_empty();
    s2 = lcaps_empty();
    //chaines avec opérations sur tail
    //s1_2 = lcaps_empty();
    //s2_2 = lcaps_empty();
    //chaines pour partition
    //slth = lcaps_empty();
    //seq = lcaps_empty();
    //sgth = lcaps_empty();
    for (int k = 5; k > 0; --k) {
      caps x1;
      caps x2;
      caps_rand(&x1);
      caps_rand(&x2);
      //chaine 1
      lcaps_insert_tail(s1, &x1);
      //lcaps_insert_tail(s1_2, &x1);
      //chaine 2
      lcaps_insert_tail(s2, &x2);
      //lcaps_insert_tail(s2_2, &x2);
    }
    //affichage chaine 1
    lcaps_fput(s1, stdout);
    //lcaps_fput(s1_2, stdout);
    //affichage chaine 2
    lcaps_fput(s2, stdout);
    //lcaps_fput(s2_2, stdout);
    //head to head
    lcaps_move_head_tail(s1, s2);
    lcaps_fput(s1, stdout);
    lcaps_fput(s2, stdout);
    //head to tail
    //lcaps_move_head_tail(s1_2, s2_2);
    //lcaps_fput(s1_2, stdout);
    //lcaps_fput(s2_2, stdout);
    //chaine 1 to head chaine 2
    lcaps_move_all_tail(s1, s2);
    lcaps_fput(s1, stdout);
    lcaps_fput(s2, stdout);
    //chaine 1 to tail chaine 2
    //lcaps_move_all_tail(s1_2, s2_2);
    //lcaps_fput(s1_2, stdout);
    //lcaps_fput(s2_2, stdout);
    //partition pivot de la chaine 2
    //lcaps_partition_pivot_tail(s2_2, slth, seq, sgth);
    //dispose
    //lcaps_dispose(&s1_2);
    lcaps_dispose(&s1);
    //lcaps_dispose(&s2_2);
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

//lcaps_partition_pivot_tail :déplace respectivement en queue des listes
//associées à slth, seq et sgth, les éléments de la liste associée à s qui
//sont strictement inférieurs, égaux et strictement supérieurs au premier
//élément de la liste associée à s. Si la liste associée à s est vide, les
//quatre listes demeurent inchangées. À la terminaison, la liste associée à
//s est vide, les éléments des listes associées à slth, seq et sgth sont
//dans le même ordre que celui avec lequel ils figuraient originellement
//dans s 
//void lcaps_partition_pivot_tail(lcaps *s, lcaps *slth, lcaps *seq, lcaps *sgth){
  //if(lcaps_is_empty(s) == true){
    //return;
  //}
  //caps ds;
  //caps sk;
  //lcaps_head_value(s, &ds);
  //while(s != NULL){
    //lcaps_head_value(s, &sk);
    //if(ds < sk){
      //lcaps_move_head_tail(s, slth);
    //}
    //if(ds == sk){
      //lcaps_move_head_tail(s, seq);
    //}
    //if(ds > sk){
      //lcaps_move_head_tail(s, sgth);
    //}
    //s = s + 1;
  //}
//}

