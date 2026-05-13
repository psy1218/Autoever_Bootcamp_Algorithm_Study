#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int N;
int a[101][101];
long long dp[101][101];

long long go(int x, int y){
    if(x==N-1 && y==N-1) return 1;
    long long &res=dp[x][y];
    if(res!=-1) return res;
    int now=a[x][y];
    res=0;
    if(y+now<N) res+=go(x, y+now);
    if(x+now<N) res+=go(x+now, y);
    return res;
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<go(0,0);
}