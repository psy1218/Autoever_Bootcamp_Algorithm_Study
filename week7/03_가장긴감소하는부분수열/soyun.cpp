#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[1001] = { 0, };
	int dp[1001] = { 0, };

	int N, a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr[i] = a;
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int res = *max_element(dp, dp + N);

	cout << res << '\n';

	return 0;
}

// dp는 바로 그 전 과거와 현재를 비교하는줄 알았지만,
// 전체 과거와 현재를 비교하는 문제도 많음. 


/*
 A = {10, 30, 10, 20, 20, 10}
*/