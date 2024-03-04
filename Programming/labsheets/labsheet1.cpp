#include <cstdio>
#include <functional>
#include <utility>

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
typedef std::pair<double, double> Angles;
Angles trigo(int n, Angles angles) {
  if (n == 1) return angles;
  if (n == 0) return std::make_pair(1.0, 0.0);

  Angles temp = trigo(n - 1, angles);
  return std::make_pair(
    temp.first * angles.first - angles.second * temp.second,
    temp.second * angles.first + angles.second * temp.first
  );
}

int main() {
  // Angles 180
  Angles testCase1 = std::make_pair(-1.0, 0);
  Angles testCase2 = std::make_pair(0.866, 0.5);

  Angles result0 = trigo(0, testCase1);
  printf("Called with 0: %f, %f\n", result0.first, result0.second);
  Angles result1 = trigo(1, testCase1);
  printf("Called with 1: %f, %f\n", result1.first, result1.second);
  Angles result2 = trigo(9, testCase2);
  printf("Called with 9: %f, %f\n", result2.first, result2.second);

  return 0;
}
