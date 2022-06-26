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

class CircularLinkedList {
public:
    Node* head;
    Node* tail;

    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }

    int empty() {
        if (head == NULL) return 1;
        else return 0;
    }

    void addBack(int X) {
        if (empty())
            head = tail = new Node(X);
        else {
            Node* node = new Node(X);
            tail->next = node;
            tail = node;
            tail->next = head;
        }
    }

    void showList() {
        Node* current = head;
        if (!current) {
            cout << -1 << endl;
            return;
        }
        while (current != tail) {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << current->data << endl;
    }

    void deleteJump(int jump) {
        Node* current = head;
        for (int i = 0; i < jump; i++) {
            current = current->next;
        }

        Node* prev = head;
        while (prev->next != current) {
            prev = prev->next;
        }

        if (current == head) {
            head = current->next;
        }
        else if (current == tail) {
            tail = prev;
        }

        prev->next = current->next;
        delete current;
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
