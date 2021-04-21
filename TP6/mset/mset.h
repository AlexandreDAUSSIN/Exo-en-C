//  Interface polymorphe pour la spécification MENS du TDA MEns(T) et son
//    extension MENSMIN. L'accès à l'extension MENSMIN requiert la définition de
//    la macroconstante MSETMIN

#ifndef MSET__H
#define MSET__H

#include <stdlib.h>
#include <stdbool.h>

//  struct mset, mset : structure regroupant les informations permettant de
//    gérer un multi-ensemble dont les éléments sont des objets quelconques. La
//    création de la structure de données associée est confiée à la fonction
//    mset_empty dont le paramètre compar précise la fonction de comparaison des
//    éléments. Une structure de données peut également être créée par copie
//    d'une autre en recourant à la fonction mset_duplicate
//  La structure de données ne stocke pas les objets mais des pointeurs vers ces
//    objets. Les pointeurs sont du type générique const void *
//  L'utilisateur doit garantir que l'adresse de chaque objet fournie aux
//    diverses fonctions est valide durant toute la durée de la présence de
//    l'objet dans le multi-ensemble. Si des opérations d'allocation dynamique
//    sont effectuées, elles le sont pour la gestion propre de la structure de
//    données, et en aucun cas pour réaliser de copies ou des destructions
//    d'objets
typedef struct mset mset;

//  Les fonctions qui suivent ont un comportement indéterminé si leur paramètre
//    de type mset * n'est pas l'adresse d'un objet préalablement renvoyé par
//    mset_empty ou mset_duplicate et non révoqué depuis par mset_dispose. Cette
//    règle ne souffre que d'une seule exception : mset_dispose tolère que la
//    déréférence de son argument ait pour valeur NULL

//  mset_empty : crée une structure de données correspondant initialement au
//    multi-ensemble vide. La fonction de comparaison des éléments est compar.
//    Renvoie NULL en cas de dépassement de capacité. Renvoie un pointeur vers
//    l'objet qui gère la structure de données sinon
extern mset *mset_empty(int (*compar)(const void *, const void *));

//  mset_add : recherche dans le multi-ensemble associé à ms un élément égal à
//    celui d'adresse xptr au sens de compar. Si un tel élément existe, cas 1),
//    incrémente son nombre d'occurrences. Sinon, cas 2), l'élément d'adresse
//    xptr est ajouté au multi-ensemble avec un nombre d'occurrences égal à un.
//    Renvoie NULL si xptr vaut NULL ou en cas de dépassement de capacité.
//    Renvoie sinon l'adresse de l'élément trouvé dans le cas 1), xptr dans le
//    cas 2)
extern const void *mset_add(mset *ms, const void *xptr);

//  mset_remove : recherche dans le multi-ensemble associé à ms un élément égal
//    à celui d'adresse xptr au sens de compar. Si un tel élément existe, le
//    retire du multi-ensemble si son nombre d'occurrences égale un et
//    décrémente son nombre d'occurrences sinon. Renvoie NULL si xptr vaut NULL
//    ou si aucun élément de la sorte n'existe. Renvoie sinon l'adresse de
//    l'élément trouvé
extern const void *mset_remove(mset *ms, const void *xptr);

//  mset_remove_all : retire du multi-ensemble associé à ms toutes les
//    occurrences d'éléments égaux à celui d'adresse xptr au sens de compar.
//    Renvoie NULL si xptr vaut NULL ou si aucune occurrence de la sorte
//    n'existe. Renvoie sinon xptr
extern const void *mset_remove_all(mset *ms, const void *xptr);

//  mset_is_empty : renvoie true ou false selon que le multi-ensemble associé à
//    ms est vide ou non
extern bool mset_is_empty(mset *ms);

//  mset_mult : calcule le nombre d'occurrences d'éléments du multi-ensemble
//    associé à ms égaux à celui d'adresse xptr au sens de compar. Renvoie zéro
//    si xptr vaut NULL. Renvoie sinon le nombre d'occurrences
extern size_t mset_mult(mset *ms, const void *xptr);

//  mset_card : renvoie le cardinal du multi-ensemble associé à ms
extern size_t mset_card(mset *ms);

#ifdef MSETMIN

//  mset_min : recherche un élément minimal du multi-ensemble associé à ms au
//    sens de compar. Renvoie NULL si le multi-ensemble est vide. Renvoie sinon
//    l'adresse d'un élément minimal
extern const void *mset_min(mset *ms);

#endif

//  mset_dispose : si *msptr ne vaut pas NULL, libère les ressources allouées à
//    la structure de données associée à *msptr puis affecte à *msptr la valeur
//    NULL
extern void mset_dispose(mset **msptr);

//  mset_duplicate : crée une structure de données dont le multi-ensemble
//    qu'elle représente contient les mêmes éléments que celui associé à ms et
//    qui possède la même fonction de comparaison des éléments. Renvoie NULL en
//    cas de dépassement de capacité. Renvoie un pointeur vers l'objet qui gère
//    la structure de données créée sinon
extern mset *mset_duplicate(mset *ms);

#endif
