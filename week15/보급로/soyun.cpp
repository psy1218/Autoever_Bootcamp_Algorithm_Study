#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Info {
	int x;
	int y;
	int cost;
};

int T, N;
vector<vector<char>>board;
vector<vector<int>>Map;
vector<vector<int>>dist;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct compare {
	bool operator()(Info& a,Info& b) {
		return a.cost > b.cost;
	}
};

void dijkstra(int X, int Y, int COST) {
	priority_queue<Info, vector<Info>, compare>pq;
	pq.push({X, Y, COST});

	dist.assign(N, vector<int>(N, INT_MAX));
	dist[X][Y] = COST;

	while (!pq.empty()) {
		auto cur = pq.top();
		int cx = cur.x;
		int cy = cur.y;
		int cc = cur.cost;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (cc > dist[cx][cy]) continue;
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)	continue;

			if (dist[nx][ny] > Map[nx][ny] + cc) {
				dist[nx][ny] = Map[nx][ny] + cc;
				pq.push({ nx, ny, Map[nx][ny] + cc });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		board.assign(N, vector<char>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}

		Map.assign(N, vector<int>(N, 0));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Map[i][j] = board[i][j] - '0';
			}
		}
		

		dijkstra(0, 0, 0);

		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << dist[i][j] << " ";
		//	}
		//	cout << '\n';
		//}

		cout << "#" << t << " " << dist[N - 1][N - 1] << '\n';
	}

	return 0;
}

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N;
vector<vector<char>>board;
vector<vector<int>>dist;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	
	dist.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = board[i][j] - '0';
		}
	}


	while (!q.empty()) {
		auto cur = q.front();
		int cx = cur.first;
		int cy = cur.second;
		q.pop();
		board[x][y] = '.';

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)	continue;
			if (board[nx][ny] == '.') continue;
			dist[nx][ny] += dist[cx][cy];
			board[nx][ny] = '.';
			q.push({ nx,ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		board.assign(N, vector<char>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}

		board[N - 1][N - 1] = 'G';
		
		bfs(0, 0);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << dist[i][j] << " ";
			}
			cout << '\n';
		}

		cout << "#" << t << " " << dist[N - 1][N - 1] << '\n';
	}

	return 0;
}
#endif