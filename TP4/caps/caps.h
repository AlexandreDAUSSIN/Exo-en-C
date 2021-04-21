#ifndef CAPS__H
#define CAPS__H

#include <stdio.h>

#define CAPS_DEFAULT_LEN  4

#ifndef CAPS_LEN
#define CAPS_LEN CAPS_DEFAULT_LEN
#else
#if CAPS_LEN <= 0
#error illegal value of CAPS_LEN
#endif
#endif

#ifndef CAPS_COMPAR_LEN
#define CAPS_COMPAR_LEN  CAPS_LEN
#else
#if CAPS_COMPAR_LEN <= 0 || CAPS_COMPAR_LEN > CAPS_LEN
#error illegal value of CAPS_COMPAR_LEN
#endif
#endif

//  caps est le nom d'une structure capable de mémoriser une suite de CAPS_LEN
//    lettres capitales
typedef struct {
  char reserved__usage[CAPS_LEN];
} caps;

//  caps_fget : lit une suite de CAPS_LEN lettres capitales consécutives sur le
//    flot contrôlé par l'objet pointé par stream et affecte la valeur associée
//    à l'objet pointé par ptr. La fonction renvoie EOF si une erreur survient
//    lors la lecture des éventuels caractères d'espacement initiaux. Elle
//    renvoie sinon 1 ou 0 selon que la lecture des CAPS_LEN lettres capitales a
//    pu être menée à son terme ou non.
extern int caps_fget(caps *ptr, FILE *stream);

//  caps_fput : écrit sur le flot contrôlé par l'objet pointé par stream les
//    CAPS_LEN lettres capitales de la suite mémorisée dans l'objet pointé par
//    ptr. Renvoie EOF en cas d'échec et zéro en cas de succès
extern int caps_fput(const caps *ptr, FILE *stream);

//  caps_rand : affecte une suite pseudo-aléatoire de CAPS_LEN lettres capitales
//    à l'objet pointé par ptr
extern void caps_rand(caps *ptr);

//  caps_compar : compare les objets pointés par ptr1 et ptr2 selon l'ordre
//    lexicographique en ne considérant que leurs préfixes de longueur
//    CAPS_COMPAR_LEN. Renvoie une valeur strictement inférieure, égale ou
//    strictement supérieure à zéro selon que le premier objet est strictement
//    inférieur, égal ou strictement supérieur au second
extern int caps_compar(const caps *ptr1, const caps *ptr2);

#endif
