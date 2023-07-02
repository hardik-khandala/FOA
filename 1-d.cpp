#include <iostream>
#include <queue>
#include <stdexcept>

using namespace std;

class StackUsingQueues {
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    void push(int item) {
        queue2.push(item);

        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        queue<int> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
    }

    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty. Cannot pop element.");
        }

        int topElement = queue1.front();
        queue1.pop();
        return topElement;
    }

    int peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty. Cannot peek element.");
        }

        return queue1.front();
    }

    bool isEmpty() {
        return queue1.empty();
    }

    int size() {
        return queue1.size();
    }
};

int main() {
    StackUsingQueues stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Size of the stack: " << stack.size() << endl;

    int topElement = stack.peek();
    cout << "Top element: " << topElement << endl;

    int poppedElement = stack.pop();
    cout << "Popped element: " << poppedElement << endl;

    stack.push(40);

    cout << "Size of the stack after pushing: " << stack.size() << endl;

    int newTopElement = stack.peek();
    cout << "Top element after pushing: " << newTopElement << endl;

    while (!stack.isEmpty()) {
        int element = stack.pop();
        cout << "Popped element: " << element << endl;
    }

    cout << "Size of the stack after popping all elements: " << stack.size() << endl;

    return 0;
}
