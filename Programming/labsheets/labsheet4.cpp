#include <cstddef>
#include <cstdio>
#include <utility>

void printArray(int arr[], size_t n) {
  for (size_t i = 0; i < n; i++) {
    printf("Index: %zu, Value: %d\n", i, arr[i]);
  }
}

// Exercise 1 - Recursive bubble sort
void recursiveBubble(int arr[], size_t n) {
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

// Exercise 2 - Insertion sort
void insertion(int arr[], size_t n) {
  for (size_t i = 0; i < n; i++) {
    size_t j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      std::swap(arr[j - 1], arr[j]);
      j--;
    }
  }
}

// Exercise 3 - Recursive insertion sort
void recursiveInsertion(int arr[], size_t n) {
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

// Exercise 4 - Selection sort
void selection(int arr[], size_t n) {
  size_t minIdx = 0;
  for (size_t i = 0; i < n - 1; i++) {
    minIdx = i;
    for (size_t j = i + 1; j < n; j++) {
      if (arr[j] > arr[minIdx]) minIdx = j;
    }
    if (minIdx != i) std::swap(arr[i], arr[minIdx]);
  }
}

void recursiveSelection(int arr[], int n) {
  if (n <= 1) return;

  int max_idx = 0;
  for (int i = 1; i < n; ++i) {
    if (arr[i] > arr[max_idx])
      max_idx = i;
  }

  std::swap(arr[max_idx], arr[n - 1]);
  recursiveSelection(arr, n - 1);
}

int main() {
  int arr[] = {-1, 2, 8, 0, 3, 4, 2, 9, 7, 5};
  size_t n = 10;

  printf("Array after sort: \n");
  recursiveSelection(arr, n);
  printArray(arr, n);
  
  return 0;
}
