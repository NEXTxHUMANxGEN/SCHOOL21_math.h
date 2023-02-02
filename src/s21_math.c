#include "s21_math.h"

#include <math.h>
#include <stdio.h>

int main() {
  double exp = -3, base = -2, res = 0.0;
  if (base < 0) {
    res = s21_exp(exp * s21_log(-base));
    if (s21_fmod(exp, 3) == 0 && base < 0) {
      res = -res;
    }
  }

  printf("\ns21 : %f\n", res);
  // res = pow(base,exp);
  // printf("\nmath : %f\n", res);

  return 0;
}