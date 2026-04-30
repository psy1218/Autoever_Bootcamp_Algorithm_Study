#include <iostream>
#include <cstring>
using namespace std;

using ull = unsigned long long;

ull memo[31][31]; // N<=30

ull solve(int w, int h) {
    if (w == 0 && h == 0) return 1; // 먹을 약 없을 때 

    ull& ret = memo[w][h];
    if (ret != (ull)-1) return ret; // 계산된 값 

    ret = 0; // 누적합용 -> 초기값이 -1이니까 
    if (h > 0) ret += solve(w, h - 1);      // H 선택 - 갈 수 있는 거
    if (w > 0) ret += solve(w - 1, h + 1);  // W 선택 - 갈 수 있는 거

    // 누가 먼저 시작했는지 
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 메모 테이블 초기화
    for (int i = 0; i <= 30; i++)
        for (int j = 0; j <= 30; j++)
            memo[i][j] = (ull)-1; // -1로 가장 큰 값 초기화 

    // 최대치까지 한 번 계산해두면 여러 테스트케이스 빠름
    solve(30, 0);

    int N;
    while (cin >> N && N != 0) {
        cout << solve(N, 0) << "\n";
    }
    return 0;
}

/*
1,1 일 때
HWH
WHH

시작에 따라 문자열은 2개, H,W로 시작하는거 1개씩 더하기 
*/