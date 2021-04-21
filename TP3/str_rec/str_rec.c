#include "str_rec.h"

char *str_chr(const char *s, int c){
  
  if (s == NULL || *s == '\0'){
    return NULL;
  }
  if (c == *s){
    return (char *) s;
  }
  return str_chr(s + 1, c);
}

char *str_pbrk(const char *s1, const char *s2){
  
  if (*s1 == '\0' || *s2 == '\0' || s1 == NULL || s2 == NULL){
    return NULL;
  }
  if (*s1 == *s2){
    return (char *) s1;
  }
  str_chr(s1, *s2);
  return str_pbrk(s1 + 1, s2);
}

//char *str_rchr(const char *s, int c){
  
  //if (c == *s){
    //const char *k = (char *)s;
  //}
  //if (*s == '\0'){
    //return k;
  //}
  //return str_rchr(s + 1, c);
//}

size_t str_spn(const char *s1, const char *s2){
  if (*s1 == '\0'){
    return 0;
  }
  if (str_chr(s1, *s2) == NULL){
    return 0;
  }
  return 1 + str_spn(s1 + 1, s2);
}

