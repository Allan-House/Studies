/*
 * Binary Search
 * 
 * Searches for an element in a sorted array by repeatedly dividing
 * the search space in half.
 * 
 * Complexity: O(log n)
 * Precondition: Array must be sorted in ascending order
*/

#include <stdio.h>

/**
 * Performs binary search on a sorted array
 * 
 * @param arr Sorted array of integers
 * @param n Array size
 * @param x Value to search for
 * @return Index of element if found, -1 otherwise
 */
int binary_search(int arr[], int n, int x) {
  if (n < 0) {
    printf("Error: Invalid size\n");
    return -1;
  }

  if (n == 0) {
    printf("Warning: Empty array\n");
    return -1;
  }

  int low = 0;
  int high = n - 1;
  
  // Continue while there are elements to check
  while (low <= high) {
    // Calculate middle index (avoids overflow)
    int mid = low + (high - low) / 2;

    if (x == arr[mid]) {
      return mid;
    }

    if (x < arr[mid]) {
      high = mid - 1;
    }
    else if (x > arr[mid]) {
      low = mid + 1;
    }
  }
  
  return -1;
}

int main() {
  int arr[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  size_t n = sizeof(arr) / sizeof(arr[0]);
  
  int tests[] = {3, 10, -5, 0, 5};
  int num_tests = sizeof(tests) / sizeof(tests[0]);
  
  printf("Array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");
  
  for (int i = 0; i < num_tests; i++) {
    int x = tests[i];
    int result = binary_search(arr, n, x);
    
    if (result != -1) {
      printf("Value %d found at index %d\n", x, result);
    } else {
      printf("Value %d not found\n", x);
    }
  }

  return 0;
}
