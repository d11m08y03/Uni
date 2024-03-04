#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// Exercise 2 - Reverses a digit 
int reverse(int num) {
  std::string numStr = std::to_string(num);
  std::size_t len = numStr.length();
  static std::size_t i = 0;

  if (i >= len / 2) return std::stoi(numStr);

  std::swap(numStr[i], numStr[len - i - 1]);
  i++;
  return reverse(std::stoi(numStr));
}

// Excercise 3a
std::vector<int> toBinary(int num) {
  static std::vector<int> bits;
  bits.push_back(num % 2 == 0 ? 0 : 1);

  if (num == 0) {
    std::reverse(bits.begin(), bits.end());
    return bits;
  }
  return toBinary(num / 2);
}

// Exercise 3b
int toDecimal(std::vector<int> bits) {
  static int num = 0, i = 0;
  if (i > bits.size()) return num;
  num += bits[i++] == 1 ? std::pow(2, bits.size() - i) : 0;
  return toDecimal(bits);
}

int main() {
  return 0;
}
