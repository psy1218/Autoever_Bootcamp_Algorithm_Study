#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <string>

using namespace std;

int arr[11];
int cnt;

bool check(int x) {
    for (int i = 0; i < x; i++)
    {
        if (arr[x] == arr[i]) return false;
        if (abs(arr[x] - arr[i]) == x - i) return false;
    }
    return true;
}

void dfs(int x, int n) {
    if (x == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        arr[x] = i;
        if (check(x)) dfs(x + 1, n);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        cin >> n;
        cnt = 0;
        

        dfs(0, n);

        cout << "#" << tc << " " << cnt << "\n";
    }

    
    return 0;
}