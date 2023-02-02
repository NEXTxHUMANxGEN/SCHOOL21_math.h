#ifndef s21_fabs
#define s21_fabs
#include "s21_fabs.c"
#endif

long double s21_exp(double x) {
  long double result = 1;
  int flag_of_end = 0;
  if (x == s21_INF) {
    result = x;
  } else if (x == -s21_INF || x == s21_INF) {
    result = 0;
  } else if (x != x) {
    result = s21_NAN;
  } else if (x == 0.0) {
    result = 1;
  } else if (x < 0) {
    result = 1 / s21_exp(-x);
  } else {
    long double rest = 1;
    int i = 1;
    while (rest > s21_EPS && !(flag_of_end)) {
      rest = rest * (x / i);
      i++;
      result += rest;
      if (result > s21_DBL_MAX) {
        result = s21_INF;
        flag_of_end = 1;
      }
      rest = s21_fabs((double)rest);
    }
  }
  return result;
}