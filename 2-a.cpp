#include<iostream>
using namespace std;

int fact(int n)
{
    int factorial = 1;
    for(int i=1;i<=n;i++)
    {
        factorial = factorial * i ;
    }
    return factorial;
}
int main() 
{
    int n;
    cout<<"Enter number: ";
    cin>>n;

    int result = fact(n);

    cout<<"Factorial is "<<result;

    return 0;
}
