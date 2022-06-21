#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;

    int safe_num;
    int korean = 0, japanese = 0, chinese = 0;

    for(int i=0; i<T; i++){
        cin >> safe_num;
        int* safe = new int[safe_num];

        for (int j=0; j<safe_num; j++){
            cin >> safe[j];
        }

        for (int j=0; j<safe_num; j++){
            if (j % 3 == 0) korean += safe[j];
            else if (j % 3 == 1) japanese += safe[j];
            else if (j % 3 == 2) chinese += safe[j];
        }
        cout << korean << ' ' << japanese << ' ' << chinese;
        korean = 0; japanese = 0; chinese = 0;
        cout << '\n';
    }
}