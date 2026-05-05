#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

long long N,K;
long long dp[1002][1002];

long long go(long long n, long long k){
    if(k==0) return 1;
    if(n==k) return 1;
    if(k==1) return n;
    long long &res=dp[n][k];
    if(res!=-1) return res;
    return res=(go(n-1,k-1)+go(n-1,k))%10007;
}

int main(){
    cin>>N>>K;
    memset(dp, -1, sizeof(dp));
    cout<<go(N,K);
}