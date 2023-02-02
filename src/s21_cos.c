#ifndef s21_fabs
#define s21_fabs
#include "s21_fabs.c"
#endif

#ifndef s21_fmod
#define s21_fmod
#include "s21_fmod.c"
#endif

long double s21_cos(double x) {
  long double result = 0;
  if (x != x || x == s21_INF || x == -s21_INF) {
    result = s21_NAN;
  } else {
    if (s21_fabs(x) > 2 * s21_PI) {
      x = s21_fmod(x, 2 * s21_PI);
    }
    long double t = 1, sum = 1;
    int i = 0;
    while (s21_fabs(t / sum) > s21_EPS) {
      i++;
      t = (-t * x * x) / ((2 * i - 1) * (2 * i));
      sum += t;
    }
    result = sum;
  }
  return result;
}