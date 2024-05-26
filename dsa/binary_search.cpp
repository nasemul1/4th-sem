#include <iostream>

using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
  if (low > high) {
    return -1;
  }

  int mid = low + (high - low) / 2;

  if (arr[mid] == target) {
    return mid;
  } else if (arr[mid] < target) {
    return binarySearch(arr, mid + 1, high, target);
  } else {
    return binarySearch(arr, low, mid - 1, target);
  }
}

int main() {
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 10;

  int result = binarySearch(arr, 0, n - 1, target);

  if (result == -1) {
    cout << target << " is not present in the array" << endl;
  } else {
    cout << target << " is present at index " << result << endl;
  }

  return 0;
}
