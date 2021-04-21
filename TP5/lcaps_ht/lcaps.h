#ifndef LCAPS__H
#define LCAPS__H

#include <stdbool.h>
#include "caps.h"

//  struct lcaps, lcaps : structure capable de gérer une liste dynamique
//    simplement chainée sur le type caps, d'alias lcaps
typedef struct lcaps lcaps;

//  lcaps_empty : crée un objet de type lcaps. La liste est initialement vide.
//    Renvoie un pointeur vers l'objet en cas de succès, NULL en cas d'échec
extern lcaps *lcaps_empty(void);

//  lcaps_is_empty : renvoie true ou false selon que la liste associée à s est
//    vide ou non
extern bool lcaps_is_empty(const lcaps *s);

//  lcaps_length : renvoie la longueur de la liste associée à s
extern size_t lcaps_length(const lcaps *s);

//  lcaps_head_value, lcaps_tail_value : si la liste associée à s n'est pas
//    vide, affecte à *ptr la valeur de l'élément de tête (head) ou de queue
//    (tail) et renvoie zéro. Renvoie une valeur non nulle sinon
extern int lcaps_head_value(const lcaps *s, caps *ptr);
extern int lcaps_tail_value(const lcaps *s, caps *ptr);

//  lcaps_insert_head, lcaps_insert_tail : insère une copie de *ptr en tête
//    (head) ou en queue (tail) de la liste associée à s. Renvoie zéro en cas de
//    succès, une valeur non nulle en cas d'échec
extern int lcaps_insert_head(lcaps *s, caps *ptr);
extern int lcaps_insert_tail(lcaps *s, caps *ptr);

//  lcaps_move_head_head, lcaps_move_head_tail : déplace l'élément de tête de la
//    liste associée à src vers la tête (head_head) ou la queue (head_tail) de
//    la liste associée à dest. Renvoie zéro en cas de succès, une valeur non
//    nulle en cas d'échec pour cause de liste associée à src vide
extern int lcaps_move_head_head(lcaps *src, lcaps *dest);
extern int lcaps_move_head_tail(lcaps *src, lcaps *dest);

//  lcaps_move_all_head, lcaps_move_all_tail : déplace en tête (head) ou en
//    queue (tail) de la liste associée à dest la liste associée à src. En cas
//    de succès, la liste associée à src est vide à la terminaison et la
//    fonction renvoie zéro. En cas d'échec, parce que src == dest, renvoie une
//    valeur non nulle
extern int lcaps_move_all_head(lcaps *src, lcaps *dest);
extern int lcaps_move_all_tail(lcaps *src, lcaps *dest);

//  lcaps_fput : écrit sur le flot contrôlé par l'objet pointé par stream les
//    éléments de la liste associée à s. Les éléments sont écrits séparés par
//    une espace. Le délimiteur gauche est vide, le délimiteur droit est la fin
//    de ligne. Renvoie zéro en cas de succès, une valeur non nulle en cas
//    d'échec
extern int lcaps_fput(const lcaps *s, FILE *stream);

//  lcaps_dispose : si *sptr ne vaut pas NULL, libère les ressources allouées à
//    *sptr ainsi qu'à la liste associée puis affecte la valeur NULL à *sptr
extern void lcaps_dispose(lcaps **sptr);

#endif
