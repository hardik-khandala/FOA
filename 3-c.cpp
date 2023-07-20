#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, position,t ,i ,j;
    cout << "Enter number of random numbers: ";
    cin >> n;
  
    int array[n];
    srand(time(0));
    for(i=0;i<n;i++)
    {
        array[i] = rand()%10000 + 1;
    }

    clock_t start = clock();
    for(i=0;i<n-1;i++)
    {
        position = i;
        for(j=i+1;j<n;j++)
        {
            if(array[position]>array[j])
            {
                position=j;
            }
        }
        if(position!=i)
        {
            t = array[i];
            array[i]=array[position];
            array[position]=t;
        }
    }
    clock_t end = clock();
    cout<<"Sorted Array is: "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by the program is: " << fixed << time_taken << " seconds" << endl;
    return 0;
}
