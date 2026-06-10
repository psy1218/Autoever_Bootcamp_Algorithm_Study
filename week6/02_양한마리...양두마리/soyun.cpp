#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//방문한 곳은 방문처리를 하고, 방문한 순간 연결된 곳까지 다 방문 처리하기 

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int H, W;
vector<vector<char>>board;

void bfs(int i, int j){
    queue<pair<int,int>>q;
    q.push({i,j});

    while(!q.empty()){
        auto cur = q.front();
        int cur_x = cur.first;
        int cur_y = cur.second;

        q.pop();

        for(int i=0;i<4;i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) continue;
            if(board[next_x][next_y] == '.') continue;
            q.push({next_x,next_y});
            board[next_x][next_y] = '.'; 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for(int k=0;k<T;k++){
        cin >> H >> W;

        board.assign(H, vector<char>(W));
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cin >> board[i][j];
            }
        }

        int cnt = 0;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(board[i][j] != '.'){ 
                    bfs(i,j);
                    cnt += 1;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}