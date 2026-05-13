#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


//int bfs(int x, int y, vector<vector<char>>& maps){ // 틀림.. maps는 vector<string> 타입임. 
int bfs(int x, int y, vector<string>& maps){
    queue<pair<int,int>>q;
    q.push({x,y});
    // 이 부분도 틀림. int Sum = maps[x][y]; 숫자는 아스키코드로 된 문자여서, 진짜 숫자로 바꿔줘야함. 
    int Sum = maps[x][y] - '0';
    maps[x][y] = '.';
    
    while(!q.empty()){
        auto cur = q.front();
        int cx = cur.first;
        int cy = cur.second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(maps[nx][ny] == 'X' || maps[nx][ny] == '.') continue;
            q.push({nx, ny});
            Sum += maps[nx][ny] - '0';
            maps[nx][ny] = '.';
        }
        
    }
    return Sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    N = maps.size();
    M = maps[0].size();
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(maps[i][j]!='X' && maps[i][j]!='.'){ // 조건 잘 확인하기, 대문자임 
                int res = bfs(i,j, maps);
                answer.push_back(res);
            }
        }
    }
    
    //if(answer.empty()) return -1; // 틀림 -> answer 타입은 vector 인데 return 을 int로 보내줌. {} 활용해야함.
    if(answer.empty()) return {-1};
    
    sort(answer.begin(), answer.end());
    
    return answer;
}