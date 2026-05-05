#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int N;
int dp[1004];

int go(int num){
    if(num==N) return 0;
    if(num>N) return 1;
    int &res=dp[num];
    if(res!=-1) return res;
    if (go(num+1)==0 || go(num+3)==0) return res = 1;
    else return res = 0;
}

int main(){
    cin>>N;
    memset(dp, -1, sizeof(dp));
    if(go(0)%2==0){
        cout<<"CY";
    }
    else{
        cout<<"SK";
    }
}