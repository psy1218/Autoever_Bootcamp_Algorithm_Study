#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;

void dfs(int now, int parent)
{
    dp[now][0] = 0;
    dp[now][1] = 1;

    for(int next : graph[now])
    {
        if(next == parent) continue;

        dfs(next, now);

        dp[now][0] += dp[next][1];
        dp[now][1] += min(dp[next][0], dp[next][1]);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {

    graph.resize(n + 1);
    dp.assign(n + 1, vector<int>(2, 0));

    for(int i = 0; i < lighthouse.size(); i++)
    {
        int a = lighthouse[i][0];
        int b = lighthouse[i][1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    return min(dp[1][0], dp[1][1]);
}