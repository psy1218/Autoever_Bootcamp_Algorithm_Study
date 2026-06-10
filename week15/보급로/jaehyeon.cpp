#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++)
    {
        int N;
        cin >> N;

        vector<vector<int>> road(N, vector<int>(N));
        vector<vector<int>> dist(N, vector<int>(N, 1e9));

        for(int i = 0; i < N; i++)
        {
            string s;
            cin >> s;

            for(int j = 0; j < N; j++)
            {
                road[i][j] = s[j] - '0';
            }
        }

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty())
        {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(cost > dist[x][y]) continue;

            for(int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                int nextCost = cost + road[nx][ny];

                if(nextCost < dist[nx][ny])
                {
                    dist[nx][ny] = nextCost;
                    pq.push({nextCost, {nx, ny}});
                }
            }
        }

        cout << "#" << tc << " " << dist[N - 1][N - 1] << "\n";
    }

    return 0;
}