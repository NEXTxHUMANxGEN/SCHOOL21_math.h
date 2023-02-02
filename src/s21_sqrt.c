long double s21_sqrt(double x) {
  long double root = x / 2;
  double eps = 0.000001;
  int iter = 0;
  if (x == 0) {
    root = 0.0;
  } else if (x < 0) {
    root = s21_NAN;
  } else {
    while (root - x / root > eps) {
      iter++;
      root = 0.5 * (root + x / root);
    }
  }
  return root;
}