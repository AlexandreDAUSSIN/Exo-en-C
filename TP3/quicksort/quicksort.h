//  Quick Sort. Un module basique implantant le tri rapide

#ifndef QUICKSORT__H
#define QUICKSORT__H

#include <stddef.h>

//  quicksort : même spécification que la fonction qsort déclarée dans l'en-tête
//    <stdlib.h> de la bibliothèque standard
extern void quicksort(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *));

#endif
