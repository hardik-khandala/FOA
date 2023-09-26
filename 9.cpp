#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    int data;
    Node* next;
};

class FiniteAutomata {
public:
    FiniteAutomata(string pattern) {
        this->pattern = pattern;
        this->start_state = new Node(0);
        this->current_state = this->start_state;

        for (int i = 0; i < pattern.length(); i++) {
            Node* new_state = new Node(i + 1);
            this->current_state->next = new_state;
            this->current_state = new_state;
        }
        this->current_state->next = this->start_state;
    }

    bool match(string text) {
        for (char c : text) {
            if (this->pattern.find(c) == string::npos) {
                return false;
            }

            this->current_state = this->current_state->next;
            if (this->current_state == this->start_state) {
                return true;
            }
        }
        return false;
    }

private:
    string pattern;
    Node* start_state;
    Node* current_state;
};

int main() {
    string pattern, text;

    cout << "Enter the pattern: ";
    cin >> pattern;

    cout << "Enter the text: ";
    cin >> text;

    FiniteAutomata finite_automata(pattern);
    bool result = finite_automata.match(text);

    if (result) {
        cout << "String matched" << endl;
    } else {
        cout << "String not matched" << endl;
    }

    return 0;
}
