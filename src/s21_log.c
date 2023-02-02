#ifndef s21_exp
#define s21_exp
#include "s21_exp.c"
#endif

long double s21_log(double x) {
  int ex_pow = 0;
  long double res = 0;
  long double comp = 0;
  if (x < 0 || x != x) res = s21_NAN;
  if (x != 0 && x != s21_NAN && x != s21_INF) {
    for (; x >= s21_EXP; x /= s21_EXP) {
      ex_pow++;
    }
    for (int i = 0; i < 100; i++) {
      comp = res;
      res = comp + 2 * (x - s21_exp(comp)) / (x + s21_exp(comp));
    }
    res = res + ex_pow;
  } else if (x == s21_INF) {
    res = s21_INF;
  } else {
    res = -s21_INF;
  }
  return res;
}