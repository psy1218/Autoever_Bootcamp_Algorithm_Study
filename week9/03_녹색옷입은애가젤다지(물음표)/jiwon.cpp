#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

const int INF=1e9;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int N, T;
int a[130][130];
vector<int> dist(15630);
vector<pair<int, int>> adj[20004];

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0]=a[0][0];
    pq.push({dist[0],0});
    while(!pq.empty()){
        int here_cost=pq.top().first;
        int u=pq.top().second;
        pq.pop();

        if(dist[u]!=here_cost) continue;
        
        for(auto &[v, weight] : adj[u]){
            int new_cost=here_cost+weight;
            if(new_cost<dist[v]){
                dist[v]=new_cost;
                pq.push({new_cost, v});
            }
        }
    }
}

int main(){
    while(cin>>N){
        if(N==0) break;
        T++;
        fill(dist.begin(), dist.end(), INF);
        for(int i=0; i<N*N; i++) adj[i].clear();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>a[i][j];
            }   
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<4; k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                    adj[N*i+j].push_back({nx*N+ny, a[nx][ny]});
                }
            }
        }
        dijkstra();
        cout<<"Problem "<<T<<": "<<dist[N*N-1]<<'\n';
    }
}