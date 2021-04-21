//  Interface polymorphe pour la spécification ABINR du TDA ABinR(T)

#ifndef BST__H
#define BST__H

#include <stdlib.h>
#include <stdio.h>

//  struct bst, bst : structure regroupant les informations permettant de gérer
//    un arbre binaire de recherche dont les valeurs sont des objets
//    quelconques. La création de la structure de données associée est confiée à
//    la fonction bst_empty
//  La structure de données ne stocke pas les objets mais des pointeurs vers ces
//    objets. Les pointeurs sont du type générique const void *
//  L'utilisateur doit garantir que l'adresse de chaque objet fournie aux
//    diverses fonctions est valide durant toute la durée de la présence de
//    l'objet dans l'ensemble. Si des opérations d'allocation dynamique sont
//    effectuées, elles le sont pour la gestion propre de la structure de
//    données, et en aucun cas pour réaliser de copies ou des destructions
//    d'objets
typedef struct bst bst;

//  Les fonctions qui suivent ont un comportement indéterminé si leur paramètre
//    ou l'un de leurs paramètres de type bst * n'est pas l'adresse d'un objet
//    préalablement renvoyé avec succès par bst_empty et non révoqué depuis par
//    bst_dispose. Cette règle ne souffre que d'une seule exception :
//    bst_dispose tolère que la déréférence de son argument ait pour valeur NULL

//  bst_empty : crée une structure de données correspondant initialement à
//    l'arbre binaire de recherche vide. La fonction de comparaison des valeurs
//    est compar. Renvoie NULL en cas de dépassement de capacité. Renvoie sinon
//    un pointeur sur l'objet qui gère la structure de données
extern bst *bst_empty(int (*compar)(const void *, const void *));

//  bst_dispose : si *tptr ne vaut pas NULL, libère les ressources allouées à la
//    structure de données associée à *tptr puis affecte à *tptr la valeur NULL
extern void bst_dispose(bst **tptr);

//  bst_add_endofpath : selon la méthode de l'ajout en bout de chemin. Recherche
//    dans l'arbre binaire de recherche associé à t une valeur égale à celle
//    d'adresse xptr au sens de compar. Si une telle valeur existe, cas 1),
//    l'arbre n'est pas modifié. Sinon, cas 2), la valeur d'adresse xptr est
//    ajoutée à l'arbre. Renvoie NULL si xptr vaut NULL ou en cas de dépassement
//    de capacité. Renvoie sinon l'adresse de la valeur trouvée dans le cas 1),
//    xptr dans le cas 2)
extern const void *bst_add_endofpath(bst *t, const void *xptr);

//  bst_remove_climbup_left : selon la méthode du retrait par remontée gauche.
//    Recherche dans l'arbre binaire de recherche associé à t une valeur égale à
//    celle d'adresse xptr au sens de compar. Si une telle valeur existe, la
//    retire de l'arbre. Renvoie NULL si xptr vaut NULL ou si une telle valeur
//    n'existe pas. Renvoie sinon l'adresse de la valeur trouvée
extern const void *bst_remove_climbup_left(bst *t, const void *xptr);

//  bst_search : recherche dans l'arbre binaire de recherche associé à t une
//    valeur égale à celle d'adresse xptr au sens de compar. Renvoie NULL si
//    xptr vaut NULL ou si une telle valeur n'existe pas. Renvoie sinon
//    l'adresse de la valeur trouvée
extern const void *bst_search(bst *t, const void *xptr);

//  bst_size : renvoie la taille de l'arbre binaire de recherche associé à t
extern size_t bst_size(bst *t);

//  bst_number, bst_rank : calcule le numéro ou le rang du nœud de l'arbre
//    binaire de recherche associé à t dont la valeur est égale à celle de xptr
//    au sens de compar. Renvoie (size_t) (-1) si xptr vaut NULL. Renvoie sinon
//    le numéro ou le rang du nœud si une telle valeur existe. Renvoie sinon le
//    numéro ou le rang qu'aurait le nœud si xptr était ajouté à l'arbre
extern size_t bst_number(bst *t, const void *xptr);
extern size_t bst_rank(bst *t, const void *xptr);

//  bst_repr_graphic : envoie une représentation de graphique de l'arbre binaire
//    de recherche associé à t sur la sortie standard. La fonction put est
//    utilisée pour envoyer sur la sortie standard chacune des valeurs dont les
//    adresses sont stockées dans l'arbre
extern void bst_repr_graphic(bst *t, void (*put)(const void *xptr));

//  bst_dft_infix_apply_context : parcourt l'arbre binaire de recherche associé
//    à t en profondeur, de manière infixe, de la gauche vers la droite si d
//    vaut 0, de la droite vers la gauche si d vaut 1. Pour chaque sous-arbre
//    non vide, exécute funcontext_pre(context) avant que de parcourir le
//    premier sous-arbre, puis fun(context, xptr) sur l'adresse stockée à la
//    racine, puis funcontext_post(context) après que d'avoir parcouru le second
//    sous-arbre. Si l'une des fonctions funcontext_pre, fun ou funcontext_post
//    renvoie une valeur non nulle, l'exécution prend fin et la fonction
//    bst_dft_infix_left_apply_context renvoie cette valeur. Sinon, la fonction
//    renvoie zéro. Il est permis que funcontext_pre et funcontext_post aient la
//    valeur NULL ; dans ce cas, aucune des exécutions correspondantes n'a lieu.
//    Renvoie -1 si d vaut autre chose que 0 ou 1
extern int bst_dft_infix_apply_context(bst *t, int d,
    void *context, int (*fun)(void *context, const void *xptr),
    int (*funcontext_pre)(void *context),
    int (*funcontext_post)(void *context));

#endif
