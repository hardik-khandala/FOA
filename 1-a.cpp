#include <iostream>
using namespace std;
#define SIZE 5

int rear = -1, front = -1;
int a[SIZE];

void insert()
{
    int x;
    if (rear == SIZE - 1)
    {
        cout << "Queue Overflow!!" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        cout << "Enter the number: ";
        cin >> x;
        rear = rear + 1;
        a[rear] = x;
    }
}
void dequeue()
{
    cout << endl;
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow!!" << endl;
        return;
    }
    else
    {
        cout << "Deleted number is " << a[front] << endl;
        front = front + 1;
    }
}
void display()
{
    cout << endl;
    int i;
    if (front == -1)
    {
        cout << "Queue is empty!!" << endl;
    }
    else
    {
        cout << "Queue is:" << endl;
        for (i = front; i <= rear; i++)
        {
            cout << a[i] << endl;
        }
    }
}
int main()
{
    cout << "Queue Operation using Array!!" << endl;
    while (1)
    {
        int ch;
        cout << endl;
        cout << "1.Insertion" << endl;
        cout << "2.Deletion" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter a choise: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid Choise!!" << endl;
            break;
        }
    }
    return 0;
}
