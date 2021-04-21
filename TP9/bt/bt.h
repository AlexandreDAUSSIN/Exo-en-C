//  Interface pour la spécification ABIN du TDA ABin

#ifndef BT__H
#define BT__H

#include <stddef.h>
#include <stdbool.h>

//  struct bt, bt : structure regroupant les informations permettant de gérer un
//    arbre binaire. La création de la structure de données associée est confiée
//    aux fonctions bt_comb_left, bt_comb_right et bt_random.
typedef struct bt bt;

//  bt_comb_left, bt_comb_right, bt_random : créent une structure de données
//    correspondant à un peigne gauche, un peigne droit, un arbre binaire
//    aléatoire de taille n. Renvoient NULL en cas de dépassement de capacité.
//    Renvoient sinon un pointeur sur l'objet qui gère la structure de données
extern bt *bt_comb_left(size_t n);
extern bt *bt_comb_right(size_t n);
extern bt *bt_random(size_t n);

//  Les fonctions qui suivent ont un comportement indéterminé si leur paramètre
//    ou l'un de leurs paramètres de type bt * n'est pas l'adresse d'un objet
//    préalablement renvoyé par bt_comb_left, bt_comb_right ou bt_random et non
//    révoqué par bt_dispose depuis. Cette règle ne souffre que d'une seule
//    exception : bt_dispose tolère que la déréférence de son argument ait pour
//    valeur NULL

//  bt_dispose : si *tptr ne vaut pas NULL, libère les ressources allouées à
//    la structure de données associée à *tptr puis affecte à *tptr la valeur
//    NULL
extern void bt_dispose(bt **tptr);

//  bt_size, bt_height, bt_distance : renvoient la taille, la hauteur, la
//    distance de l'arbre binaire associé à t
extern size_t bt_size(bt *t);
extern size_t bt_height(bt *t);
extern size_t bt_distance(bt *t);

//  bt_is_skinny, bt_is_comb_left, bt_is_comb_right : testent si l'arbre binaire
//    associé à t est filiforme, un peigne gauche, un peigne droit
extern bool bt_is_skinny(bt *t);
extern bool bt_is_comb_left(bt *t);
extern bool bt_is_comb_right(bt *t);

//  bt_is_similar : teste si l'arbre binaire associé à t1 est semblable à celui
//    associé à t2
extern bool bt_is_similar(bt *t1, bt *t2);

//  bt_repr_graphic, bt_repr_formal, bt_repr_lukas, bt_repr_subtrees : affichent
//    sur la sortie standard une représentation graphique, la notation formelle,
//    le mot de Łukasiewicz, le mot des sous-arbres de l'arbre binaire associé à
//    t
extern void bt_repr_graphic(bt *t);
extern void bt_repr_formal(bt *t);
extern void bt_repr_lukas(bt *t);
extern void bt_repr_subtrees(bt *t);

#endif
