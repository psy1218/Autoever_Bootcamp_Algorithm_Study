#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T,H,W; 
int a[101][101];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int nx, ny;
bool visit[101][101];

void DFS(int x, int y){
    for(int i=0; i<4; i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx<0 || H<=nx || ny<0 || W<=ny) continue;
        if(visit[nx][ny]) continue;
        if(a[nx][ny]==1){
            visit[nx][ny]=true;
            DFS(nx,ny);
        }
    }
}

int main(){
    cin>>T;
    for(int i=0; i<T; i++){
        fill(&a[0][0], &a[0][0]+101*101, 0);
        fill(&visit[0][0], &visit[0][0]+101*101, false);
        int cnt=0;
        cin>>H>>W;
        for(int j=0; j<H; j++){
            string s;
            cin>>s;
            for(int k=0; k<W; k++){
                if(s[k]=='#'){
                    a[j][k]=1;
                }
            }
        }
        // for(int j=0; j<H; j++){
        //     for(int k=0; k<W; k++){
        //         cout<<a[j][k]<<' ';
        //     }
        //     cout<<endl;
        // }
        for(int j=0; j<H; j++){
            for(int k=0; k<W; k++){
                if(a[j][k]==1 && !visit[j][k]){
                    DFS(j,k);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}