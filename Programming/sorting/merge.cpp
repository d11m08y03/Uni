#include <cstddef>
#include <cstdio>

void print_arr(int arr[], size_t n) {
  for (size_t i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

auto merge_sort(int arr[], size_t n) -> void {
  if (n <= 1) return;

  size_t middle = n / 2;
  int *left_arr = new int[middle];
  int *right_arr = new int[n - middle];

  auto merge = [&]() -> void {
    size_t i = 0, left = 0, right = 0;

    while (left < middle && right < n - middle) {
      if (left_arr[left] < right_arr[right]) {
        arr[i++] = left_arr[left++];
      } else {
        arr[i++] = right_arr[right++];
      }
    }

    while (left < middle) {
      arr[i++] = left_arr[left++];
    }

    while (right < n - middle) {
      arr[i++] = right_arr[right++];
    }
  };

  // Divide le shit
  size_t j = 0;
  for (size_t i = 0; i < n; i++) {
    if (i < middle) {
      left_arr[i] = arr[i];
    } else {
      right_arr[j++] = arr[i];
    }
  }

  printf("Left: ");
  print_arr(left_arr, middle);
  printf("Right: ");
  print_arr(right_arr, n - middle);

  merge_sort(left_arr, middle);
  merge_sort(right_arr, n - middle);
  merge();

  delete[] left_arr;
  delete[] right_arr;
}

auto main() -> int {
  int arr[] = {4, 3, 2, 1};
  size_t n = sizeof(arr) / sizeof(arr[0]);
  merge_sort(arr, n);

  printf("\n");
  print_arr(arr, n);


  return 0;
}
