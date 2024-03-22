
#include <cstdio>
#include <utility>
int main() {
  int arr[] = {1, 2, 3};
  std::swap(arr[1], arr[1]);

  for (int i = 0; i < 3; i++) {
    printf("%d\n", arr[i]);
  }
  
  return 0;
}
