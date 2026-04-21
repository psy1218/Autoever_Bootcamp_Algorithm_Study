#include <iostream>
#include <string>
using namespace std;

int solution(string s) 
{ 
    int answer=0;
    int N=s.size();
    int dp[2503][2503];
    for(int i=1; i<=N; i++){
        dp[i][i]=1;
    }
    for(int i=0; i<N-1; i++){
        if(s[i]==s[i+1]){
            dp[i+1][i+2]=1;
        }
    }
    for(int len=3; len<=N; len++){
        for(int i=1; i<=N-len+1; i++){
            int j=i+len-1;
            if(s[i-1]==s[j-1] && dp[i+1][j-1]==1){
                dp[i][j]=1;
            }
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(dp[i][j]==1){
                answer=max(answer, j-i+1);
            }
        }
    }
    return answer;
}