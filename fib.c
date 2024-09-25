#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long unlong;

unlong cache[102] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

extern unlong fib_r_core(int n);
extern unlong fib_i_core(int n);

unlong fib_i(int n) {
  if (cache[n] != -1) {
    return cache[n];
  }
  cache[n] = fib_i_core(n);
  return cache[n];
}

unlong fib_i_core(int n) {

  unlong num1 = 0;
  unlong num2 = 1;
  unlong sum = 1;
  if (n <= 1) {
    return 0;
  } else {
    for (int ix = 1; ix < n - 1; ++ix) {
      sum = num1 + num2;
      num1 = num2;
      num2 = sum;
    }
    return sum;
  }
}

unlong fib_r(unlong n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }

  if (cache[n] != -1) {
    return cache[n];
  }

  cache[n] = fib_r_core(n);

  return cache[n];
}
unlong fib_r_core(int n) {

  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }

  return fib_r(n - 1) + fib_r(n - 2);
}

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  if (argv[2] == "r") {
    printf("%lld", fib_r(n - 1));
  }
  if (argv[2]) {
    printf("%lld", fib_i(n));
  }

  return 0;
}
