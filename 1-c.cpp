#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

template <typename T>
class QueueUsingStacks
{
private:
    stack<T> stack1;
    stack<T> stack2;

public:
    void enqueue(T item)
    {
        stack1.push(item);
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty. Cannot dequeue element.");
        }

        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        T front = stack2.top();
        stack2.pop();
        return front;
    }

    T peek()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty. Cannot peek element.");
        }

        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();
    }

    bool isEmpty()
    {
        return stack1.empty() && stack2.empty();
    }

    int size()
    {
        return stack1.size() + stack2.size();
    }
};

int main()
{
    QueueUsingStacks<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Size of the queue: " << queue.size() << endl;

    int frontElement = queue.peek();
    cout << "Front element: " << frontElement << endl;

    while (!queue.isEmpty())
    {
        int element = queue.dequeue();
        cout << "Dequeued element: " << element << endl;
    }

    cout << "Size of the queue after dequeuing: " << queue.size() << endl;

    return 0;
}
