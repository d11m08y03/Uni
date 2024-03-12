#include "output.cpp"

#include <cstddef>
#include <utility>
#include <vector>

void iterativeInsertion(std::vector<int>& arr) {
  for (size_t i = 0; i < arr.size(); i++) {
    size_t j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      std::swap(arr[j - 1], arr[j]);
      j--;
    }
  }
  printArray(arr);
}

void recursiveInsertion(std::vector<int>& arr, size_t n) {
  if (n <= 1) return;

  recursiveInsertion(arr, n - 1);

  int last = arr[n - 1];
  size_t j = n - 2;

  while (j >= 0 && arr[j] > last) {
    arr[j + 1] = arr[j];
    j--;
  }
  arr[j + 1] = last;
}


int main() {
  std::vector<int> arr = {4, 3, 2, 1};
  // iterativeInsertion(arr);
  recursiveInsertion(arr, arr.size());
  printArray(arr);
  return 0;
}
