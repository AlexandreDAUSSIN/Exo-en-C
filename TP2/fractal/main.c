#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fractal.h"
#include "sg.h"

#define SIZE_DEFAULT 640

int main(void) {
  sg_open(SIZE_DEFAULT, SIZE_DEFAULT, BLACK, WHITE, "Recursive graphs");
  if (fitted_squares(SIZE_DEFAULT, 2) == 0 
    && sierp_tri(SIZE_DEFAULT, 5) == 0 
    //&& sierp_carpet(SIZE_DEFAULT, 5) == 0
    //&& autre_fractale(SIZE_DEFAULT, ordre_maximal) == 0
    //&& ...
      ) {
  }
  sg_close();
  return EXIT_SUCCESS;
}
