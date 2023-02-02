#ifndef S21_MATH
#define S21_MATH
#include <stdio.h>
#include <stdlib.h>
#define s21_INF 1.0 / 0.0
#define s21_E 2.718281828459045
#define s21_EXP 2.71828182845904523536
#define s21_NAN 0.0 / 0.0
#define s21_EPS 1e-17
#define s21_DBL_MAX 1.79769313486231570814527423731704357e+308L
#define s21_PI 3.14159265358979323846

long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
int s21_abs(int x);
long double s21_ceil(double x);
#endif