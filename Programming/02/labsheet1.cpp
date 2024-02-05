#include <cstdio>
#include <functional>
#include <iostream>

// Exercise 1
int pgcd(int a, int b) {
  return a == 0 || b == 0 ? a > b ? a : b : pgcd(a, b >= a ? b - a : 0);
}

// Exercise 2
int sum(int n, int x) {
  std::function<int(int, int)> p;
  p = [&](int n, int x) -> int {
    return n == 0 ? 1 : (x / n) * p(n - 1, x);
  };

  return n == 0 ? : sum(n - 1, x) + p(n, x);
}

// Exercise 3
// typedef std::pair<double, double> Angles;
// Angles trigo(int n, Angles angles) {
//   if (n == 1)
//     return angles;

//   if (n == 0)
//     return std::make_pair(0.0, 0.0);
// }

int main() {
  int num1 = 5, num2 = 6;
  std::clog << "GCD of " << num1 << " and " << num2 << ":" << pgcd(num1, num2) << std::endl;

  int n = 3, x = 4;
  printf("S(%d, %d) = %d\n", n, x, sum(n, x));

  return 0;
}
