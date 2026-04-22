#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int dp[100003];

int solution(int n, vector<int> money) {
    int answer = 0;
    sort(money.begin(), money.end());
    // for(int i : money){
    //     cout<<i<<endl;
    // }
    dp[0]=1;
    for(int i : money){
        for(int j=i; j<=n; j++){
            dp[j]=(dp[j]+dp[j-i])%1000000007;
        }
    }
    answer=dp[n];
    return answer;
}