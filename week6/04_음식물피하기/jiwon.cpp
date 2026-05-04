#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,K;
int a[101][101];
bool visit[101][101];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int nx, ny, cnt;
int mx=-1;

void DFS(int x, int y){
    visit[x][y]=true;
    cnt++;
    // cout<<x<<' '<<y<<endl;
    for(int i=0; i<4; i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx<1 || N<nx || ny<1 || M<ny) continue;
        if(visit[nx][ny]) continue;
        if(a[nx][ny]==1){
            DFS(nx,ny);
        }
    }
}

int main(){
    cin>>N>>M>>K;
    for(int i=0; i<K; i++){
        int r,c;
        cin>>r>>c;
        a[r][c]=1;
    }
    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=M; j++){
    //         cout<<a[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cnt=0;
            if(!visit[i][j] && a[i][j]==1){
                DFS(i,j);
                mx=max(mx,cnt);
            }
        }
    }
    cout<<mx;
}