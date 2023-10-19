// Queue implementation of queue

class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

class Queue {
	Node *head;
	Node *tail;
	int size;
   public:
    Queue() {
		head=NULL;
		tail=NULL;
		size=0;
	}

	int getSize() {
		return size;
	}

    bool isEmpty() {
		if(head==NULL) return true;
		else return false;
	
	}

    void enqueue(int data) {
		Node *a=new Node(data);
		if(head==NULL){
			head=a;
			tail=a;
			tail->next=NULL;
			size++;
		}
		else{
			tail->next=a;
			a->next=NULL;
			tail=a;
			size++;
		}
	}

    int dequeue() {
       if(isEmpty()) return -1;
	   size--;
	   Node *t=head;
	   head=head->next;
	   int d= t->data;
	   t->next=NULL;
	   delete t;
	   return d;
    }

    int front() {
		if(isEmpty()) return -1;
        return head->data;
    }
};
