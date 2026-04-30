#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N;
	cin >> N;
	vector<vector<int>>board(N, vector<int>(N, 0));
	vector<vector<long long>>dp(N, vector<long long>(N, 0)); // 각 칸에 몇 가지 방법으로 왔는지. 

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> board[i][j];
		}
	}

	dp[0][0] = 1; //시작점
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (i == N - 1 && j == N - 1) continue; // 도착
			if (dp[i][j] == 0) continue; // 경로에 도달하지 않는 경우, 경로는 미리 증가시킴. 
			
			int jump = board[i][j];
			if (i + jump < N) { // 범위 안 넘어가게! 
				dp[i + jump][j] += dp[i][j];
			}
			if (j + jump < N) {
				dp[i][j + jump] += dp[i][j];
			}
			
		}
	}

	cout << dp[N - 1][N - 1] << '\n';


	return 0;
}

/*

4
2 3 3 1
1 2 1 3
1 2 3 1
3 1 1 0

1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0


처음에 일단 예외처리를 해. board[0][0] 이 N보다 같거나 크면 일단 출발도 못 하니까 경로는 0 가능하면 일단 위 아래로 두 갈래 가능하니까 cnt 시작을 2부터 해. 
그리고 각각 나뉘어서 가. 예를 들어서 4 2 3 3 1 1 2 1 3 1 2 3 1 3 1 1 0 이거이면, 시작하면 0,2와 2,0 가지. 0,2일 때 3칸이니까 오른쪽은 칸 넘으니까 못 가고, 아래로 3,2 가 돼. 
이 때 경로는 1개였으니까 cnt 는 유지해. 증가를 안 한거지. 그리고 3,2일 때 1인데 아래로는 못 가고 오른쪽으로 가서 0 이 되니까 가능. 
그리고 2,0일때는 1일야. 아래 오른쪽 다 갈 수 있어. 갈 수 있는 경로 2개니까 cnt=2에서 +1을 하나해줘. 경로가 1개일때는 cnt 추가 안 하고 2개일 때는 cnt 한 개 추가해주는거지. 
아무튼 이런 식으로 이동해서 cnt 최종 계산을 하는 거야. 근데 대신 이동하다가 결국 끝이 board[N-1][N-1] 이 아니면 cnt -1 을 해서 경로를 뺴는 거야.

-> 틀림


경로를 직접 따라가며 cnt를 세는 게 아니라, 각 칸에 “몇 가지 방법으로 왔는지”를 저장하는 문제다.
*/