//
// Created by 심준열 on 2022/06/27.
//

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class SLinkedList{
public:
    Node* head;
    Node* tail;

    SLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addFront(int x) {
        Node* node = new Node(x);
        if (empty()) {
            head = tail = node;
        }
        else {
            node->next = head;
            head = node;
        }
    }

    int removeFront() {
        if (empty()) {
            return -1;
        }

        else {
            Node* old = head;
            int old_data = old->data;
            head = head->next;
            delete old;
            return old_data;
        }
    }

    int front() {
        return head->data;
    }

    bool empty() {
        return head == NULL;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    string s;

    SLinkedList* sl = new SLinkedList();
    for (int i=0; i<T; i++){
        cin >> s;
        if (s == "add"){
            int p;
            cin >> p;
            sl->addFront(p);
        }

        else if (s == "remove"){
            cout << sl->removeFront() << endl;
        }

        else if (s == "front") {
            cout << sl->front() << endl;
        }

        else if (s == "empty") {
            cout << sl->empty() << endl;
        }
    }
}