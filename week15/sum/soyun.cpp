#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("input.txt", "r", stdin);

	int T;
	for (int t = 1; t <= 10; t++) {
		cin >> T;

		vector<int>res;
		int board[100][100];

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> board[i][j];
			}
		}

		int diag1_res = 0;
		int diag2_res = 0;
		for (int i = 0; i < 100; i++) {
			int row_res = 0;
			int col_res = 0;

			for (int j = 0; j < 100; j++) {
				
				row_res += board[i][j];
				col_res += board[j][i];
				
			}

			diag1_res += board[i][i];
			diag2_res += board[i][99 - i];
			res.push_back(row_res);
			res.push_back(col_res);

		}
		res.push_back(diag1_res);
		res.push_back(diag2_res);

		sort(res.begin(), res.end());

		cout << "#" << t << " " << *(res.end() - 1) << '\n';

	}


	return 0;
}