#include <iostream>
using namespace std;

int main()
{
    int search, i, n;
    cout << "Enter number of elements in array: ";
    cin >> n;

  int array[n];
    cout << "Enter " << n << " integer(s): ";
    for (i = 0; i < n; i++)
        cin >> array[i];
    cout << "Enter a number to search: ";
    cin >> search;

    for (i = 0; i < n; i++)
    {
        if (array[i] == search)
        {
            cout << search << " is present at location " << i + 1 << ".\n";
            break;
        }
    }
    if (i == n)
        cout << search << " isn't present in the array.\n";
    return 0;
}
