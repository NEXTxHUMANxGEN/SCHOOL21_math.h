
#include "s21_math.h"

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

long double s21_floor(double x) {
  long double res = x;
  if (x < 0) {
    res = (long long int)x;
    res = (long double)res - 1;
  } else if (x > 0) {
    res = (long long int)x;
    res = (long double)res;
  } else {
    res = 0.0;
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (x == s21_NAN || y == s21_NAN || y == 0 || x == s21_INF ||
      s21_fabs(y) < 0 || (x == s21_INF && y == s21_INF)) {
    res = s21_NAN;
  } else {
    res = x - ((long long int)(x / y)) * y;
  }
  return res;
}

long double s21_exp(double x) {
  long double res = 1;
  int flag_of_end = 0;
  if (x == -s21_INF || x == s21_INF) {
    res = 0;
  } else if (x != x) {
    res = s21_NAN;
  } else if (x == 0.0) {
    res = 1;
  } else if (x < 0) {
    res = 1 / s21_exp(-x);
  } else {
    long double rest = 1;
    int i = 1;
    while (rest > s21_EPS && !(flag_of_end)) {
      rest = rest * (x / i);
      i++;
      res += rest;
      if (res > s21_DBL_MAX) {
        res = s21_INF;
        flag_of_end = 1;
      }
      rest = s21_fabs((double)rest);
    }
  }
  return res;
}

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

long double s21_pow(double base, double exp) {
  long double res = 1;
  // if (base < 0){
  //   // base = -base;
  // }
  if (base != base || exp != exp) {
    res = s21_NAN;
  } else if (exp < 0 && base == 0) {
    res = s21_INF;
  } else if (exp == -s21_INF) {
    res = 0;
  } else if (exp == s21_INF) {
    if (base == -1 || base == 1) {
      res = 1;
    } else if (base < 1 && base > -1) {
      res = 0;
    } else {
      res = s21_INF;
    }
  } else if (exp == 0) {
    res = 1;
  } else {
    if (base < 0) {
      res = s21_exp(exp * s21_log(-base));
    } else {
      res = s21_exp(exp * s21_log(base));
    }
    if (s21_fmod(exp, 3) == 0 && base < 0) {
      res = -res;
    }
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res = 1.0;
  if (x < 0) {
    res = s21_NAN;
  } else {
    res = s21_exp(s21_log(x) / 2);
  }
  return res;
}

long double s21_sin(double x) {
  long double res = 0;
  if (x != x || x == s21_INF || x == -s21_INF) {
    res = s21_NAN;
  } else {
    if (s21_fabs(x) > 2 * s21_PI) {
      x = s21_fmod(x, 2 * s21_PI);
    }
    long double t = x, sum = t;
    int i = 1;
    while (s21_fabs(t / sum) > s21_EPS) {
      i = i + 2;
      t = (-t * x * x) / ((i * (i - 1)));
      sum += t;
    }
    res = sum;
  }
  return res;
}

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

long double s21_tan(double x) {
  long double result = s21_sin(x) / s21_cos(x);
  return result;
}

long double s21_atan(double x) {
  int sta = 0, sp = 0;
  long double x2, a;
  if (x < 0.F) {
    x = -x;
    sta |= 1;
  }
  if (x > 1.F) {
    x = 1.F / x;
    sta |= 2;
  }
  while (x > s21_PI / 12.F) {
    sp++;
    a = x + s21_sqrt(3);
    a = 1.F / a;
    x *= s21_sqrt(3);
    x -= 1.F;
    x *= a;
  }
  x2 = x * x;
  a = x2 + 1.4087812F;
  a = 0.55913709F / a;
  a += 0.60310579F;
  a -= 0.05160454F * x2;
  a *= x;
  while (sp > 0) {
    a += (s21_PI / 6.F);
    sp--;
  }
  if (sta & 2) {
    a = (s21_PI / 2.F) - a;
  }
  if (sta & 1) {
    a = -a;
  }
  return (a);
}

long double s21_asin(double x) {
  long double res = 1.0;
  if (x < -1 || x > 1) {
    res = s21_NAN;
  } else if (x == 1 || x == -1) {
    res = s21_PI / 2 * x;
  } else {
    res = s21_atan(s21_sqrt(x * x / (1 - x * x)));
  }
  if (x < 0 && res > 0) {
    res = -res;
  }
  return res;
}

long double s21_acos(double x) {
  long double res = 1.0;
  res = s21_PI / 2 - s21_asin(x);
  return res;
}

int s21_abs(int x) {
  int res = x;
  if (x == s21_INF || x == -s21_INF) {
    res = s21_INF;
  } else if (x < 0) {
    res = -(res);
  } else if (x == 0) {
    res = 0;
  }
  return res;
}

long double s21_ceil(double x) {
  long double res = x;
  if (x < 0) {
    res = (long long int)x;
    res = (long double)res;
  } else if (x > 0) {
    res = (long long int)x;
    res = (long double)res + 1;
  } else {
    res = 0.0;
  }
  return res;
}

// int main () {
//   double res = 0.0;
// //   res = s21_fabs(222.22);
// //   printf("\n%f\n",res);
// //   res = s21_floor(22.22);
// //   printf("\n%f\n",res);
// //   res = s21_fmod(331.1, 2.4);
// //   printf("\n%f\n",res);
// //   res = s21_exp(52.2);
// //   printf("\n%f\n",res);
// //   res = s21_log(60);
// //   printf("\n%f\n",res);
// //   res = s21_pow(23.2, 1.6);
// //   printf("\n%f\n",res);
// //   res = s21_sqrt(96.0);
// //   printf("\n%f\n",res);
// //   res = s21_sin(60);
// //   printf("\n%f\n",res);
// //   res = s21_cos(60);
// //   printf("\n%f\n",res);
//   res = s21_atan(60);
//   printf("\ns21_ : %f\n",res);
//   res = atan(60);
//   printf("\n%f\n",res);
//   res = s21_asin(-0.777777);
//   printf("\ns21_ : %f\n",res);
//   res = asin(-0.777777);
//   printf("\n%f\n",res);
//     res = s21_acos(0.5);
//   printf("\ns21_ : %f\n",res);
//   res = acos(0.5);
//   printf("\n%f\n",res);
//   return 0;
// }