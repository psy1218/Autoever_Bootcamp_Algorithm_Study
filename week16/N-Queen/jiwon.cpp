#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int T,N,cnt;
bool visit[11];
bool visit1[25];
bool visit2[25];
 
void dfs(int n){
    if(n==N){
        cnt++;
        return;
    }
    for(int i=1; i<=N; i++){
        if(visit[i] || visit1[n+i] || visit2[n-i+N]) continue;
        visit[i]=true;
        visit1[n+i]=true; // / 대각선 합은 다 같음
        visit2[n-i+N]=true; // \ 대각선
        dfs(n+1);
        visit[i]=false;
        visit1[n+i]=false;
        visit2[n-i+N]=false;
    }
}
 
int main(){
    cin>>T;
    for(int i=1; i<=T; i++){
        cnt=0;
        cin>>N;
        memset(visit, false, sizeof(visit));
        memset(visit1, false, sizeof(visit1));
        memset(visit2, false, sizeof(visit2));
        dfs(0);
        cout<<'#'<<i<<' '<<cnt<<'\n';
    }
    return 0;
}