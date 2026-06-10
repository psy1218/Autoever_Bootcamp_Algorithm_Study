#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N, res = 0;

bool check(int row, int col, vector<vector<int>>& board) {
	for (int i = 0; i < N; i++) {
		if (board[row][i] == 1) return false;
		if (board[i][col] == 1) return false;
		if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 1) return false;
		if (row - i >= 0 && col + i < N && board[row - i][col + i] == 1) return false;
	}

	return true;
}


void dfs(int row, vector<vector<int>>& board) {
	if (row >= N) {
		res++;
		return;
	}

	for (int col = 0; col < N; col++) {
		if (check(row, col, board)) {
			board[row][col] = 1;
			dfs(row + 1, board);
			board[row][col] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		vector<vector<int>>board(N, vector<int>(N, 0));
		
		res = 0;
		dfs(0, board);
		cout << "#" << t << " " << res << '\n';
	}

	return 0;
}


/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N, res = 0;

bool check(int x, int y, vector<vector<int>>& board) {

	// row는 이미 새 row로 넘어와서 굳이 안 봐도 됨. 어차피 없음.
	// x, y 가 0 일 때 본인 자신은 이미
	for (int i = 0; i < N; i++) {
		if (board[x][i] != 0) return false;
		if (board[i][y] != 0) return false;
		if (x - i >= 0 && y - i >= 0 && board[x - i][y - i] != 0) return false;
		if (x - i >= 0 && y + i < N && board[x - i][y + i] != 0) return false;
		
	}
	return true;

}

// x 는 row 
void dfs(int row, vector<vector<int>>& board) {
	if (row >= N) {
		res += 1;
		return;
	}
	//if (check(x, y, board)) return; 위치가 여기가 아님. col 어디 놓을지 볼 때 확인해야함
	//								  그리고 행, 열, 대각선 다 봐야함. 하나 안 된다고 false 안 됨.

	// col
	for (int col = 0; col < N; col++) {
		if (check(row, col, board)) {
			board[row][col] = 1;
			dfs(row + 1, board);
			board[row][col] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		res = 0;
		vector<vector<int>>board(N, vector<int>(N, 0));

		dfs(0, board);
		cout << "#" << t << " " << res << '\n';
	}

	return 0;
}
*/