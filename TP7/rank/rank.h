#ifndef RANK__H
#define RANK__H

#include <stddef.h>

//  rank : alloue un tableau de pointeurs du type générique void * et y range le
//    classement du tableau pointé par base selon la fonction de comparaison
//    pointée par compar. La longueur du tableau alloué et du tableau pointé par
//    base est nmemb. La taille des éléments du tableau pointé par base est
//    size. Renvoie NULL si nmemb vaut zéro ou en cas de dépassement de
//    capacité. Renvoie sinon l'adresse du tableau alloué
void **rank(const void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *));

#endif
