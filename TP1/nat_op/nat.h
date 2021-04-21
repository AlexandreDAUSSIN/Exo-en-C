//  nat : Natural. Un module basique sur les entiers naturels, ou, pour être
//    exact, sur un intervalle fini de ceux-ci contenant zéro. Les entiers
//    naturels dudit intervalle sont représentés par des objets du type nommé
//    nat. Tout élément de l'intervalle est qualifié de valide. De même tout
//    représentant d'un élément de l'intervalle. Les autres naturels et les
//    autres objets du type nommé nat ne sont pas valides. Le nombre d'éléments
//    appartenant à l'intervalle dépend de l'implantation. Au moins un objet du
//    type nommé nat n'est pas valide. Deux implantations sont définies : l'une
//    de portée réduite à quelques éléments, l'autre, beaucoup plus conséquente.
//    La première est l'implantation par défaut ; elle peut être précisée à la
//    compilation au moyen de l'option -DNATMODEL=LOW. L'option -DNATMODEL=HIGH
//    sélectionne la seconde

#ifndef NAT__H
#define NAT__H

#include <stdbool.h>

//  définition du (nom de) type nat
typedef const void *nat;

//  zero : renvoie l'objet valide du type nat représentant zéro
extern nat zero(void);

//  invalid : renvoie un objet du type nat non valide
extern nat invalid(void);

//  succ : si l'argument x n'est pas valide ou alors si l'implantation ne
//    possède pas de représentant pour le successeur du naturel associé à x,
//    renvoie un objet du type nat non valide. Sinon, renvoie l'objet valide du
//    type nat représentant pour le successeur du naturel associé à x
extern nat succ(nat x);

//  pred : si l'argument x n'est pas valide ou alors si x représente zéro,
//    renvoie un objet du type nat non valide. Sinon, renvoie l'objet valide du
//    type nat représentant pour le prédécesseur du naturel associé à x
extern nat pred(nat x);

//  is_zero : renvoie true si x représente zéro, false sinon
extern bool is_zero(nat x);

//  is_invalid : renvoie true si x n'est pas valide, false sinon
extern bool is_invalid(nat x);

#endif
