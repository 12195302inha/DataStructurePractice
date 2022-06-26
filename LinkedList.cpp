#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int e) {
        this->data = e;
        this->next = nullptr;
    };
};

class SLinkedList {
public:
    Node* head;
    Node* tail;

    SLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    bool empty(){
        return head == nullptr;
    };
    int front(){
        return head->data;
    };
    void showList(){
        Node* next_node = head;
        while (next_node){
            cout << next_node->data << ' ';
            next_node = next_node->next;
        }
        cout << '\n';
    };
    void addFront(int X){
        Node* node = new Node(X);
        if (empty())
            head = tail = node;
        else {
            node->next = head;
            head = node;
        }
    };
    void addBack(int X){
        Node* node = new Node(X);
        if (empty())
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    };
    int deleteFront(){
        if (empty())
            return -1;
        Node* old = head;
        int return_data = old->data;
        head = old->next;
        delete old;
        return return_data;
    };
    int deleteBack(){
        if (empty())
            return -1;
        Node* old = tail;
        int return_data = old->data;
        Node* current = head;
        while(current->next != tail)
            current = current->next;
        current->next = nullptr;
        tail = current;
        delete old;
        return return_data;
    };
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    SLinkedList* ll = new SLinkedList();
    ll->addFront(0);
    ll->addFront(1);
    ll->addBack(2);
    ll->addBack(3);
    ll->showList();
    cout << ll->deleteBack() << '\n';
    ll->showList();
}