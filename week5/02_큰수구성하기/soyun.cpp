#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<char> K(M);
    for (int i = 0; i < M; i++)
        cin >> K[i];

    sort(K.begin(), K.end());
    char maxDigit = K.back();

    string n = to_string(N);
    string result = "";

    for (int i = 0; i < n.size(); i++) {
        char cur = n[i];
        char chosen = -1;  // 선택 못했음을 명확히 표현

        // 현재 자리에서 cur 이하 중 가장 큰 숫자 선택
        for (char d : K) {
            if (d <= cur)
                chosen = d;
        }

        if (chosen == -1) {
            // 현재 자리에서 선택 불가(선택하면 큰 수) → 이전 자리 줄이기 시도
            int pos = result.size() - 1;


            // 예) 540, 5,4 -> 455가 맞음. 544 안됨. 
            // 5-> 54 -> 54(4보다 작은 거 없고 pos 위치 앞으로!) -> 44 -> 455
            while (pos >= 0) {
                char prev = result[pos];
                char smaller = -1;

                for (char d : K) {
                    if (d < prev)
                        smaller = d;
                }

                if (smaller != -1) {
                    result[pos] = smaller;

                    // 그 뒤는 전부 최대값으로 채움
                    result = result.substr(0, pos + 1);
                    result += string(n.size() - pos - 1, maxDigit);

                    cout << result;
                    return 0;
                }

                pos--;
            }

            //1 첫째 자리 큰게 없으면 = 앞자리도 전부 줄일 수 없으면 자리수 감소
            // 657, 9 9 -> 99 
            cout << string(n.size() - 1, maxDigit); // 자리수 하나 감소하고 다 최대로 채우기 
            return 0;
        }

        result += chosen;

        // 657, 1 5 7 -> 5 ->577
        if (chosen < cur) {
            // 이미 작아졌으면 뒤는 최대값
            result += string(n.size() - i - 1, maxDigit); // 채우고 남은 거 만큼 
            cout << result;
            return 0;
        }
    }

    // 끝까지 동일한 경우
    cout << result;
    return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<char> K(M);
    for (int i = 0; i < M; i++) {
        cin >> K[i];
    }

    sort(K.begin(), K.end());   // 오름차순
    char maxDigit = K.back();

    string n = to_string(N);
    string result = "";

    for (int i = 0; i < n.size(); i++) {
        char cur = n[i];
        char chosen = 0;

        // 현재 자리에서 cur 이하 중 가장 큰 숫자 선택
        for (char d : K) {
            if (d <= cur)
                chosen = d;
        }

        if (chosen == 0) {
            // 현재 자리에서 선택 불가 → 자리수 줄이기
            // 321 : 4 7 -> 77 
            cout << string(n.size() - 1, maxDigit);
            return 0;
        }

        result += chosen;

        if (chosen < cur) {
            // 이미 작아졌으면 뒤는 전부 최대값
            // 657: 1 5 7 -> 577 
            result += string(n.size() - i - 1, maxDigit);
            cout << result;
            return 0;
        }
    }

    // 끝까지 동일 → 그대로 출력
    cout << result;
    return 0;
}

*/