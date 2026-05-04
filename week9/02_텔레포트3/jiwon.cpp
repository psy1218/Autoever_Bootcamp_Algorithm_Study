#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

long long dist[8][8];
vector<pair<long long, long long>> v;

int main(){
    for(int i=0; i<8; i++){
        long long x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            dist[i][j]=abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second);
        }
    }
    for(int i=1; i<=3; i++){
        int u=2*i, v=2*i+1;
        dist[u][v]=min(dist[u][v], 10LL); 
        dist[v][u]=min(dist[v][u], 10LL);
    }
    for(int k=0; k<8; k++){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    cout<<dist[0][1];
    return 0;
}