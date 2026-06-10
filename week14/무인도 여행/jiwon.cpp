#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[4]={0,-1,0,1};
const int dy[4]={-1,0,1,0};
int cnt;
int visit[103][103];
int N,M;

void dfs(int x, int y, const vector<string>& maps){
    visit[x][y]=1;
    cnt+=maps[x][y]-'0';
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
        if(visit[nx][ny]==1 || maps[nx][ny]=='X') continue;
        else{
            dfs(nx,ny,maps);
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    N=maps.size();
    M=maps[0].size();
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(visit[i][j]==1||maps[i][j]=='X') continue;
            else{
                cnt=0;
                dfs(i,j,maps);
                answer.push_back(cnt);
            }
        }
    }
    if(answer.empty()) return {-1};
    sort(answer.begin(),answer.end());
    return answer;
}