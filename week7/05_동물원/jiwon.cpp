#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int N;
long long dp[100004];

long long go(int n){
    if(n==0) return 1;
    if(n==1) return 3;
    long long &res=dp[n];
    if(res!=-1) return res;
    return res=(go(n-1)*2+go(n-2))%9901;
}

int main(){
    cin>>N;
    memset(dp, -1, sizeof(dp));
    cout<<go(N);
}