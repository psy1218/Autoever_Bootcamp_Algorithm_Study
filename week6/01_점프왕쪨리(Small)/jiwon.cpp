#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int a[4][4];
const int dx[2]={1,0};
const int dy[2]={0,1};
int nx,ny;
bool ans;
bool visit[4][4];

void DFS(int x, int y, int l){
    for(int i=0; i<2; i++){
        nx=x+dx[i]*l;
        ny=y+dy[i]*l;
        if(0>nx || nx>=N || 0>ny || ny>=N) continue;
        if(visit[nx][ny]) continue;
        // cout<<nx<<' '<<ny<<endl;
        visit[nx][ny]=true;
        if(a[nx][ny]==-1){
            ans=true;
            return;
        }
        DFS(nx,ny,a[nx][ny]);
    }
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>a[i][j];
        }
    }
    DFS(0,0,a[0][0]);
    if(ans){
        cout<<"HaruHaru";
    }
    else{
        cout<<"Hing";
    }
}