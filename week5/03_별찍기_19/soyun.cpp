#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    int size = 4 * N - 3;  // 전체 크기

    // 공백으로 초기화
    vector<vector<char>> board(size, vector<char>(size, ' '));

    // 겹마다 테두리 그리기
    for (int layer = 0; layer < N; layer++) {

        int start = layer * 2; // 한 칸씩 띄어져 있음. 
        int end = size - 1 - layer * 2;

        // 위, 아래 가로줄
        for (int i = start; i <= end; i++) {
            board[start][i] = '*';
            board[end][i] = '*';
        }

        // 왼쪽, 오른쪽 세로줄
        // 위 아래 * 채우고 세로,가로를 2개씩 빼서 어떻게 하지 고민했는데
        // 그냥 그 자리에 데이터 저장해도 됨!! 
        for (int i = start; i <= end; i++) {
            board[i][start] = '*';
            board[i][end] = '*';
        }
    }

    // 출력
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}

// 1->5->9->14