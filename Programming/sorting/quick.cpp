#include <cstdio>
#include <utility>

auto quickie(int arr[], int low, int high) -> void {
  auto partition = [](int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high; j++) {
      if (arr[j] < pivot) {
        i++;
        std::swap(arr[i], arr[j]);
      }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
  };

  if (low >= high) return;

  int pi = partition(arr, low, high);
  quickie(arr, low, pi - 1);
  quickie(arr, pi + 1, high);
}

auto main() -> int {
  int arr[] = {4, 3, 2, 1};
  quickie(arr, 0, 4 - 1);
  for (int i = 0; i < 4; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

