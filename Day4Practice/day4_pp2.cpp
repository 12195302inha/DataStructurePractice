//
// Created by 심준열 on 2022/06/27.
//

#include <iostream>

using namespace std;

class Stack{
public:
    int* S;
    int t;

    Stack(){
        S = new int[10000];
        t = -1;
    }

    void push(int x) {
        t += 1;
        S[t] = x;
    }
    int pop() {
        int data = S[t];
        t -= 1;
        return data;
    }
    int top() {
        return S[t];
    }
};

int cal_post(string s) {
    int n = s.size();
    Stack* st = new Stack();
    char temp;

    for (int i = 0; i < n; i++) {
        temp = s.at(i);

        if (temp == '+'){
            st->push(st->pop() + st->pop()) ;
        }

        else if (temp == '-') {
            int p1 = st->pop();
            int p2 = st->pop();
            st->push(p2 - p1);
        }

        else if (temp == '*') {
            st->push(st->pop() * st->pop());
        }

        else {
            st->push(temp - '0');
        }
    }
    return st->top();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;

    for (int i=0; i<T; i++) {
        string s;
        cin >> s;
        cout << cal_post(s) << endl;
    }
}