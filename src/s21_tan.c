#ifndef s21_sin
#define s21_sin
#include "s21_sin.c"
#endif

#ifndef s21_cos
#define s21_cos
#include "s21_cos.c"
#endif

long double s21_tan(double x) {
  long double result = s21_sin(x) / s21_cos(x);
  return result;
}