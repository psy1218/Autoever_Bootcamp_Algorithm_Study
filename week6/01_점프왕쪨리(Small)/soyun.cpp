#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

int N;
int flag = 0;
vector<vector<int>>board;


void bfs(int i, int j) {
	queue<pair<int, int>>q;

	q.push({ i,j });
	while (!q.empty()) {
		auto cur = q.front();
		int cur_x = cur.first;
		int cur_y = cur.second;

		q.pop();


		if (board[cur_x][cur_y] == -1) {
			cout << "HaruHaru" << '\n';
			flag = 1;
			return;
		}

		for (int i = 0; i < 2; i++) {
			int num = board[cur_x][cur_y];
			int next_x = cur_x + (dx[i] * num);
			int next_y = cur_y + (dy[i] * num);
			if (next_x > N || next_y > N) continue; // 보드 초과하는지
			if (board[next_x][next_y] == 0) continue; // 0인 경우 계속 push 하면 무한 굴레에 파짐 ㅜ
            // 0이면 아무리 추가해도 범위를 안 넘어가서 계속 큐에 넣게 됨 
            // 예외 처리하기!! 
			q.push({ next_x, next_y });
		}

	}
}

int main() {
	cin >> N;

	board.assign(N + 1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	if (board[1][1] == 0) {
		cout << "Hing" << '\n';
		return 0;
	}

	bfs(1, 1);
	if (flag == 0) cout << "Hing" << '\n';


	return 0;
}
#if 0
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

int N;
int flag = 0;
vector<vector<int>>board;
vector<vector<int>>visited; // 방문했는지 체크하기! 안 하면, 중복해서 방문할 수 있음.
/*
1 1 1
1 1 1
1 1 -1

이렇게 되면 2,2 좌표가 오른쪽 때문에, 아래 때문에 2번씩 들어가서 
*/


void bfs(int i, int j) {
	queue<pair<int,int>>q;

	q.push({ i,j });
	visited[i][j] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		int cur_x = cur.first;
		int cur_y = cur.second;

		q.pop();


		if (board[cur_x][cur_y] == -1) {
			cout << "HaruHaru" << '\n';
			flag = 1;
			return;
		}

		for (int i = 0; i < 2; i++) {
			int num = board[cur_x][cur_y];
			int next_x = cur_x + (dx[i] * num);
			int next_y = cur_y + (dy[i] * num);
			if (next_x > N || next_y > N) continue; // 보드 초과하는지
			if (visited[next_x][next_y] == 1) continue;
			q.push({ next_x, next_y });
			visited[next_x][next_y] = 1;
		}

	}
}

int main() {
	cin >> N;

	board.assign(N+1, vector<int>(N+1));
	visited.assign(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	if (board[1][1] == 0) {
		cout << "Hing" << '\n';
		return 0;
	}

	bfs(1, 1);
	if(flag == 0) cout << "Hing" << '\n';


	return 0;
}

/*
1 2 1
2 2 2
1 2 -1 
*/

#endif