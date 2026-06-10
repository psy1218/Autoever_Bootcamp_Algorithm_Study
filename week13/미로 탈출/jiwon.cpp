#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
int N,M;
int visit[101][101];

int bfs(int sx, int sy, char c, vector<string>& maps){
    memset(visit,-1,sizeof(visit));
    queue<pair<int,int>> q;
    q.push({sx,sy});
    visit[sx][sy]=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(maps[x][y]==c){
            return visit[x][y];
        }
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=N || ny<0 || ny>=M || maps[nx][ny]=='X') continue;
            if(visit[nx][ny]==-1){
                visit[nx][ny]=visit[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer=0;
    N=maps.size();
    M=maps[0].size();
    int sx,sy;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(maps[i][j]=='S'){
                int a=bfs(i,j,'L',maps);
                if(a==-1) return -1;
                else answer+=a;
            }
            else if(maps[i][j]=='L'){
                int b=bfs(i,j,'E',maps);
                if(b==-1) return -1;
                else answer+=b;
            }
        }
    }
    return answer;
}