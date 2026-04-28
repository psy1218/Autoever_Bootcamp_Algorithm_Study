#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int cnt = 0, flag = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<vector<char>>board;
vector<pair<int,int>>Info(3, {0,0});

// 0: S - 시작 지점
// 1: E - 출구
// 2: L - 레버

void bfs(int sx, int sy, int ex, int ey){
    vector<vector<int>>Dist(board.size(), vector<int>(board[0].size(), 0));
    vector<vector<int>>visited(board.size(), vector<int>(board[0].size(), 0));
    queue<pair<int,int>>q;
    q.push({sx,sy});
    visited[sx][sy] = 1;
    
    flag = 0;
    while(!q.empty()){
        auto cur = q.front();
        int cx = cur.first;
        int cy = cur.second;
        q.pop();
 
        // 길이 없는 경우 - 이 방법은 틀린 것임.
        // queue 특성 상 아직 남은 길이 있는데 (가능성이 있는 길)
        // 하나 보고 안 된다는건 틀린 것임.
        // 그래서 q가 빌 동안 레버를 찾았는지 flag를 세움. 
        /*
                비유하면

                BFS는 동굴 탐험할 때 여러 팀이 동시에 퍼지는 느낌이야.

                A팀은 막다른 길 만남
                B팀은 아직 다른 길 탐색 중
                C팀은 거의 목적지 근처일 수도 있음

                그런데 A팀이 막혔다고
                “전체 동굴에 길이 없다”라고 하면 안 되겠지.
        */
//       flag = 0;
//         for(int i=0;i<4;i++){
//             int nx = cx + dx[i];
//             int ny = cy + dy[i];
            
//             //cout << cx << ' ' << cy << ' ' << nx << ' ' << ny << ' ' << flag << '\n';

            
//             if(nx < 0 || nx >= board.size() || ny < 0 || ny >=board[0].size()){
//                 flag += 1;
//                 continue;
//             }

//             if(board[nx][ny] == 'X') flag += 1;

//             if(flag == 4) return;
//         }
        
        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || nx >= board.size() || ny < 0 || ny >=board[0].size()) continue;
            if(board[nx][ny] == 'X' || visited[nx][ny] == 1) continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
            Dist[nx][ny] = Dist[cx][cy] + 1; // += 를 하면 이전 내용들이 계속 누적합됨. 
            if(nx == ex && ny == ey) {
                cnt += Dist[nx][ny];
                flag = 1;
                return;
            }
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0;
    
    board.assign(maps.size(), vector<char>(maps[0].size(), ' ')); 
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++){
            board[i][j] = maps[i][j];
            if(board[i][j] == 'S') Info[0] = {i,j};
            if(board[i][j] == 'E') Info[1] = {i,j};
            if(board[i][j] == 'L') Info[2] = {i,j};
        }
    }
    
    // for(auto it:Info){
    //    cout << it.first << ' ' << it.second << '\n';
    // }
    
    bfs(Info[0].first, Info[0].second,Info[2].first, Info[2].second);
    if(flag == 0) return -1;
    bfs(Info[2].first, Info[2].second,Info[1].first, Info[1].second);
    if(flag == 0) return -1;

    answer = cnt;
    return answer;
}

/*
if((nx < 0 || board[nx][ny] == 'X')
&& (nx >= board.size() || board[nx][ny] == 'X')
&& (ny < 0 || board[nx][ny] == 'X')
&& (ny >= board[0].size() || board[nx][ny] == 'X')
){
*/