#include <stdlib.h>
#include "nat_io.h"
#include "nat_op.h"

int main(void) {
  nat x;
  nat y;
  while (input(stdin, &x) != EOF && input(stdin, &y) != EOF) {
    //Somme
    output(stdout, x);
    printf(" + ");
    output(stdout, y);
    printf(" = ");
    output(stdout, sum(x, y));
    printf("\n");
    //Distance
    printf(" Distance entre ");
    output(stdout, x);
    printf(" et ");
    output(stdout, y);
    printf(" est ");
    output(stdout, dist(x, y));
    printf("\n");
    //Minimum
    printf(" Minimum entre ");
    output(stdout, x);
    printf(" et ");
    output(stdout, y);
    printf(" est ");
    output(stdout, min(x, y));
    printf("\n");
    //Maximum
    printf(" Maximum entre ");
    output(stdout, x);
    printf(" et ");
    output(stdout, y);
    printf(" est ");
    output(stdout, max(x, y));
    printf("\n");
    //Égaux
    output(stdout, x);
    printf(" et ");
    output(stdout, y);
    printf(" sont égaux ");
    output(stdout, is_eq(x, y));
    printf("\n");
    //Différents
    output(stdout, x);
    printf(" et ");
    output(stdout, y);
    printf(" sont différents ");
    output(stdout, is_neq(x, y));
    printf("\n");
    //Inférieur ou égaux
    output(stdout, x);
    printf(" est inférieur ou égal à ");
    output(stdout, y);
    output(stdout, is_leq(x, y));
    printf("\n");
    //Inférieur
    output(stdout, x);
    printf(" est inférieur à ");
    output(stdout, y);
    output(stdout, is_lth(x, y));
    printf("\n");
    //EXO 3
    //Produit
    output(stdout, x);
    printf(" * ");
    output(stdout, y);
    printf(" = ");
    output(stdout, mul(x, y));
    printf("\n");
    //Quotient et Reste ?
    output(stdout, x);
    printf(" % ");
    output(stdout, y);
    printf(" = ");
    output(stdout, div_eu(x, y));
    printf("\n");
  }
  return EXIT_SUCCESS;
}

