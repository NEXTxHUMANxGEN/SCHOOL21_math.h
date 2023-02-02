long double s21_fabs(double x) {
  long double res = x;
  if (x == s21_INF || x == -s21_INF) {
    res = s21_INF;
  } else if (x != x) {
    res = s21_NAN;
  } else if (x < 0) {
    res = -(res);
  } else if (x == 0.0) {
    res = 0.0;
  }
  return res;
}
