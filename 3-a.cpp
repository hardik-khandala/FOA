#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of random numbers: ";
    cin >> n;

    int array[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 100000 + 1;
    }

    clock_t start = clock();
    for (int i = 1; i < n; i++)
    {
        int current = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > current)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
    clock_t end = clock();

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by the program is: " << fixed << time_taken << " seconds" << endl;

    return 0;
}
