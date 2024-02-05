#include <iostream>
#include <vector>

int binarySearch(int key, std::vector<int> arr) {
  static int low = 0, high = arr.size();
  int middle = (high + low) / 2;

  if (low > high) return -1;
  if (key == arr[middle]) return middle;
  else if (key > arr[middle]) low = middle + 1;
  else if (key < arr[middle]) high = middle - 1;

  return binarySearch(key,  arr);
}

int main() {
  int r = binarySearch(2, {1, 2, 3, 4});
  std::clog << r << '\n';
  return 0;
}
