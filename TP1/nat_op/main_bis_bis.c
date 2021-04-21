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
    bool b1 = is_eq(x, y);
    printf(" %d ", b1);
    printf("\n");
    //Différents
    output(stdout, x);
    printf(" et ");
    output(stdout, y);
    printf(" sont différents ");
    bool b2 = is_neq(x, y);
    printf(" %d ", b2);
    printf("\n");
    //Inférieur ou égaux
    output(stdout, x);
    printf(" est inférieur ou égal à ");
    output(stdout, y);
    bool b3 = is_leq(x, y);
    printf(" %d ", b3);
    printf("\n");
    //Inférieur
    output(stdout, x);
    printf(" est inférieur à ");
    output(stdout, y);
    bool b4 = is_lth(x, y);
    printf(" %d ", b4);
    printf("\n");
    //EXO 3
    //Produit
    output(stdout, x);
    printf(" * ");
    output(stdout, y);
    printf(" = ");
    output(stdout, mul(x, y));
    printf("\n");
    //Quotient
    printf(" Le quotient de ");
    output(stdout, x);
    printf(" divisé par ");
    output(stdout, y);
    printf(" est ");
    output(stdout, div_q(x, y));
    printf("\n");
    //Reste
    printf(" Le reste de ");
    output(stdout, x);
    printf(" divisé par ");
    output(stdout, y);
    printf(" est ");
    output(stdout, div_r(x, y));
    printf("\n");
  }
  return EXIT_SUCCESS;
}

