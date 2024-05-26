#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int size = 10000;
    int arr[size];
    
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }

    clock_t start_bubble = clock();
    bubbleSort(arr, size);
    clock_t end_bubble = clock();

    clock_t start_quick = clock();
    quickSort(arr, 0, size - 1);
    clock_t end_quick = clock();

    double time_bubble = double(end_bubble - start_bubble) / CLOCKS_PER_SEC;
    double time_quick = double(end_quick - start_quick) / CLOCKS_PER_SEC;

    cout << "Time taken by Bubble Sort: " << time_bubble << " seconds" << endl;
    cout << "Time taken by Quick Sort: " << time_quick << " seconds" << endl;

    return 0;
}
