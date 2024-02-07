#include <cstddef>
#include <cstdio>
#include <functional>
#include <iostream>
#include <bits/stdc++.h>

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
int counter(int arr[], size_t n) {
  std::function<int(int arr[], int key)> search;
  search = [&](int arr[], int key) {
    static int low = 0, high = n; 
    int middle = low + (high - low) / 2;

    if (low > high) return -1;
    if (key == arr[middle]) return middle;
    else if (key < arr[middle]) low = middle + 1;
    else if (key > arr[middle]) high = middle - 1;

    return search(arr, key);
  };

  static int count = 0;
  int foundAt = search(arr, 1);

  if (foundAt == -1) return count;

  arr[foundAt] = 0;
  std::sort(arr, arr + n, std::greater<int>());
  count++;
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
  int arr2[] = {1, 1, 1, 1, 0, 0, 0, 0};
  std::cout << counter(arr2, 7) << std::endl;
  return 0;
}
