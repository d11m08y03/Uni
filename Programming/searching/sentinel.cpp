#include <cstddef>
#include <cstdio>

auto iterative_sentinel(int arr[], size_t n, int key) -> void {
  int last_element = arr[n - 1];
  arr[n - 1] = key;
  size_t i = 0;

  while (arr[i] != key)
    i++;

  arr[n - 1] = last_element;
  i < n - 1 || arr[n - 1] == key ? printf("Found\n") : printf("Not found\n");
}

auto main() -> int {
  int arr[] = {1, 2, 3, 4, 5, 6};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  iterative_sentinel(arr, n, 6);

  return 0;
}
