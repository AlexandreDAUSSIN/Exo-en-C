#include <ctype.h>
#include "nat_io.h"

#define ZERO '0'
#define SUCC 's'
#define PRED 'p'

//  input_leadingspaces : lecture sur le flot contrôlé par l'objet pointé par
//    stream d'une suite éventuellement vide de caractères d'espacement. La
//    lecture prend fin dès qu'une erreur survient ou qu'un caractère qui
//    n'appartient pas à la catégorie des caractères d'espacement est rencontré.
//    La fonction renvoie EOF dans le premier cas, la valeur renvoyée par la
//    réinjection du caractère dans le second cas
static int input_leadingspaces(FILE *stream);

//  input_body : même spécification que input mais en supposant que les
//    éventuels caractères d'espacement initiaux ont été lus
static int input_body(FILE *stream, nat *ptr);

int input(FILE *stream, nat *ptr) {
  *ptr = invalid();
  if (input_leadingspaces(stream) == EOF) {
    return EOF;
  }
  return input_body(stream, ptr);
}

int input_leadingspaces(FILE *stream) {
  int c = fgetc(stream);
  if (c == EOF) {
    return EOF;
  }
  if (!isspace(c)) {
    return ungetc(c, stream);
  }
  return input_leadingspaces(stream);
}

int input_body(FILE *stream, nat *ptr) {
  int c = fgetc(stream);
  if (c == EOF) {
    return 0;
  }
  if (c == ZERO) {
    *ptr = zero();
    return 1;
  }
  if (!(c == SUCC || c == PRED)) {
    return 0;
  }
  int r = input_body(stream, ptr);
  if (r <= 0) {
    return r;
  }
  *ptr = (c == SUCC ? succ : pred)(*ptr);
  return !is_invalid(*ptr);
}

//  output_body : même spécification que output mais en supposant que x est
//    valide
static int output_body(FILE *stream, nat x);

int output(FILE *stream, nat x) {
  if (is_invalid(x)) {
    fputs("INVALID", stream);
    return EOF;
  }
  return output_body(stream, x);
}

int output_body(FILE *stream, nat x) {
  if (is_zero(x)) {
    return fputc(ZERO, stream);
  }
  int r = fputc(SUCC, stream);
  if (r == EOF) {
    return EOF;
  }
  return output_body(stream, pred(x));
}

//  outpout_body : même spécification que outpout mais en supposant que x est
//    valide
static int outpout_body(FILE *stream, bool x);

int outpout(FILE *stream, bool x) {
  return outpout_body(stream, x);
}

int outpout_body(FILE *stream, bool x) {
  int r = fputc(SUCC, stream);
  if (r == EOF) {
    return EOF;
  }
  return outpout_body(stream, x);
}
