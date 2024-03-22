#include <iostream>
#include <vector>

template <typename T>
void printArray(std::vector<T> arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << "Index: " << i << " " << arr[i] << std::endl;
  }
}
