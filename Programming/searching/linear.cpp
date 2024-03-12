#include <cstddef>
#include <cstdio>

void iterativeLinear(int arr[], size_t n, int key) {
  for (size_t i = 0; i < n; i++) {
    if (key == arr[i]) {
      printf("Found at index %zu\n", i);
      return;
    }
  }

  printf("Not found in array");
}
