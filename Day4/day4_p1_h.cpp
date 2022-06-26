#include <iostream>

using namespace std;

class arrayStack {
public:
    int* S;
    int capacity;
    int t;

    arrayStack(int capacity) {
        this->capacity = capacity;
        this->S = new int[capacity];
        this->t = -1;
    }

    int size() {
        return t + 1;
    }

    int empty() {
        if (t == -1)
            return 1;
        return 0;
    }

    int top() {
        if (t == -1)
            return -1;
        return S[t];
    }

    void push(int e) {
        t += 1;
        S[t] = e;
    }

    int pop() {
        if (t == -1)
            return -1;
        int return_data = S[t];
        t -= 1;
        return return_data;
    }

};


int main() {
    string s;
    int T, param;

    cin >> T;
    arrayStack* as = new arrayStack(10000);

    for (int i = 0; i < T; i++) {
        cin >> s;

        if (s == "size") {
            cout << as->size() << endl;
        }

        else if (s == "empty") {
            cout << as->empty() << endl;
        }

        else if (s == "top") {
            cout << as->top() << endl;
        }

        else if (s == "push") {
            cin >> param;
            as->push(param);
        }

        else if (s == "pop") {
            cout << as->pop() << endl;
        }
    }
}
