#include<bits/stdc++.h>
using namespace std;

int findMaxMin(int arr[], int low, int high, int& maxVal, int& minVal) {
  if (low == high) {
    maxVal = minVal = arr[low];
    return 0;
  }

  int mid = low + (high - low) / 2;

  findMaxMin(arr, low, mid, maxVal, minVal);

  int leftMax = maxVal;
  int leftMin = minVal;

  findMaxMin(arr, mid + 1, high, maxVal, minVal);

  maxVal = max(leftMax, maxVal);
  minVal = min(leftMin, minVal);

  return 0;
}

int main() {
  int arr[] = {5, 1, 4, 2, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  int maxVal, minVal;

  findMaxMin(arr, 0, n - 1, maxVal, minVal);

  cout << "Maximum element: " << maxVal << endl;
  cout << "Minimum element: " << minVal << endl;

  return 0;
}
