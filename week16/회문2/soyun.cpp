#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

// 함수에서 k<(len+1) / 2 범위가 되어야함.
// len의 인자가 함수에 들어올 떄 0~99 라서, +1 을 해야함.
// 그래서 1~100 까지의 길이가될 수 있게 해야함. 
bool check_row(vector<vector<char>>& board, int i, int start, int len) {
	for (int k = 0; k < (len+1) / 2; k++) {
		if (board[i][start + k] != board[i][start + len - k]) return false;
	}
	return true;
}

bool check_col(vector<vector<char>>& board, int i, int start, int len) {
	for (int k = 0; k < (len+1) / 2; k++) {
		if (board[start + k][i] != board[start + len - k][i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	for (int t = 1;t <= 10;t++) {
		int N;
		cin >> N;

		vector<vector<char>>board(100, vector<char>(100));
		for (int i = 0;i < 100;i++) {
			for (int j = 0;j < 100;j++) {
				cin >> board[i][j];
			}
		}

		int answer = 1;

		// 이렇게 하면 안 됨. 그럼 첫 줄에 찾고 멈춤. 다음 줄도 계속 보고, 가장 큰 len 찾는 거니까
		//  for 문 순서가 바뀌어야함. 
		//for (int i = 0;i < 100;i++) {
		//	bool found = false;

		//	for (int len = 99;len >= 0;len--) {
		for (int len = 99;len >= 0;len--) {
			bool found = false;
			for (int i = 0;i < 100;i++) {
				for (int start = 0; start + len < 100;start++) {
					found = false;
					if (check_row(board, i, start, len)) {
						answer = len + 1;
						found = true;
						break;
					}

					if (check_col(board, i, start, len)) {
						answer = len + 1;
						found = true;
						break;
					}
				}
				if (found) break;
			}
			if (found) break;
		}

		cout << "#" << t << " " << answer << '\n';
	}

	return 0;
}




/*
* 
// 하나하나 순차적으로 봤찌만, 긴 것부터 보면 좋음 
for (int i = 0;i < 100;i++) {
			for (int j = 0;j < 100;j++) {
				int k = j + 1;

				int cnt = 0;
				while (1) {
					for (int a = j;a <= k-j / 2;a++) {
						if(board[i][a] == board[i][k-a])
					}

				}
			}
		}

*/