#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker){
    int answer = 0;
    
    // 스티커 개수에 따라 예외처리해주기(3개 미만일 때)
    int len = sticker.size();
    
    // 이렇게 끝나면 안 됨. 밑에 계산도 돼서, 여기서 return 해줘야함. 
    // if(len == 1) answer = sticker[0];
    // if(len == 2) answer = max(sticker[0], sticker[1]);
    if(len == 1) return sticker[0];
    if(len == 2) return max(sticker[0], sticker[1]);
    
    // 시작 사용
    vector<int>dp1;
    dp1.push_back(sticker[0]);
    dp1.push_back(max(sticker[0], sticker[1])); // 1하면 안 되는데! 0에서 이미 사용했으니까. 
    
    for(int i=2;i<len-1;i++){ // 시작 사용했으니까 마지막 사용하면 안 됨.
        dp1.push_back(max(dp1[i-1], dp1[i-2] + sticker[i]));
    }
    
    // 마지막 사용
    vector<int>dp2;
    dp2.push_back(0);
    dp2.push_back(sticker[1]);
    for(int i=2;i<len;i++){ // 시작 사용 안 했으니까 마지막 사용
        dp2.push_back(max(dp2[i-1], dp2[i-2] + sticker[i]));
    }
    
    //for(auto it: dp2) cout << it << ' ';
    
    answer = max(dp1[dp1.size()-1], dp2[dp2.size()-1]);
    return answer;
}


/*
그리디로 풀려다가 최적의 결과 안 나올 거 같아서, 백트래킹 생각했는데 -> 시간 초과 ->DP 접근 

    - 백트래킹 -
    각 스티커마다
    뜯는다
    안 뜯는다

    두 선택이 있으니까
    경우의 수가 거의 2^N 수준으로 커져서
    N = 100000은 절대 못 버텨.
    
    - DP -
    [14, 6, 5, 11, 3, 9, 2, 10]
    시작
    dp[0] = 14
    dp[1] = 14
    dp[2] = 14, 14 + 5 = 19
    dp[3] = 19, 14 + 11 = 25
    dp[4] = 25, 19 + 3 = 22
    dp[5] = 22, 25 + 9 = 34
    dp[6] = 34, 22 + 2 = 24
    dp[7] -> 처음해서 안됨.
    
    마지막 
    dp[0] = 0 -> 마지막 사용했으니까 처음은 안 됨. 
    dp[1] = 6
    dp[2] = 6, 0 + 5 = 6
    dp[3] = 6, 6 + 11 = 17
    dp[4] = 17, 6 + 3 = 9
    dp[5] = 9, 17 + 9 = 26
    dp[6] = 26, 26 + 2 = 28
    dp[7] = 28, 26 + 10 = 26 
*/

/*
int solution(vector<int> sticker)
{
    int answer =0;

    vector<int>around;
    around.push_back(sticker[1]+sticker[sticker.size()-1]);
    for(int i=1;i<sticker.size()-1;i++){
        around.push_back(sticker[i-1]+sticker[i+1]);
    }
    around.push_back(sticker[0]+sticker[sticker.size()-2]);

    for(auto it:around){
        cout << it << ' ';
    }

    return answer;
}
*/

/*
[14, 6, 5, 11, 3, 9, 2, 10] -> 가장 크려면 뜯어지는게 작아야함. 
6, 11, 9, 10

[1, 3, 2, 5, 4]
3, 5

*/