#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T, N, num;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		vector<int>nums(N);
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}

		long long res = 0, std = nums[N-1]; // long long.. 타입 잘 보기 

		for (int i = N-2; i >= 0; i--) {
			if (nums[i] < std) {
				res += std - nums[i];
			}
			if (nums[i] > std) {
				std = nums[i];
			}
		}

		cout << "#" << t << " " << res << '\n';
	}

	return 0;
}