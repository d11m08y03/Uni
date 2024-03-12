#include "./output.cpp"
#include <cstddef>
#include <utility>
#include <vector>

void iterativeBubble(std::vector<int>& arr) {
  for(size_t i = 0; i < arr.size(); i++) {
    bool swapped = false;
    for (size_t j = 0; j < arr.size() - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }

  printArray(arr);
}

void recursiveBubble(std::vector<int>& arr, size_t n) {
  if (n <= 1) return;

  bool swapped = false;
  for (size_t i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);
        swapped = true;
    }
  }

  if (!swapped) return;

  return recursiveBubble(arr, n);
}

int main() {
  std::vector<int> arr = {4, 3, 2, 1};
  recursiveBubble(arr, true);
  iterativeBubble(arr);
  printArray(arr);
  return 0;
}
