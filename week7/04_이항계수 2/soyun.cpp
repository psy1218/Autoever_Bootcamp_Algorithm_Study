#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MOD = 10007;
    int N, K;
    cin >> N >> K;

    int C[1001][1001]; // 0으로 자동 초기화

    for (int n = 0; n <= N; n++) {
        C[n][0] = 1;      // C(n,0)=1
        C[n][n] = 1;      // C(n,n)=1
        for (int k = 1; k < n; k++) {
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
        }
    }

    cout << C[N][K] << "\n";
    return 0;
}

/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1 

양 끝은 항상 1 = 0개 고르거나 전부 고르기 

파스칼의 삼각형
*/