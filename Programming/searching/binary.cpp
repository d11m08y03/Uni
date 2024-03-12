#include <cstddef>
#include <cstdio>

void iterativeBinary(int arr[], size_t n, int key) {
  int low = 0, high = n - 1;

  while (low <= high) {
    int middle = (low + high) / 2;
    if (arr[middle] == key) {
      printf("Found at index %d\n", middle);
      return;
    } else if (key > arr[middle]) {
      low = middle + 1;
    } else {
      high = middle - 1;
      printf("%d\n", high);
    }
  }

  printf("Not found in array\n");
}

void recursiveBinary(int arr[], size_t n, int key) {
  static size_t low = 0, high = n - 1;
  size_t middle = (low + high) / 2;

  if (low > high) {
    printf("Not found in array\n");
    return;
  }

  if (key == arr[middle]) {
    printf("Found at index %zu\n", middle);
    return;
  } else if (key > arr[middle]) {
    low = middle + 1;
  } else {
    high = middle - 1;
  }

  return recursiveBinary(arr, n, key);
}

int main() {
  int arr[] = {1, 2, 3, 3, 4};
  // recursiveBinary(arr, 5, 0);
  iterativeBinary(arr, 5, 0);
  return 0;
}
