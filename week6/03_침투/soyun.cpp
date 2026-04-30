/*
5 6
010101
010000
011101
100011
001011

입력이 붙어있어서 문자 char형으로 받아야했음.. ㅜ
int 로 해서 계속 입력 넣었어했고 
도착 처리를 '-1'로 했었는데 이러면 안됨.
-1은 2글자라서 char형이랑 안 맞음 ㅜㅜ 
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int M, N;
vector<vector<char>>board;

void bfs(int i, int j) {
    queue<pair<int, int>>q;
    q.push({ i,j });
    board[i][j] =  '2';
    while (!q.empty()) {
        auto cur = q.front();
        int cx = cur.first;
        int cy = cur.second;

        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if (board[nx][ny] != '0') continue;
            q.push({ nx, ny });
            board[nx][ny] = '2';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> M >> N;
    board.assign(M, vector<char>(N));
    for (int i = 0;i < M;i++) {
        for (int j = 0;j < N;j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0;i < N;i++) {
        if (board[0][i] == '0')  bfs(0, i);
    }

    // for(int i=0;i<M;i++){
    //     for(int j=0;j<N;j++){
    //         cout << board[i][j];
    //     }
    //     cout << '\n';
    // }

    for (int i = 0;i < N;i++) {
        if (board[M - 1][i] == '2') {
            cout << "YES" << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';

    return 0;
}

/*
3 3
101
100
010
*/