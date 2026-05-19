#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    //freopen("input.txt", "r", stdin);
 
    int t;
    for (int T = 1; T <= 10; T++) {
        cin >> t;
        int board[100][100];
 
        int x = 99, y;
 
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> board[i][j];
                if (board[i][j] == 2) y = j;
            }
        }
 
        int res = 0;
 
        while (x >= 0) {
            if (x == 0) {
                res = y ;
                break;
            }
 
            if (y - 1 < 0 || board[x][y - 1] == 0) {
                if (y + 1 >= 100 || board[x][y + 1] == 0) {
                    x--;
                }
            }
 
            if (y - 1 >= 0 && board[x][y - 1] == 1) {
                while (y - 1 >= 0 && board[x][y - 1] != 0) {
                    board[x][y - 1] = 0;
                    y--;
                }
                continue;
            }
 
            if (y + 1 < 100 && board[x][y + 1] == 1) {
                while (y + 1 < 100 && board[x][y + 1] != 0) {
                    board[x][y + 1] = 0;
                    y++;
                }
                continue;
            }
 
        }
 
        //cout << "x: " << x << "y: " << y << '\n';
 
        //for (int i = 0; i < 100; i++) {
        //  for (int j = 0; j < 100; j++) {
        //      cout << board[i][j] ;
        //      
        //  }
        //  cout << '\n';
        //}
 
 
        cout << "#" << T << " " << res << '\n';
    }
 
 
    return 0;
}