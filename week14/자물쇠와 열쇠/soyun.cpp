#include <string>
#include <vector>

using namespace std;



vector<vector<int>> rotateKey(vector<vector<int>> key) {
    int M = key.size();
    vector<vector<int>> rotated(M, vector<int>(M, 0));

    // 90 도 돌리기 
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            rotated[j][M - 1 - i] = key[i][j];
        }
    }

    return rotated;
}

bool check(vector<vector<int>> key, vector<vector<int>> lock, int startX, int startY) {
    int M = key.size();
    int N = lock.size();

    int boardSize = N + 2 * (M - 1);
    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));

    // lock을 큰 board 가운데에 복사
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i + M - 1][j + M - 1] = lock[i][j];
        }
    }

    // key를 board의 시작점에 올림. 
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            board[startX + i][startY + j] += key[i][j]; // 보드에서의 출발점 위치의 키 위치와 
                                                        // 진짜 키가 맞는지 비교하기 위해서 더하기
        }
    }

    // lock이 놓인 영역만 확인
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i + M - 1][j + M - 1] != 1) { // M-1은 전체 사이즈가 늘어났으니까 줄여주기. 
                // 1이어야하는 이유: 0과 1을 더하면 만날 수 빈 구멍에 들어가는거임.
                // 더해서 0이면 둘 다 빈 거고 2이면 부딪히는 상태 
                return false;
            }
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size();
    int N = lock.size();

    // 기본 락 보드보다 크게 만들어서, 키가 범위에서도 잘 들어가는지 확인하기
    // 그래서 키가 락에 하나라도 겹쳐야하니까 M-1이고, 왼쪾, 오른쪽 둘 다 봐야하니까 *2를 함.
    // 그래서 기본 락 사이즈에다가 N + 2 * (M - 1)
    int boardSize = N + 2 * (M - 1);

    for (int r = 0; r < 4; r++) {
        // key를 큰 board 안에서 왼쪽 위부터 쭉 밀어보기, 범위 안 넘어가게 ,boardSize - M 까지 키 딱 맞게 살펴보기 
        for (int x = 0; x <= boardSize - M; x++) {
            for (int y = 0; y <= boardSize - M; y++) {
                if (check(key, lock, x, y)) {
                    return true;
                }
            }
        }

        key = rotateKey(key);
    }

    return false;
}

/* 
구현 : 90도씩 돌려서 맞는지 확인하기. 

0 0 0   0 1 0   1 1 0   0 0 1
1 0 0   1 0 0   0 0 1   0 0 1 
0 1 1   1 0 0   0 0 0   0 1 0 

1,0     0,1     1,2     2,1
2,1     1,0     0,1     1,2
2,2     2,0     0,0     0,2


temp[j][M-1-i] = key[i][j]
*/