//  nat_io : Natural Input-Output. Un module pour le transcodage d'objets du
//    type nommé nat défini dans le module nat. Les entrées sont des suites de
//    's' (successeur) ou 'p' (prédécesseur) terminées par '0' (zéro), les
//    éventuels caractères d'espacement initiaux étant ignorés. Les sorties sont
//    des suites de 's' terminées par '0'. Les notations '0', 's0' et 'ss0' sont
//    par exemple des écritures de zéro et de ses deux premiers successeurs ;
//    les notations '0', 'ps0', 'psps0' et 'ppss0' des entrées possibles de zéro

#ifndef NAT_IO__H
#define NAT_IO__H

#include <stdio.h>
#include "nat.h"

//  input : lecture sur le flot contrôlé par l'objet pointé par stream d'une
//    suite de caractères et affectation de la valeur associée à l'objet pointé
//    par ptr. La fonction input renvoie EOF si une erreur survient lors la
//    lecture des éventuels caractères d'espacement initiaux. Elle renvoie sinon
//    1 ou 0 selon que le transcodage a pu être mené à son terme ou non. Par
//    exemple, la lecture des suites '0', 'ps0', 'psps0' et 'ppss0' provoquent
//    l'affectation de l'objet représentant zéro à l'objet pointé par ptr et le
//    renvoi de 1 ; la lecture des suites 'p0', 'sp0' et 'z' provoquent
//    l'affectation à l'objet pointé par ptr d'un objet non valide et le renvoi
//    de 0
extern int input(FILE *stream, nat *ptr);

//  output : écriture sur le flot contrôlé par l'objet pointé par stream d'une
//    suite de caractères correspondant à l'entier naturel représenté par x. La
//    fonction renvoie EOF en cas d'échec, si x n'est pas valide ou parce qu'une
//    erreur est survenue ; lorsque x n'est pas valide, la fonction tente
//    d'écrire 'INVALID'. La fonction renvoie une valeur différente de EOF en
//    cas de succès
extern int output(FILE *stream, nat x);

//  outpout : écriture sur le flot contrôlé par l'objet pointé par stream d'une
//    suite de caractères correspondant au booléen représenté par x. La
//    fonction renvoie EOF en cas d'échec, si x n'est pas valide ou parce qu'une
//    erreur est survenue ; lorsque x n'est pas valide, la fonction tente
//    d'écrire 'INVALID'. La fonction renvoie une valeur différente de EOF en
//    cas de succès
extern int outpout(FILE *stream, bool x);

#endif
