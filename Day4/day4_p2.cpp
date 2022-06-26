#include <iostream>
#include <string>

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

int calPostfix(string exp) {
    arrayStack S = arrayStack(10);
    string postfix = exp;
    int n = postfix.size();
    char testch;

    for (int i = 0; i < n; i++) {
        testch = exp.at(i);
        if (testch == '+') {
            S.push(S.pop() + S.pop());
        }

        else if (testch == '-') {
            int p1 = S.pop();
            int p2 = S.pop();
            S.push(p2 - p1);
        }

        else if (testch == '*') {
            S.push(S.pop() * S.pop());
        }

        else {
            S.push((int)(testch - '0'));
        }
    }
    return S.top();
}


int main() {
    string s;
    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> s;
        cout << calPostfix(s) << endl;
    }
}
