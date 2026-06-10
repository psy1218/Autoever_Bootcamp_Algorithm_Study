#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<vector<int>> adj;
vector<vector<int>> dp;
vector<bool> visited;
void dfs(int cur){
    visited[cur]=true;
    dp[cur][0]=0;
    dp[cur][1]=1;
    for(int next:adj[cur]){
        if(visited[next])continue;
        dfs(next);
        dp[cur][0]+=dp[next][1];
        dp[cur][1]+=min(dp[next][0],dp[next][1]);
    }
}
int solution(int n,vector<vector<int>> lighthouse){
    N=n;
    adj.assign(N+1,vector<int>());
    dp.assign(N+1,vector<int>(2,0));
    visited.assign(N+1,false);
    for(auto& edge:lighthouse){
        int u=edge[0];
        int v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    return min(dp[1][0],dp[1][1]);
}
