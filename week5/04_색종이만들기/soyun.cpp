#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> board;
int white = 0;  // 0
int blue = 0;   // 1

void divide(int x, int y, int size) {

    int first = board[x][y];
    bool same = true;

    // 현재 구간이 전부 같은 색인지 검사
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (board[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    // 전부 같은 색이면 카운트
    if (same) {
        if (first == 0) white++;
        else blue++;
        return;
    }

    // 다르면 4등분
    int half = size / 2;
    divide(x, y, half);                    // 왼쪽 위
    divide(x, y + half, half);             // 오른쪽 위
    divide(x + half, y, half);             // 왼쪽 아래
    divide(x + half, y + half, half);      // 오른쪽 아래
}

int main() {
    cin >> N;

    board.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    divide(0, 0, N);

    cout << white << "\n";
    cout << blue << "\n";

    return 0;
}

#if 0
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>res(2);

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int bfs(int x, int y, int num){
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){

        auto cur = q.front();
        int cur_x = cur.first;
        int cur_y = cur.second;

        for(int i=0;i<4;i++){
            int qx = cur_x + dx[i];
            int qy = cur_y + dy[i];

            if(qx < 0 || qx >= x || qy < 0 || qy >= y) continue;
            
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, color;
    cin >> N;

    vector<vector<int>>board(N, vector<int>(N));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> color;
            board[i][j] = color;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j] == 0) res[0] += bfs(i,j,0);
            if(board[i][j] == 1) res[1] += bfs(i,j,1);
        }
    }

    return 0;
}
#endif