#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of random numbers: ";
    cin >> n;

    int array[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100000 + 1;
    }

    clock_t start = clock();
    quickSort(array, 0, n - 1);
    clock_t end = clock();

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by the program is: " << fixed << time_taken << " seconds" << endl;

    return 0;
}
