#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool compare(pair<pair<int,int>,int> a , pair<pair<int, int>, int> b) {
	if (a.first.second == b.first.second) return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}

int main() {

	vector<pair<pair<int, int>, int>>dis;
	int dp[10001] = { 0, };
	int N, D, start, end, distance;

	fill(dp, dp + 10001, INT_MAX);

	cin >> N >> D;
	for (int i = 0;i < N;i++) {
		cin >> start >> end >> distance;
		dis.push_back({ {start, end}, distance });
	}

	sort(dis.begin(), dis.end(), compare);

	//for (auto it : dis) {
	//	cout << it.first.first << " " << it.first.second << " " << it.second << '\n';
	//}

	int j = 0;
	dp[0] = 0;
	for (int i = 1;i < 10001;i++) {
		if (j >= N) {
			dp[i] = dp[i - 1] + 1;
			continue;
		}

		if (i == dis[j].first.second) {
			while (1) { // 똑같은 도착위치가 여러 개일 때를 대비 
				if (j >= N) break;
				if (i != dis[j].first.second) break;

				if (i == dis[j].first.second) { // 지름길이면,
					dp[i] = min(min(dp[i - 1] + 1, dp[dis[j].first.first] + dis[j].second), dp[i]);
					j++;
					// 지름길이 아닐 때/ 지름길 전의 길이 + 지름길의 길이를 더해서 더 작은 값 / 현재 dp 값 
				}
			}
		}
		
		else dp[i] = dp[i - 1] + 1;
		
	}

	cout << dp[D] << '\n';

	return 0;
}
/*
2 10
1 6 4
5 9 2


0 1 2 3 4 5 6 7 8 9 10
0 1 2 3 4 5 5 6 7 7 8 
* 
* 
0 1 2 3 4 5 6 7 8 9 10
0 1 2 3 4 5 5 6 7 7 8 

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
0 1 2 3 4 1 2 3 4 5 2  3   4  5  6  7

5 150
0 50 10
0 50 20
50 100 10
100 151 10
110 140 90

0 50 10
0 50 20
50 100 10
110 140 90
100 151 10

0부터 시작해서 50까지 

10 , 50 -> 10


10 60 40
50 90 20

0 10 60 100 - 90
0 50 90 100 - 80

2 10
1 6 4
5 9 2


0 1 2 3 4 5 6 7 8 9 10
0 1 2 3 4 5 5 6 7 7 8 

-> 1 + 4 + 4
-> 5 + 2 + 1 
*/