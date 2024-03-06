#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <utility>

// Question 1 - Frequency
void frequency(int arr[], size_t n) {
  auto insertionSort = [](int arr[], size_t n) {
    for (size_t i = 0; i < n; i++) {
      size_t j = i;
      while (j > 0 && arr[j - 1] > arr[j]) {
        std::swap(arr[j - 1], arr[j]);
        j--;
      }
    }
  };
  insertionSort(arr, n);

  int arr2d[n][2];
  size_t arr2dIndex = 0;

  for (size_t i = 0; i < n; i++) {
    int count = 1;
    for (size_t j = i; j < n; j++) {
      if (arr[j + 1] == arr[i]) {
        count++;
      }
    }
    arr2d[arr2dIndex][0] = arr[i];
    arr2d[arr2dIndex++][1] = count;
  }

  for (size_t i = 0; i < n; i++) {
    bool swapped = false;
    for (size_t j = i; j < n - i - 1; j++) {
      if (arr2d[j][1] > arr2d[j + 1][1]) {
        std::swap(arr2d[j][1], arr2d[j + 1][1]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }

  for (size_t i = 0; i < n; i++) {
    printf("Frequency: %d, Value: %d\n", arr2d[i][1], arr2d[i][0]);
  }

}

// Question 2 - 0s, 1s and 2s
void ranges(int arr[], size_t n) {
  size_t low = 0, mid = 0, high = n - 1;
  size_t i = 1;

  // size_t low = 1, mid = 1, high = n;
  // size_t i = 0;

  while (mid < high && i < n) {
    switch (arr[i]) {
      case 0:
        std::swap(arr[i], arr[low++]);
        mid++;
        break;

      case 1:
        mid++;
        break;

      case 2:
        std::swap(arr[i--], arr[high--]);
        break;

      default:
        break;
    }
    i++;
  }

  for (size_t i = 0; i < n; i++) {
    printf("%d, ", arr[i]);
    printf("\n");
  }
}

// Question 3 - Wave array 
void wave(int arr[], size_t n) {
  auto insertionSort = [](int arr[], size_t n) {
    for (size_t i = 0; i < n; i++) {
      size_t j = i;
      while (j > 0 && arr[j - 1] > arr[j]) {
        std::swap(arr[j - 1], arr[j]);
        j--;
      }
    }
  };
  insertionSort(arr, n);

  for (size_t i = 0; i < n - 1; i += 2) {
    std::swap(arr[i], arr[i + 1]);
  }

  for (size_t i = 0; i < n; i++) {
    printf("Index: %zu, Value: %d\n", i, arr[i]);
  }
}

int main() {
  int arr[] = {4, 4, 2, 1, 0};
  int arr2[] = {1, 2, 0, 0, 1};
  // wave(arr, 5);
  // frequency(arr, 5);
  ranges(arr2, 5);
  
  return 0;
}
