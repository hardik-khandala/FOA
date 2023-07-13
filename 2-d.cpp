#include<iostream>
using namespace std;

void fibonacci_recursive(int a, int b, int n) {
    if (a > n) {
        return;
    }
    cout << a << endl;
    fibonacci_recursive(b, a + b, n);
}

int main() {
    int n;
    cout << "Enter a number for the Fibonacci series up to: ";
    cin >> n;

    cout << "Fibonacci Series:" << endl;

    fibonacci_recursive(0, 1, n);

    return 0;
}
