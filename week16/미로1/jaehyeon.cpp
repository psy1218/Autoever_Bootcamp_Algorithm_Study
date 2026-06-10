#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> v(16, vector<int>(16));
vector<vector<bool>> vis(16, vector<bool>(16));

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};
bool goal = false;

void dfs(int x, int y)
{
    if (goal) return;

    if (x < 0 || x>15 || y < 0 || y>15) return;
    if (vis[x][y] == 1 || v[x][y] == 1) return;
    if (v[x][y] == 3){
        goal = true;
        return;
    }
    
    vis[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        dfs(x + mx[i], y + my[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int tc = 1; tc <= 10; tc++)
    {
        int n;
        cin >> n;

        goal = 0;
        int sx = 0, sy = 0;

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                char c;
                cin >> c;

                v[i][j] = c - '0';
                vis[i][j] = false;

                if (v[i][j] == 2) {
                    sx = i;
                    sy = j;
                }
            }
        }

        dfs(sx, sy);

        cout << "#" << tc << " " <<goal << "\n";
    }

    
    return 0;
}