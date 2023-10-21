// Queue using linked list

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class Queue {
	private:
		Node* front;
		Node* rear;
	public:
		Queue() {
			front = NULL;
			rear = NULL;
		}

		bool isEmpty() {
			return (front == NULL && rear == NULL);
		}

		void enqueue(int x) {
			Node* newNode = new Node;
			newNode->data = x;
			newNode->next = NULL;
			if (isEmpty()) {
				front = rear = newNode;
			} else {
				rear->next = newNode;
				rear = newNode;
			}
		}

		void dequeue() {
			if (isEmpty()) {
				cout << "Queue is empty" << endl;
			} else if (front == rear) {
				Node* temp = front;
				front = rear = NULL;
				delete temp;
			} else {
				Node* temp = front;
				front = front->next;
				delete temp;
			}
		}

		int getFront() {
			if (isEmpty()) {
				cout << "Queue is empty" << endl;
				return -1;
			} else {
				return front->data;
			}
		}

		int getRear() {
			if (isEmpty()) {
				cout << "Queue is empty" << endl;
				return -1;
			} else {
				return rear->data;
			}
		}

		void print() {
			if (isEmpty()) {
				cout << "Queue is empty" << endl;
			} else {
				Node* temp = front;
				while (temp != NULL) {
					cout << temp->data << " ";
					temp = temp->next;
				}
				cout << endl;
			}
		}
};

int main() {
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.print();
	q.dequeue();
	q.print();
	cout << "Front element: " << q.getFront() << endl;
	cout << "Rear element: " << q.getRear() << endl;
	return 0;
}