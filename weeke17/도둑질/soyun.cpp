#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<int>& money, int start, int end) {
    vector<int> dp(money.size(), 0);

    dp[start] = money[start];
    dp[start + 1] = max(money[start], money[start + 1]);

    for (int i = start + 2; i <= end; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }

    return dp[end];
}

int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();

    int res1 = check(money, 0, n - 2);
    int res2 = check(money, 1, n - 1);

    answer = max(res1, res2);

    return answer;
}