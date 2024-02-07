#include <cstddef>
#include <cstdio>

// Question 1
void reseat(int arr[], size_t n) {
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n; j++) {
      if (arr[i] == arr[j]) {
        printf("Index: %zu, Value: %d\n", i, arr[i]);
        return;
      }
    }
  }
}

// Question 2
void counter(int arr[], size_t n) {
  static int low = 0;
  static int high = n;
  static int count = 0;
  int middle = (low + high) / 2;

  if (low >= high) {
    printf("Count %d\n", count);
    return;
  }

  if (arr[middle] == 1) { 
    count++;
    arr[middle] = -1;
  } else {
    high = middle - 1;
  }

  return counter(arr, n); 
}

// Question 3 
int pairSum(int arr[], int n) {
  int highest = 0, secondHighest = 0;

  if (arr[0] > arr[1]) {
    highest = arr[0];
    secondHighest = arr[1];
  } else { 
    highest = arr[0]; 
    secondHighest = arr[1]; 
  }

  for (int i = 3; i < n; i++) {
    if (arr[i] > highest && arr[i] > secondHighest) {
      highest = arr[i];
    } else if (arr[i] > secondHighest && arr[i] < highest) {
      secondHighest = arr[i];
    }
  }

  return highest + secondHighest;
}

// Question 4
void pairDiff(int arr[], int n, int num) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i] > arr[j] && arr[i] - arr[j] == num) {
        printf("Pair found: %d, %d\n", arr[i], arr[j]);
        return;
      }
    }
  }
  printf("Pair not found.\n");
}

int main() {
  int arr[] = {5, 20, 3, 2, 50, 80};
  pairDiff(arr, 6, 78);
  return 0;
}
