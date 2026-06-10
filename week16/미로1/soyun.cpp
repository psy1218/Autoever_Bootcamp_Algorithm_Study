#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool bfs(vector<pair<int, int>>& pos, vector<vector<char>>& board) {
	queue<pair<int, int>>q;
	q.push({ pos[0].first, pos[0].second });
	while (!q.empty()) {
		auto cur = q.front();
		int cx = cur.first;
		int cy = cur.second;
		q.pop();

		board[cx][cy] = '1';

		for (int i = 0;i < 4;i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16) continue;
			if (board[nx][ny] == '3') return true;
			if (board[nx][ny] != '0') continue;
			q.push({ nx, ny });
			board[nx][ny] = '1';
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);

	for (int t = 1;t <= 10;t++) {
		int N;
		cin >> N;
		vector<vector<char>>board(16, vector<char>(16));
		vector<pair<int, int>>pos(2);

		for (int i = 0;i < 16;i++) {
			for (int j = 0;j < 16;j++) {
				cin >> board[i][j];
				if (board[i][j] == '2') {
					pos[0].first = i;
					pos[0].second = j;
				}
				if (board[i][j] == '3') {
					pos[1].first = i;
					pos[1].second = j;
				}
			}
		}
		cout << "#" << t << " ";
		if (bfs(pos, board)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}


	return 0;
}