#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;
char maze[16][16];
bool visited[16][16];
int ans=0;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void dfs(int y,int x){
    if(maze[y][x]=='3'){
        ans=1;
        return;
    }
    visited[y][x]=true;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny>=0 && ny<16 && nx>=0 && nx<16){
            if(maze[ny][nx]!='1' && !visited[ny][nx]){
                dfs(ny,nx);
                if(ans==1) return;
            }
        }
    }
}

int main(){
    while(cin>>T){
        int startX=0, startY=0;
        ans=0;
        for(int i=0; i<16; i++){
            string s;
            cin>>s;
            for(int j=0; j<16; j++){
                maze[i][j]=s[j];
                visited[i][j]=false;
                if(maze[i][j]=='2'){
                    startY=i;
                    startX=j;
                }
            }
        }
        dfs(startY, startX);
        cout<<'#'<<T<<' '<<ans<<'\n';
    }
    return 0;
}