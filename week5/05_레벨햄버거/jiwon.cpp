#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long N,X;
long long l[51], p[51];
long long cnt;

void count(int n){
    l[0]=1; p[0]=1;
    for(int i=1; i<=n; i++){
        l[i]=2*l[i-1]+3;
        p[i]=2*p[i-1]+1;
    }
}

long long solve(long long n, long long x){
    if(n==0){
        cnt=(x==1)? 1: 0;
    }
    else if(x==1){
        cnt=0;
    }
    else if(x<l[n]/2+1){
        cnt=solve(n-1, x-1);
    }
    else if(x==l[n]/2+1){
        cnt=p[n-1]+1;
    }
    else if(x<l[n]){
        cnt=p[n-1]+1+solve(n-1, x-(l[n]/2+1));
    }
    else{
        cnt=p[n];
    }
    return cnt;
}

int main(){
    cin>>N>>X;
    count(N);
    // cout<<l[N]<<' '<<p[N-1];
    cout<<solve(N,X);
}