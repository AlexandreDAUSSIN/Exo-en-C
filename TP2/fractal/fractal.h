#ifndef FRACTAL__H
#define FRACTAL__H

//  sfitted_squares : produit la figure fractale d'ordre n des carrés emboités à
//    l'intérieur d'un carré dont la longueur des côtés exprimée en pixels est
//    size. Renvoie une valeur non nulle en cas de demande d'abandon détectée
extern int fitted_squares(unsigned int size, int n);


//Triangle de Sierpinski
extern int sierp_tri;

//Tapis de Sierpinski
extern int sierp_carpet;
#endif
