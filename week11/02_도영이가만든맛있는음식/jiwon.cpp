#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> s;
int mul=1;
int sum,diff;
int MIN=1e9;

void cal(){
    diff=abs(mul-sum);
    MIN=min(MIN,diff);
}

void go(int idx, int depth){
    if(idx==depth){
        cal();
        // mul=1;
        // sum=0;
        return;
    }
    for(int i=idx; i<N; i++){
        mul*=s[i].first;
        sum+=s[i].second;
        go(i+1, depth);
        mul/=s[i].first;
        sum-=s[i].second;
    }
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        int a,b;
        cin>>a>>b;
        s.push_back({a,b});
    }
    for(int i=1; i<=N; i++){
        go(0,i);
    }
    cout<<MIN;
    return 0;
}