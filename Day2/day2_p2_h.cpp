#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    int safe_num;
    int korean = 0, japanese = 0, chinese = 0;
    int korean_num = 0, japanese_num = 0, chinese_num = 0;
    int korean_average = 0, japanese_average = 0, chinese_average = 0;

    for(int i=0; i<T; i++){
        cin >> safe_num;
        int* safe = new int[safe_num];

        for (int j=0; j<safe_num; j++){
            cin >> safe[j];
        }

        for (int j=0; j<safe_num; j++){
            if (j % 3 == 0) {
                korean += safe[j];
                if (safe[j] != 0) korean_num += 1;
            }
            else if (j % 3 == 1) {
                japanese += safe[j];
                if (safe[j] != 0) japanese_num += 1;
            }
            else if (j % 3 == 2) {
                chinese += safe[j];
                if (safe[j] != 0) chinese_num += 1;
            }
        }
        cout << korean << ' ' << japanese << ' ' << chinese << '\n';
        if (korean_num == 0) korean_average = 0; else korean_average = floor(korean / korean_num);
        if (japanese_num == 0) japanese_average = 0; else japanese_average = floor(japanese / japanese_num);
        if (chinese_num == 0) chinese_average = 0; else chinese_average = floor(chinese/ chinese_num);
        cout << korean_average << ' ' << japanese_average << ' ' << chinese_average << '\n';
        korean = 0; japanese = 0; chinese = 0;
        korean_num = 0; japanese_num = 0; chinese_num = 0;
        delete[] safe;
    }
}