#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int N,D;
int dp[10001];

struct s {
    int start, end, dist;
};

bool cmp(s a, s b){
    return a.start<b.start;
}

vector<s> v;

int main(){
    cin>>N>>D;
    for(int i=0; i<=D+1; i++){
        dp[i]=i;
    }
    for(int i=0; i<N; i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(D<b || b-a<=c) continue;
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end(),cmp);
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i].start<<' '<<v[i].end<<' '<<v[i].dist<<endl;
    // }
    for(int i=0; i<v.size(); i++){
        dp[v[i].end]=min(dp[v[i].end],dp[v[i].start]+v[i].dist);
        for(int j=v[i].end+1; j<=D+1; j++){
            dp[j]=min(dp[j-1]+1,dp[j]);
        }
    }
    cout<<dp[D];
}