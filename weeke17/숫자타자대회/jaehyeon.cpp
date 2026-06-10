#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int cost[10][10];
int dp[100001][10][10];

pair<int, int> pos(int n) {
    if (n == 0) return {3, 1};

    n--;
    return {n / 3, n % 3};
}

int getCost(int a, int b) {
    if (a == b) return 1;

    pair<int, int> p1 = pos(a);
    pair<int, int> p2 = pos(b);

    int x = abs(p1.first - p2.first);
    int y = abs(p1.second - p2.second);

    int diag = min(x, y);
    int straight = max(x, y) - diag;

    return diag * 3 + straight * 2;
}

int solution(string numbers) {
    int len = numbers.size();
    int INF = 1e9;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cost[i][j] = getCost(i, j);
        }
    }

    for (int i = 0; i <= len; i++) {
        for (int l = 0; l < 10; l++) {
            for (int r = 0; r < 10; r++) {
                dp[i][l][r] = INF;
            }
        }
    }

    dp[0][4][6] = 0;

    for (int i = 0; i < len; i++) {
        int num = numbers[i] - '0';

        for (int l = 0; l < 10; l++) {
            for (int r = 0; r < 10; r++) {
                if (dp[i][l][r] == INF) continue;

                if (l == num) {
                    dp[i + 1][l][r] = min(dp[i + 1][l][r], dp[i][l][r] + 1);
                }
                else if (r == num) {
                    dp[i + 1][l][r] = min(dp[i + 1][l][r], dp[i][l][r] + 1);
                }
                else {
                    dp[i + 1][num][r] = min(dp[i + 1][num][r], dp[i][l][r] + cost[l][num]);
                    dp[i + 1][l][num] = min(dp[i + 1][l][num], dp[i][l][r] + cost[r][num]);
                }
            }
        }
    }

    int ans = INF;

    for (int l = 0; l < 10; l++) {
        for (int r = 0; r < 10; r++) {
            ans = min(ans, dp[len][l][r]);
        }
    }

    return ans;
}