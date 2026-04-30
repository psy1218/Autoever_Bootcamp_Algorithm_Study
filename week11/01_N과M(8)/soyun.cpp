#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int>arr;
vector<int>Data;
vector<int>visited(8, 0);


void dfs(int cnt) {
	if (cnt >= M) {
		for (int i = 0; i < M; i++) {
			cout << Data[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int k = 0; k < N; k++) {
		//if (visited[k] == 1) continue;
		if (!Data.empty() && Data[Data.size() - 1] > arr[k]) continue;
		Data.push_back(arr[k]);
		visited[k] = 1;
		dfs(cnt + 1);
		Data.pop_back();
		visited[k] = 0;
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	
	dfs(0);

	return 0;
}