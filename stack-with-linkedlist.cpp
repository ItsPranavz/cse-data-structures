// Stack using linked list

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = NULL; }
    void push(int x);
    int pop();
    void display();
};

void Stack::push(int x) {
    Node* temp = new Node;
    if (temp == NULL) {
        cout << "Stack overflow" << endl;
        return;
    }
    temp->data = x;
    temp->next = top;
    top = temp;
}

int Stack::pop() {
    int x = -1;
    if (top == NULL) {
        cout << "Stack underflow" << endl;
        return x;
    }
    Node* temp = top;
    x = temp->data;
    top = top->next;
    delete temp;
    return x;
}

void Stack::display() {
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << s.pop() << endl;
    s.display();
    return 0;
}