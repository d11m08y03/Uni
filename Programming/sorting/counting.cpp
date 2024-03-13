#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <vector>

auto counting(int arr[], size_t size) -> void {
  int max_element = *std::max_element(arr, arr + size - 1);
  std::vector<int> counting_arr(max_element + 1, 0);

  for (size_t i = 0; i < size; i++) {
    counting_arr[arr[i]]++;
  }

  // Counting number of occurences for element 
  for (size_t i = 1; i < max_element + 1; i++) {
    counting_arr[i] += counting_arr[i - 1];
  }

  int* output = new int[size];
  for (int i = size - 1; i >= 0; i--) {
    output[--counting_arr[arr[i]]] = arr[i];
  }

  for (size_t i = 0; i < size; i++) {
    printf("%d, ", output[i]);
  }
  printf("\n");

  delete[] output;
}

int main() {
  int arr[] = {3, 2, 1, 1, 0};
  counting(arr, 5);
  
  return 0;
}
