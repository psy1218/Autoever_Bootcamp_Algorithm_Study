#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 0, N;

	while (1) {
		cin >> N;

		if (N == 0) break;

		T++;

		vector<vector<int>>graph(N + 1, vector<int>(N + 1));
		vector<vector<int>>dist(N + 1, vector<int>(N + 1, INT_MAX));

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				cin >> graph[i][j];
			}
		}

		// x,y,w
		priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> >pq;


		dist[0][0] = graph[0][0]; // 시작 
		pq.push({ graph[0][0], {0,0} });

		while (!pq.empty()) {
			auto cur = pq.top();
			int cur_Dist = cur.first;
			int cur_x = cur.second.first;
			int cur_y = cur.second.second;
			pq.pop();

			if (dist[cur_x][cur_y] < cur_Dist) continue; //dist 테이블의 값이 현재 비교할 값보다 작으면 안 봐도 되니까 continue;

			for (int i = 0;i < 4;i++) {
				int next_x = cur_x + dx[i];
				int next_y = cur_y + dy[i];

				if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;

				if (dist[next_x][next_y] > graph[next_x][next_y] + cur_Dist) {
					dist[next_x][next_y] = graph[next_x][next_y] + cur_Dist;
					pq.push({ dist[next_x][next_y],{next_x, next_y} });
				}
			}
		}

		cout << "Problem " <<  T << ": " << dist[N - 1][N - 1] << '\n';
	}

	return 0;
}


/*

0   INF INF
INF INF INF
INF INF INF


5 5 4
3 9 1
3 2 7
*/