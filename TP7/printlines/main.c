#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

//==============================================================================
#if 0

#define UCHAR_MAX = 100;

int main(void) {
  long int n = 0;
  int c;
  stack *t = malloc(sizeof UCHAR_MAX);
  
  while ((c = getchar()) != EOF) {
    ++n;
    printf("%ld\t", n);
    while (c != EOF && c != '\n') {
      stack_push(t, c);
      c = getchar();
    }
    while (!stack_is_empty(t) ){
      c = (int) ((char *) stack_pop(t) - t)
      putchar(c);
    }
    putchar('\n');
  }
  return EXIT_SUCCESS;
}

//==============================================================================
#else

#define UCHAR_MAX = 100;
int main(void) {
  long int n = 0;
  int c;
  int a;
  stack *t1 = malloc(sizeof UCHAR_MAX);
  stack *t2 = malloc(sizeof UCHAR_MAX);
  
  while ((c = getchar()) != EOF) {
    ++n;
    printf("%ld\t", n);
    while (c != EOF && c != '\n') {
      if (c == '#'){
        free(stack_top(t1));
      }else if (c == '@'){
        free (t1);
      }
      stack_push(t1, c);
      c = getchar();
    }
    while (!stack_is_empty(t1)){
      stack_move(t2, t1);
      c = (int) ((char *) stack_pop(t2) - t2);
      putchar(c);
    }
    putchar('\n');
  }
  free(t);
  return EXIT_SUCCESS;

//==============================================================================
}

#endif

