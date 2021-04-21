#ifndef STR_REC__H
#define STR_REC__H

#include <stddef.h>

//  str_chr, str_pbrk, str_rchr et str_spn possèdent les mêmes spécifications
//    que les fonctions strchr, strpbrk, strrchr et strspn déclarées dans
//    l'en-tête <string.h> de la bibliothèque standard
extern char *str_chr(const char *s, int c);
extern char *str_pbrk(const char *s1, const char *s2);
extern char *str_rchr(const char *s, int c);
extern size_t str_spn(const char *s1, const char *s2);

#endif
