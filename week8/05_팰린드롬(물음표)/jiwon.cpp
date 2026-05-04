#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int N,M;
vector<int> v;
int dp[2003][2003];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=1; i<=N; i++){
        dp[i][i]=1;
    }
    for(int i=0; i<N-1; i++){
        if(v[i]==v[i+1]) dp[i+1][i+2]=1;
    }
    for(int len=3; len<=N; len++){
        for(int i=1; i<=N-len+1; i++){
            int j=i+len-1;
            if(v[i-1]==v[j-1] && dp[i+1][j-1]==1){
                dp[i][j]=1;
            }
        }
    }
    cin>>M;
    for(int i=0; i<M; i++){
        int x,y;
        cin>>x>>y;
        cout<<dp[x][y]<<'\n';
    }
}