#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int n;
long long dp[50];

long long go(int now){
    if(now==0 || now==1) return now;
    if(dp[now]!=-1) return dp[now];
    long long &res=dp[now];
    return res=go(now-1)+go(now-2);
}

int main(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<go(n);
}