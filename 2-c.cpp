#include<iostream>
using namespace std;

int main()
{
    int n, a=0, b=1,c=0;
    cout<<"Enter a number for Fibonacci series upto: ";
    cin>>n;
    
    cout<<a<<endl;
    cout<<b<<endl;

    while(a+b<=n)
    {
        c = a+b;
        cout<<c<<endl;
        a=b;
        b=c;
    }

    return 0;
}
