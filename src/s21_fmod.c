#ifndef s21_fabs
#define s21_fabs
#include "s21_fabs.c"
#endif

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (x == s21_NAN || y == s21_NAN || y == 0 || x == s21_INF ||
      s21_fabs(y) < 0 || (x == s21_INF && y == s21_INF)) {
    res = s21_NAN;
  } else if (y == s21_INF) {
    res = x;
  } else {
    res = x - ((long long int)(x / y)) * y;
    // long double res = num_x/num_y - (int)(num_x/num_y);
  }
  return res;
}