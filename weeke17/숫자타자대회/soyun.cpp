#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int cost[10][10];
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int move_cost[8] = {2, 2, 2, 2, 3, 3, 3, 3};

vector<pair<int, int>> pos = {
    {3, 1}, // 0
    {0, 0}, // 1
    {0, 1}, // 2
    {0, 2}, // 3
    {1, 0}, // 4
    {1, 1}, // 5
    {1, 2}, // 6
    {2, 0}, // 7
    {2, 1}, // 8
    {2, 2}  // 9
};

void make_cost() {
    for (int start = 0; start <= 9; start++) {
        for (int i = 0; i <= 9; i++) {
            cost[start][i] = 1e9;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        cost[start][start] = 1;
        pq.push({0, start});

        while (!pq.empty()) {
            int dist = pq.top().first;
            int now = pq.top().second;
            pq.pop();

            if (cost[start][now] < dist) continue;

            int x = pos[now].first;
            int y = pos[now].second;

            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                int next = -1;

                for (int num = 0; num <= 9; num++) {
                    if (pos[num].first == nx && pos[num].second == ny) {
                        next = num;
                        break;
                    }
                }

                if (next == -1) continue;

                int nd = dist + move_cost[d];

                if (cost[start][next] > nd) {
                    cost[start][next] = nd;
                    pq.push({nd, next});
                }
            }
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    int INF = 1e9;

    make_cost();

    vector<vector<int>> dp(10, vector<int>(10, INF));
    dp[4][6] = 0;

    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i] - '0';

        vector<vector<int>> next_dp(10, vector<int>(10, INF));

        for (int left = 0; left <= 9; left++) {
            for (int right = 0; right <= 9; right++) {
                if (dp[left][right] == INF) continue;

                if (left == num) {
                    next_dp[left][right] = min(next_dp[left][right], dp[left][right] + 1);
                }
                else if (right == num) {
                    next_dp[left][right] = min(next_dp[left][right], dp[left][right] + 1);
                }
                else {
                    next_dp[num][right] = min(next_dp[num][right], dp[left][right] + cost[left][num]);
                    next_dp[left][num] = min(next_dp[left][num], dp[left][right] + cost[right][num]);
                }
            }
        }

        dp = next_dp;
    }

    answer = INF;

    for (int left = 0; left <= 9; left++) {
        for (int right = 0; right <= 9; right++) {
            answer = min(answer, dp[left][right]);
        }
    }

    return answer;
}