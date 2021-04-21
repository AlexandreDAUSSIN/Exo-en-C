//  nat_op : Natural Operations. Un module de calcul sur les objets du type
//    nommé nat défini dans le module nat

#ifndef NAT_OP__H
#define NAT_OP__H

#include "nat.h"

//  sum, dist, min, max : renvoient la somme, la distance, le minimum, le
//    maximum, des deux arguments. Renvoient un objet non valide si l'un des
//    deux arguments n'est pas valide. La fonction sum renvoie un objet non
//    valide en cas de dépassement de capacité
extern nat sum(nat x, nat y);
extern nat dist(nat x, nat y);
extern nat min(nat x, nat y);
extern nat max(nat x, nat y);

//  is_eq, is_neq, is_leq, is_lth, is_geq, is_gth : renvoient true ou false
//    selon que le premier argument est égal, différent, inférieur ou égal,
//    strictement inférieur, supérieur ou égal, strictement supérieur, au
//    deuxième argument ou non. Renvoient false si l'un des deux arguments n'est
//    pas valide
extern bool is_eq(nat x, nat y);
extern bool is_neq(nat x, nat y);
extern bool is_leq(nat x, nat y);
extern bool is_lth(nat x, nat y);
extern bool is_geq(nat x, nat y);
extern bool is_gth(nat x, nat y);

#endif
