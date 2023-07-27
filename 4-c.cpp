#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (x > array[mid])
            low = mid + 1;
        else if (x < array[mid])
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int array[n];
    cout << "Enter the elements of the array in ascending order: ";
    for (int i = 0; i < n; i++)
        cin >> array[i];

    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;

    int result = binarySearch(array, x, 0, n - 1);
    if (result == -1)
        cout << "Not found";
    else
        cout << "Element is found at index " << result + 1;
    
    return 0;
}
