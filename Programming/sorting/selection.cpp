#include <cstddef>
#include <vector>
#include "output.cpp"

void iterativeSelection(std::vector<int>& arr) {
  size_t minIdx = 0;
  for (size_t i = 0; i < arr.size() - 1; i++) {
    minIdx = i;
    for (size_t j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[minIdx]) minIdx = j;
    }
    if (minIdx != i) std::swap(arr[i], arr[minIdx]);
  }
}

void recursiveSelection(std::vector<int>& arr) {
  static size_t i = 0;
  static size_t minIdx = i;

  if (i >= arr.size() - 1) return;
  minIdx = i;

  for (size_t j = 0; j < arr.size(); j++) {
    if (arr[j] < arr[minIdx]) minIdx = j;
  }

  if (minIdx != i) std::swap(arr[i], arr[minIdx]);
  i++;

  return recursiveSelection(arr);
}

int main() {
  std::vector<int> arr = {4, 3, 2, 1};
  iterativeSelection(arr);
  // recursiveSelection(arr);
  printArray(arr);
  return 0;
}
