#include <stdio.h>
#include <string.h>
#include "point.h"
#include "sg.h"
#include "fractal.h"

#define QUIT  'q'

#define FUN_FAILURE -1
#define FUN_SUCCESS 0

#define TITLE_ORDER " / order = "

//  ndigits : renvoie le nombre de chiffres de n dans son écriture en base base,
//    en supposant n >= 0 et base >= 2
static size_t ndigits(int n, int base) {
  if (n < base) {
    return 1;
  }
  return ndigits(n / base, base);
}

//  set_title : efface la fenêtre, affiche le titre title avec affichage de
//    l'ordre n, en supposant n >= 0
static void make_title(const char *title, int n) {
  sg_clear();
  char s[strlen(title) + strlen(TITLE_ORDER) + ndigits(n, 10) + 1];
  sprintf(s, "%s%s%d", title, TITLE_ORDER, n);
  sg_set_title(s);
}

//  graduate_color : fixe la couleur de premier plan entre le vert et le marron
//    proportionnellement à k, en supposant 0 <= k <= n et n >= 1
static void graduate_color(int k, int n) {
  sg_set_fgcolor(
      COLOR((int) (RGBMAX * (double) k / n), RGBMAX / 2, RGBMAX / 4));
}

//--- Carrés emboités ----------------------------------------------------------

#define SHIFT 5.0

 // r_fitted_4 : produit l'emboité d'ordre n du quadrilatère de sommets pa, pb,
   // pc et pd avec rotation droite de proportion 1 / (SHIFT + 1)
static void r_fitted_4(int n, point pa, point pb, point pc, point pd) {
  if (n < 0) {
    return;
  }
  draw_line(pa, pb);
  draw_line(pb, pc);
  draw_line(pc, pd);
  draw_line(pd, pa);
  if (n == 0) {
    return;
  }
  r_fitted_4(n - 1,
      barycenter(pa, SHIFT, pb, 1.0),
      barycenter(pb, SHIFT, pc, 1.0),
      barycenter(pc, SHIFT, pd, 1.0),
      barycenter(pd, SHIFT, pa, 1.0));
}

int fitted_squares(unsigned int size, int n) {
  unsigned int d = size / 10;
  for (int k = 0; k <= n; ++k) {
    make_title("Fitted squares", k);
    graduate_color(k, n);
    r_fitted_4(k,
        (point) { d, d },
        (point) { size - d, d },
        (point) { size - d, size - d },
        (point) { d, size - d });
    if (sg_get_key() == QUIT) {
      return FUN_FAILURE;
    }
  }
  return FUN_SUCCESS;
}

static void s_tri_3(int n, point pa, point pb, point pc){
  if (n < 0) {
    return;
  }
  draw_line(pa, pb);
  draw_line(pb, pc);
  draw_line(pc, pa);
  if (n == 0) {
    return;
  }
  point pd = barycenter(pa, 1.0, pb, 1.0);
  point pe = barycenter(pb, 1.0, pc, 1.0);
  point pf = barycenter(pc, 1.0, pa, 1.0);
  s_tri_3(n - 1, pa, pd, pf);
  s_tri_3(n - 1, pd, pb, pe);
  s_tri_3(n - 1, pf, pe, pc);
}


int sierp_tri(unsigned int size, int n) {
  unsigned int d = size / 10;
  for (int k = 0; k <= n; ++k) {
    make_title("Sierpinski's triangle", k);
    graduate_color(k, n);
    point a = {d, size - d};
    point b = {size - d, size - d};
    point c = equilateral_triangle(b, a);
    s_tri_3(k, a, b, c);
    if (sg_get_key() == QUIT) {
      return FUN_FAILURE;
    }
  }
  return FUN_SUCCESS;
}

// static void s_carpet_2(int n, point pa, point pb) {
  // if (n < 0) {
    // return;
  // }
  // point c = right_angle_triangle(pb, pa);
  // point d = right_angle_triangle(pa, pb);
  // draw_line(c, pa); 
  // draw_line(d, pb);
  // draw_line(c, pb);
  // draw_line(d, pa);
  // if (n == 0) {
    // return;
  // }
  // s_carpet_2(n - 1,
      // barycenter(pa, 2.0, c, 1.0),
      // barycenter(pa, 2.0, d, 1.0));
  // s_carpet_2(n - 1,
      // barycenter(pa, 2.0, c, 1.0),
      // barycenter(pa, 1.0, c, 2.0));
// }

// int sierp_carpet(unsigned int size, int n) {
  // unsigned int d = size / 10;
  // for (int k = 0; k <= n; ++k) {
    // make_title("Sierpinski's carpet", k);
    // graduate_color(k, n);
    // s_carpet_2(k,
        // (point) { d, d },
        // (point) { size - d, size - d });
    // if (sg_get_key() == QUIT) {
      // return FUN_FAILURE;
    // }
  // }
  // return FUN_SUCCESS;
// }

