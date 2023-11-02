// Binary Search Tree implementation in C++

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

class binarySearchTree {
public:
    Node* root;
    binarySearchTree() {
        root = NULL;
    }

    void insert(int data) {
        root = insertHelper(root, data);
    }

    Node* insertHelper(Node* root, int data) {
        if (root == NULL) {
            root = new Node(data);
            return root;
        }
        if (data < root->data) {
            root->left = insertHelper(root->left, data);
        }
        else if (data > root->data) {
            root->right = insertHelper(root->right, data);
        }
        return root;
    }

    void display() {
        displayHelper(root);
    }

    void displayHelper(Node* root) {
        if (root != NULL) {
            displayHelper(root->left);
            cout << root->data << " ";
            displayHelper(root->right);
        }
    }

    void search(int data) {
        if (searchHelper(root, data)) {
            cout << data << " is present in the tree." << endl;
        }
        else {
            cout << data << " is not present in the tree." << endl;
        }
    }

    bool searchHelper(Node* root, int data) {
        if (root == NULL) {
            return false;
        }
        if (root->data == data) {
            return true;
        }
        else if (data < root->data) {
            return searchHelper(root->left, data);
        }
        else {
            return searchHelper(root->right, data);
        }
    }

    void deleteNode(int data) {
        root = deleteHelper(root, data);
    }

    Node* deleteHelper(Node* root, int data) {
        if (root == NULL) {
            return root;
        }
        if (data < root->data) {
            root->left = deleteHelper(root->left, data);
        }
        else if (data > root->data) {
            root->right = deleteHelper(root->right, data);
        }
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteHelper(root->right, temp->data);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }
};

int main() {
    binarySearchTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Original tree: ";
    tree.display();
    cout << endl;

    tree.deleteNode(20);
    cout << "Tree after deleting 20: ";
    tree.display();
    cout << endl;

    tree.deleteNode(30);
    cout << "Tree after deleting 30: ";
    tree.display();
    cout << endl;

    tree.deleteNode(50);
    cout << "Tree after deleting 50: ";
    tree.display();
    cout << endl;

    tree.search(60);
    tree.search(100);

    return 0;
}

