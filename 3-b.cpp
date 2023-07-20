#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of random numbers: ";
    cin >> n;
  
    int array[n];
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        array[i] = rand()%100000 + 1;
    }
    clock_t start = clock();
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                int swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }
    }
    clock_t end = clock();
    cout<<"Sorted Array is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by the program is: " << fixed << time_taken << " seconds" << endl;
    
    return 0;
}
