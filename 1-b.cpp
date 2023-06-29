#include <iostream>
using namespace std;
#define SIZE 5

int a[SIZE], top = -1;

void push()
{
    cout << endl;
    int data;
    if (top == SIZE - 1)
    {
        cout << "Stack Overflow!!";
    }
    else
    {
        cout << "Enter the number: ";
        cin >> data;
        top++;
        a[top] = data;
    }
}
void pop()
{
    cout << endl;
    if (top == -1)
    {
        cout << "Stack is empty!!" << endl;
    }
    else
    {
        cout << "Deleted number is " << a[top] << endl;
        top--;
    }
}
void display()
{
    cout << endl;
    int i;
    if (top >= 0)
    {
        cout << "Stack is: " << endl;
        for (i = top; i >= 0; i--)
        {
            cout << a[i] << endl;
        }
    }
    else
    {
        cout << "Stack is empty!!" << endl;
    }
}
int main()
{
    cout << "Stack Operation using Array!!" << endl;
    int ch;
    cout << endl;
    cout << "1.Push" << endl;
    cout << "2.Pop" << endl;
    cout << "3.Display" << endl;
    cout << "4.Exit" << endl;
    while (1)
    {
        cout << endl;
        cout << "Enter a choise: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            exit(0);
        }
        default:
            cout << "Invalid Choise!!";
        }
    }
    return 0;
}
