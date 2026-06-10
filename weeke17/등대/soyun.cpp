#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int dp[100001][2];
bool visited[100001];

void dfs(int node) {
    visited[node] = true;

    dp[node][0] = 0;
    dp[node][1] = 1;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];

        if (visited[next]) continue;

        dfs(next);

        dp[node][0] += dp[next][1];
        dp[node][1] += min(dp[next][0], dp[next][1]);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;

    for (int i = 0; i < lighthouse.size(); i++) {
        int a = lighthouse[i][0];
        int b = lighthouse[i][1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    answer = min(dp[1][0], dp[1][1]);

    return answer;
}