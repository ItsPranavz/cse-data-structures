// Queue implementation with LL

class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

class Stack {
	Node *head;
    int size;
   public:
    Stack() {
        head=NULL;
        size=0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if(head==NULL) return true;
        else return false;
    }

    void push(int element) {
        
        Node *t= new Node(element);
        t->next=head;
        head=t;
        size++;
    }

    int pop() {
        if( isEmpty()) return -1;
        int ans=head->data;
        Node *t=head;
        head=head->next;
        delete t;
        size--;
        return ans;
    }

    int top() {
        if(isEmpty()) return -1;
        return head->data;
    }
};
