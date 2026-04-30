#include <iostream>
#include <vector>
using namespace std;

struct Info {
    int num;
    int strike;
    int ball;
};

int main() {
    int N;
    cin >> N;

    vector<Info> questions(N);

    for (int i = 0; i < N; i++) {
        cin >> questions[i].num
            >> questions[i].strike
            >> questions[i].ball;
    }

    int answer = 0;

    // 1~9 중 서로 다른 3자리 숫자 생성
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            for (int c = 1; c <= 9; c++) {

                if (a == b || b == c || a == c) continue; // 서로 다른 숫자 세 개로 구성되어 있어서 같으면 pass 

                bool valid = true;

                for (int i = 0; i < N; i++) {

                    int num = questions[i].num;

                    int x = num / 100;
                    int y = (num / 10) % 10;
                    int z = num % 10;

                    int strike = 0;
                    int ball = 0;

                    // strike 계산
                    if (a == x) strike++;
                    if (b == y) strike++;
                    if (c == z) strike++;

                    // ball 계산
                    if (a == y || a == z) ball++;
                    if (b == x || b == z) ball++;
                    if (c == x || c == y) ball++;

                    // 스트라이크랑 볼 개수가 다르면 일치 x 
                    if (strike != questions[i].strike ||
                        ball != questions[i].ball) {
                        valid = false;
                        break;
                    }
                }

                if (valid) answer++;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}