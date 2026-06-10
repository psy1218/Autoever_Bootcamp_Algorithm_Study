#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <string>

using namespace std;

char arr[101][101];

bool Row_Palin_odd(int x, int y, int l) {
    for (int i = 1; i <= l / 2; i++) {
        if (arr[x][y + (l / 2) - i] == arr[x][y + (l / 2) + i]) continue;
        else return false;
    }
    return true;
}

bool Col_Palin_odd(int x, int y, int l) {
    for (int i = 1; i <= l / 2; i++) {
        if (arr[x + (l / 2) - i][y] == arr[x + (l / 2) + i][y]) continue;
        else return false;
    }
    return true;
}

bool Row_Palin_even(int x, int y, int l) {
    for (int i = 0; i < l / 2; i++) {
        if (arr[x][y + (l / 2) - 1 - i] == arr[x][y + (l / 2) + i]) continue;
        else return false;
    }
    return true;
}

bool Col_Palin_even(int x, int y, int l) {
    for (int i = 0; i < l / 2; i++) {
        if (arr[x + (l / 2) - 1 - i][y] == arr[x + (l / 2) + i][y]) continue;
        else return false;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int tc = 1; tc <= 10; tc++)
    {
        int ans = 0;
        int n;
        cin >> n;

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int l = 100; l > 0; l--) {

            for (int i = 0; i < 100; i++){
                for (int j = 0; j <= 100 - l; j++){
                    if (l % 2 == 1) {
                        if (Row_Palin_odd(i, j, l)) {
                            ans = l;
                            break;
                        }
                    }
                    else {
                        if (Row_Palin_even(i, j, l)) {
                            ans = l;
                            break;
                        }
                    }
                }
                if (ans != 0) break;
            }
            if (ans != 0) break;
            

            for (int i = 0; i <= 100 - l; i++) {
                for (int j = 0; j < 100; j++) {
                    if (l % 2 == 1) {
                        if (Col_Palin_odd(i, j, l)) {
                            ans = l;
                            break;
                        }
                    }
                    else {
                        if (Col_Palin_even(i, j, l)) {
                            ans = l;
                            break;
                        }
                    }
                }
                if (ans != 0) break;
            }
            if (ans != 0) break;
            
        }

        cout << "#" << n << " " << ans << "\n";
    }

    
    return 0;
}