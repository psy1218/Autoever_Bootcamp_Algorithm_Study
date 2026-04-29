#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(vector<string>& maps, pair<int,int> start, char target) {
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (maps[x][y] == target) {
            return dist[x][y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maps[nx][ny] == 'X') continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    pair<int,int> S, L;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'S') S = {i, j};
            if (maps[i][j] == 'L') L = {i, j};
        }
    }

    int toLever = bfs(maps, S, 'L');
    if (toLever == -1) return -1;

    int toExit = bfs(maps, L, 'E');
    if (toExit == -1) return -1;

    return toLever + toExit;
}