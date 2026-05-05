#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int K;
int dp[50][2];

int go(int k, int a){ // a=0 A개수 a=1 B개수
    if(k==1){
        if(a==0) return 0;
        else return 1;
    }
    int &res = dp[k][a];
    if(res!=-1) return res;
    if(a==0) res=go(k-1,1);
    if(a==1) res=go(k-1,0)+go(k-1,1);
    return res;
}

int main(){
    cin>>K;
    memset(dp, -1, sizeof(dp));
    cout<<go(K,0)<<' '<<go(K,1);
}