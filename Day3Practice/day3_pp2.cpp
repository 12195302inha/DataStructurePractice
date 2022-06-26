//
// Created by 심준열 on 2022/06/27.
//

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

class CircularLinkedList{
public:
    Node* head;
    Node* tail;

    CircularLinkedList() {
        head = tail = NULL;
    }

    bool empty() {
        return head == NULL;
    }

    void addBack(int x) {
        if (empty())
            head = tail = new Node(x);
        else {
            Node* node = new Node(x);
            tail->next = node;
            tail = node;
            tail->next = head;
        }
    }

    void deleteJump(int k) {
        Node* current = head;
        for (int i=0; i<k; i++) {
            current = current->next;
        }

        Node* next = current->next;
        Node* prev = head;
        while (prev->next != current)
            prev = prev->next;



        if (current == head) {
            head = current->next;
        }
        else if (current == tail) {
            tail = prev;
        }

        prev->next = next;
        delete current;
    }

    void showList() {
        Node* current = head;
        while(current != tail){
            cout << current->data << " ";
            current = current->next;
        }
        cout << current->data << endl;
    }
};

int main() {
    string s;
    int param, T;
    cin >> T;

    int temp;

    for (int i = 0; i < T; i++) {
        CircularLinkedList* cl = new CircularLinkedList();
        for (int j = 0; j < 10; j++) {
            cin >> temp;
            cl->addBack(temp);
        }

        for (int j = 0; j < 3; j++) {
            cin >> s;
            if (s == "Delete") {
                cin >> param;
                cl->deleteJump(param);
            }
        }
        cl->showList();
    }
    return 0;
}