#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int N, M;
vector<vector<char>>board;

int bfs(int i, int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    int cnt = 1;
    board[i][j] = '.';
    while(!q.empty()){
        auto cur = q.front();
        int cx = cur.first;
        int cy = cur.second;

        q.pop();

        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= N || ny <0 || ny >= M) continue;
            if(board[nx][ny] != '#') continue;
            q.push({nx,ny});
            board[nx][ny] = '.';
            cnt ++;
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K, r, c;
    cin >> N >> M >> K;

    board.assign(N, vector<char>(M, '.'));
    for(int i=0;i<K;i++){
        cin >> r >> c;
        board[r-1][c-1] = '#';
    }

    int Max = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int cnt = 0;
            if(board[i][j] == '#') cnt = bfs(i,j);
            if(Max < cnt) Max = cnt;
        }
    }

    cout << Max << '\n';
    

    return 0;
}