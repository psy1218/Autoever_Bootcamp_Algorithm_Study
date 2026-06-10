#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

// x,y를 정점으로 보고 다익스트라로 풀기 
// 중요한 점 8개를 그래프로 만들고, 점들 사이 걷기/텔레포트 비용을 간선으로 넣은 뒤, 
// 0번(시작)에서 1번(도착)까지 다익스트라로 최단거리를 구하는 코드야.

int main() {
	long long x, y;

	vector<pair<long long, pair<long long,long long>>>info(8);
	
	for (long long i = 0;i < 8;i++) { //시작, 끝 노드는 각각 0, 1 노드 
		cin >> x >> y;
		info[i].first = i;
		info[i].second.first = x;
		info[i].second.second = y;
	}

	vector<vector<pair<long long,long long>>>graph(8);

	// 정점들의 연결 -> 간선 추가 = 가중치 포함해서 최소 찾기 = 아직 최단 거리는 안 찾음. 
	for (long long i = 0;i < 8;i++) {
		for (long long j = 0;j < 8;j++) {
			if (i == j) continue; // 나 자신과 비교 할 필요 없음. 
			long long dis = abs(info[i].second.first - info[j].second.first) + abs(info[i].second.second - info[j].second.second); //jump
			if ((i == 2 && j == 3) || (i == 4 && j == 5) || (i == 6 && j == 7) ) { // 텔레포트 
				graph[i].push_back({ j, min((long long)10, dis) }); 
				graph[j].push_back({ i, min((long long)10, dis) });
			}
			graph[i].push_back({ j, dis });
			graph[j].push_back({ i, dis });
		}
	}

	// 최단 거리 찾기 = 다익스트라 이용
	vector<long long>dist(8, LLONG_MAX);
	dist[0] = 0;

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
	pq.push({ 0,0 }); // 거리, 정점
	while (!pq.empty()) {
		auto cur = pq.top();
		long long cur_dis = cur.first;
		long long cur_node = cur.second;
		pq.pop();

		if(cur_dis > dist[cur_node]) continue; // cur_node 의 dist가 더 작으면 계속!  

		for (auto next : graph[cur_node]) {
			long long next_dis = next.second;
			long long next_node = next.first;

			if (dist[next_node] > dist[cur_node] + next_dis) { // 기존의 다음 dist 와 현재의 거리 + weight 
				dist[next_node] = dist[cur_node] + next_dis;
				pq.push({ next_dis, next_node });
			}
		}

	}

	cout << dist[1] << '\n';

	return 0;
}

/*
노드 8개 만들고 간선 연결해서 최소 찾으면 됨. 

0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 s 0 0
0 0 0 0 0 0
0 0 0 0 e 0

s 0 0 0 0 0 0 0 0 0 0
0 t 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 t 0 e


*/