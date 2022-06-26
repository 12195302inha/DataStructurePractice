#include <iostream>

using namespace std;

string s;
int i, X;
int n = 0;
int int_array[10000] = {0, };

void at() {
    cin >> i;
    cout << int_array[i] << '\n';
}

void set() {
    cin >> i >> X;
    if (int_array[i] == 0) {
        cout << 0 << '\n';
    }
    else {
        int_array[i] = X;
    }
}

void add() {
    cin >> i >> X;
    if (int_array[i] == 0) {
        int_array[n] = X;
    }
    else {
        for (int t=n; t>=i; t--)
            int_array[t + 1] = int_array[t];
        int_array[i] = X;
    }
    n += 1;
}

void remove() {
    cin >> i;
    if (int_array[i] == 0) {
        cout << 0 << '\n';
    }
    else {
        cout << int_array[i] << '\n';
        for (int t=i; t<n; t++)
            int_array[t] = int_array[t + 1];
        n -= 1;
    }
}

void printArray() {
    if (int_array[0] == 0) {
        cout << 0 << '\n';
    }
    else {
        int t = 0;
        while (int_array[t] != 0){
            cout << int_array[t] << ' ';
            t += 1;
        }
        cout << '\n';
    }
}

int main() {
    int T;
    cin >> T;

    for (int j=0; j<T; j++){
        cin >> s;
        if (s == "at") at();
        else if (s == "set") set();
        else if (s == "add") add();
        else if (s == "remove") remove();
        else if (s == "printArray") printArray();
    }
}