#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MOD = 9901;
    int N;
    cin >> N;

    // dp0: i번째 열까지 배치했을 때, i열이 비어있는 경우
    // dp1: i열 위칸에 사자
    // dp2: i열 아래칸에 사자

    // 우리의 크기가 1개일 때, 빈 칸, 위칸, 아래칸 1개씩 
    long long dp0 = 1, dp1 = 1, dp2 = 1; // i=1 기준 (빈/위/아래)

    for (int i = 2; i <= N; i++) {
        long long ndp0 = (dp0 + dp1 + dp2) % MOD;
        long long ndp1 = (dp0 + dp2) % MOD; // 바로 왼쪽 위칸은 비어야 함
        long long ndp2 = (dp0 + dp1) % MOD; // 바로 왼쪽 아래칸은 비어야 함

        dp0 = ndp0;
        dp1 = ndp1;
        dp2 = ndp2;
    }

    cout << (dp0 + dp1 + dp2) % MOD << "\n";
    return 0;
}