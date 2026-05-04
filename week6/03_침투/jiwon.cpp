#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int M,N;
int a[1001][1001];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int nx, ny;
bool visit[1001][1001];
bool ans;

void DFS(int x, int y){
    for(int i=0; i<4; i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx<0 || M<=nx || ny<0 || N<=ny) continue;
        if(visit[nx][ny]) continue;
        if(a[nx][ny]==0){
            visit[nx][ny]=true;
            DFS(nx,ny);
        }
    }
}

int main(){
    cin>>M>>N;
    for(int i=0; i<M; i++){
        string s;
        cin>>s;
        for(int j=0; j<N; j++){
            if(s[j]=='1'){
                a[i][j]=1;
            }
        }
    }
    for(int i=0; i<N; i++){
        if(!visit[0][i]&&a[0][i]==0){
            DFS(0,i);
        }
    }
    for(int i=0; i<N; i++){
        if(visit[M-1][i]){
            ans=true;
        }
    }
    if(ans){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}