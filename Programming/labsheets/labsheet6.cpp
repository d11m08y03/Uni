#include <cstddef>
#include <cstdio>
#include <functional>
#include <utility>

// Question 1 - Iterative quick sort
void iterQuickie(int arr[], size_t n) {
  for (size_t i = n - 1; i > -1; i--) {
    int pivot = arr[i];
    for (size_t j = i - 1; j < -1; j--) {
      if (arr[j] > pivot) {
        std::swap(arr[i], arr[j]);
      }
    }
  }
}

// Question 3 - Binary insertion sort
void binsertion(int arr[], size_t n) {
  std::function<int(int, int[], size_t)> binarySearch;
  binarySearch = [&](int key, int arr[], size_t n) {
    static int low = 0, high = n;
    int middle = (high + low) / 2;

    if (low > high) return -1;
    if (key == arr[middle]) return middle;
    else if (key > arr[middle]) low = middle + 1;
    else if (key < arr[middle]) high = middle - 1;

    return binarySearch(key, arr, n);
  };

  for (size_t i = 1; i < n; ++i) {
    size_t j = i - 1;
    int key = arr[i];
    int location = binarySearch(key, arr, n);

    while (j >= location) {
      arr[j + 1] = arr[j--];
    }
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {4, 3, 2, 1};

  binsertion(arr, 4);
  for (size_t i = 0; i < 4; i++) {
    printf("%d\n", arr[i]);
  }
  
  return 0;
}
