#include <cmath>
#include <cstddef>
#include <cstdio>

auto jumpy(int arr[], size_t n, int key) -> void {
  size_t block = sqrt(n); // :)
  size_t prev = 0;

  while (arr[block] <= key && block < n) {
    prev = block;
    block += sqrt(n);
    if (block > n - 1) {
      printf("Not found\n");
    }
  }

  for (size_t i = prev; i < block; i++) {
    if (arr[i] == key) {
      printf("Found\n");
      return;
    }
  }

  printf("Not found\n");
  return;
}

auto main() -> int {
  int arr[] = {1, 2, 3, 4, 5, 6};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  jumpy(arr, n, 3);

  return 0;
}
