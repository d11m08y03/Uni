#include <iostream>
#include <utility>

int pgcd(int a, int b) {
  return a == 0 || b == 0 ? a > b ? a : b : pgcd(a, b >= a ? b - a : 0);
}

typedef std::pair<double, double> Angles;
Angles trigo(int n, Angles angles) {
  if (n == 1)
    return angles;

  if (n == 0)
    return std::make_pair(0.0, 0.0);
}

int main() {
  Angles result = trigo(5, std::make_pair(0.866, 0.5));
  std::clog << result.first << ' ' << result.second << '\n';

  return 0;
}
