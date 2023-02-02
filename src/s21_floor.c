#include <math.h>
#include <stdio.h>

long double s21_floor(double x) {
  long double res = (long double)x;
  if (x < 0) {
    res = (long long int)x;
    res = (long double)(res)-1;
  } else if (x > 0) {
    res = (long long int)x;
    res = (long double)res;
  } else {
    res = 0.0;
  }
  return res;
}

int main() {
  double res = s21_floor(6666666666.6666666);
  printf("\ns21_floor = %f\n", res);
  printf("\nfloor = %f\n", floor(6666666666.6666666));

  return 0;
}