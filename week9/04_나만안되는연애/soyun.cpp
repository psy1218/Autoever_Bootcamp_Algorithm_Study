#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>>mst;
vector<int>parent;

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]); // 경로 압축까지 한번에 
}

void Union(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);
	if (root_a == root_b) return; // 이미 연결된 건 패스 -> 최단 경로로 이미 저장 됨 

	parent[root_b] = root_a;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, u, v, d;
	char h;

	cin >> N >> M;

	mst.assign(M+ 1, vector<int>(3 + 1));

	vector<int>human(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> h;
		// 남자면 0, 여자면 1
		if (h == 'M') human[i] = 0;
		else human[i] = 1;
	}

	for (int i = 1; i <= M; i++) {
		cin >> u >> v >> d;
		mst[i][1] = d;
		mst[i][2] = u;
		mst[i][3] = v;
	}

	parent.assign(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		parent[i] = i; // 노드가 이어지기 전에 루트는 나 자신 
	}

	sort(mst.begin() + 1, mst.end()); // 1부터 시작이니까 1부터 봐야함. 

	int sum = 0;
	int path = 0;
	for (int i = 1; i <= M; i++) {
		if (human[mst[i][2]] == human[mst[i][3]]) continue; // 같은 성별 대학교 연결은 패스!
		if (find(mst[i][2]) == find(mst[i][3])) continue; // 이미 루트가 같은 경우 = 연결 된 경우도 패스

		Union(mst[i][2], mst[i][3]);
		sum += mst[i][1];
		path += 1;
	}

	if (path == N - 1)	cout << sum << '\n'; // 경로가 다 이어지면 노드 - 1
	else cout << -1 << '\n';

	return 0;
}

/*
1, 5: M, 2,3,4: W

1 2 12
1 3 10
4 2 5
5 2 5
2 5 10
3 4 3
5 4 7

3 4 3
4 2 5
5 2 5
5 4 7
1 3 10
2 5 10
1 2 12

*/