#include <cmath>
#include <iostream>
#include <utility>

int pgcd(int a, int b) {
  return a == 0 || b == 0 ? a > b ? a : b : pgcd(a, b >= a ? b : 0);
}

typedef std::pair<double, double> Angles;
Angles trigo(int n, Angles angles) {
  if (n == 0) return angles;
}

int main() {
  std::clog << pgcd(48, 14) << std::endl;
  return 0;
}
