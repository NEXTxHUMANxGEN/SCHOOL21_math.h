#ifndef s21_fabs
#define s21_fabs
#include "s21_fabs.c"
#endif

#ifndef s21_exp
#define s21_exp
#include "s21_exp.c"
#endif

#ifndef s21_log
#define s21_log
#include "s21_log.c"
#endif

long double s21_pow(double base, double exp) {
  double res = 1;
  double i = 1;
  if (base != base || exp != exp) res = s21_NAN;
  if (exp != 0) {
    res = base;
    while (i < s21_fabs(exp)) {
      res *= base;
      i++;
    }
  }
  if (exp < 0) {
    res = 1 / res;
  }
  if ((int)exp != exp) {
    res = s21_exp(exp * s21_log(base));
  }
  return res;
}