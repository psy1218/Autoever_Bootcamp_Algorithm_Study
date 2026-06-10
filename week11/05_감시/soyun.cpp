#if 1
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Info {
	int x;
	int y;
	int cctv;
};

// 회전 순서도 중요함. 난 우,좌,상,하인데,
// 회전 순서로 바꿔야함!! 중요!! 
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M, zero_size = 0;
vector<vector<int>>board;
vector<vector<int>>copy;

vector<Info>xy;

int Min = INT_MAX;

int watch(vector<vector<int>>& temp, int x, int y, int i) {
    int cnt = 0;
    int index = i % 4; // 방향

    int nx = x + dx[index];
    int ny = y + dy[index];

    while (1) {
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;

        if (temp[nx][ny] == 6) break;

        if (temp[nx][ny] == 0) {
            cnt++;
            temp[nx][ny] = -1;
        }
    
        nx += dx[index];
        ny += dy[index];
    }

    return cnt;

}

void dfs(int idx, int watched, vector<vector<int>>& temp) {
    if (idx == xy.size()) { // CCTV 개수 저장한 xy에 대한 인덱스! -> 넘으면 인덱스 오류 
        Min = min(Min, zero_size - watched);
        return;
    }

    int x = xy[idx].x;
    int y = xy[idx].y;

    if (xy[idx].cctv == 1) { // 4방향
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> copy = temp;
            int add = watch(copy, x, y, i);
            dfs(idx + 1, watched + add, copy);
        }
    }
    if (xy[idx].cctv == 2) {
        for (int i = 0; i < 2; i++) {
            vector<vector<int>> copy = temp;
            int add = 0;
            add += watch(copy, x, y, i);
            add += watch(copy, x, y, i + 2);
            dfs(idx + 1, watched + add, copy);
        }
    }
    if (xy[idx].cctv == 3) {
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> copy = temp;
            int add = 0;
            add += watch(copy, x, y, i);
            add += watch(copy, x, y, i + 1);
            dfs(idx + 1, watched + add, copy);
        }
    }
    if (xy[idx].cctv == 4) {
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> copy = temp;
            int add = 0;
            add += watch(copy, x, y, i);
            add += watch(copy, x, y, i + 1);
            add += watch(copy, x, y, i + 2);
            dfs(idx + 1, watched + add, copy);
        }
    }
    if (xy[idx].cctv == 5) {
        vector<vector<int>> copy = temp;
        int add = 0;
        for (int i = 0; i < 4; i++) {
            add += watch(copy, x, y, i);
        }
        dfs(idx + 1, watched + add, copy);
    }
    
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	int num;
	board.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			board[i][j] = num;
			if (num == 0) zero_size++;
			if (num != 0 && num != 6) xy.push_back({ i, j , num });
		}
	}

    dfs(0, 0, board);

    cout << Min << '\n';

	return 0;
}

/*

0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 6 0
0 0 0 0 0 0
0 0 0 2 0 0


*/

#endif

#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info {
    int x;
    int y;
    int cctv;
};

int N, M;
int answer = 1e9;
int zero_size = 0;

vector<vector<int>> board;
vector<Info> xy;

// 상 우 하 좌
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 한 방향으로 감시하고, 새롭게 감시된 0의 개수를 반환
int watch(vector<vector<int>>& temp, int x, int y, int dir) {
    int cnt = 0;
    dir %= 4;

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    while (nx >= 0 && nx < N && ny >= 0 && ny < M) {
        if (temp[nx][ny] == 6) break;   // 벽이면 중단

        if (temp[nx][ny] == 0) {
            temp[nx][ny] = -1;          // 감시 표시
            cnt++;
        }
        // CCTV(1~5), 이미 감시된 칸(-1)은 그냥 통과

        nx += dx[dir];
        ny += dy[dir];
    }

    return cnt;
}

void dfs(int idx, vector<vector<int>> temp, int watched) {
    if (idx == xy.size()) {
        answer = min(answer, zero_size - watched);
        return;
    }

    int x = xy[idx].x;
    int y = xy[idx].y;
    int type = xy[idx].cctv;

    if (type == 1) {
        for (int d = 0; d < 4; d++) {
            vector<vector<int>> copy = temp;
            int add = watch(copy, x, y, d);
            dfs(idx + 1, copy, watched + add);
        }
    }
    else if (type == 2) {
        for (int d = 0; d < 2; d++) {
            vector<vector<int>> copy = temp;
            int add = 0;
            add += watch(copy, x, y, d);
            add += watch(copy, x, y, d + 2);
            dfs(idx + 1, copy, watched + add);
        }
    }
    else if (type == 3) {
        for (int d = 0; d < 4; d++) {
            vector<vector<int>> copy = temp;
            int add = 0;
            add += watch(copy, x, y, d);
            add += watch(copy, x, y, d + 1);
            dfs(idx + 1, copy, watched + add);
        }
    }
    else if (type == 4) {
        for (int d = 0; d < 4; d++) {
            vector<vector<int>> copy = temp;
            int add = 0;
            add += watch(copy, x, y, d);
            add += watch(copy, x, y, d + 1);
            add += watch(copy, x, y, d + 2);
            dfs(idx + 1, copy, watched + add);
        }
    }
    else if (type == 5) {
        vector<vector<int>> copy = temp;
        int add = 0;
        for (int d = 0; d < 4; d++) {
            add += watch(copy, x, y, d);
        }
        dfs(idx + 1, copy, watched + add);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    int num;
    board.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> num;
            board[i][j] = num;

            if (num == 0) zero_size++;
            if (num != 0 && num != 6) {
                xy.push_back({ i, j, num });
            }
        }
    }

    dfs(0, board, 0);

    cout << answer << '\n';
    return 0;
}
#endif