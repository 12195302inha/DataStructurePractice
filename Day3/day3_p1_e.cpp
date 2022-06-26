#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int e) {
        this->data = e;
        this->next = NULL;
    }
};

class SLinkedList {
public:
    Node* head;
    Node* tail;

    SLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addFront(int X) {
        if (empty())
            head = tail = new Node(X);
        else {
            Node* node = new Node(X);
            node->next = head;
            head = node;
        }
    }
    int removeFront() {
        if (empty())
            return -1;
        else {
            Node* old = head;
            int old_data = old->data;
            head = old->next;
            delete old;
            return old_data;
        }
    }
    int front() {
        if (head == NULL) return -1;
        else return head->data;
    }
    int empty() {
        if (head == NULL) return 1;
        else return 0;
    }
};

int main() {
    string s;
    int param, T;
    SLinkedList* sl = new SLinkedList();
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> s;
        if (s == "addFront") {
            cin >> param;
            sl->addFront(param);
        }

        else if (s == "removeFront") {
            cout << sl->removeFront() << endl;
        }

        else if (s == "front") {
            cout << sl->front() << endl;
        }

        else if (s == "empty") {
            cout << sl->empty() << endl;
        }
    }
    return 0;
}
