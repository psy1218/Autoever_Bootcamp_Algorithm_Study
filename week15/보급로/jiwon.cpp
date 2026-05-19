#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T,N;
int map[100][100];
int dist[100][100];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

struct Node{
    int y,x,cost;
    bool operator<(const Node& o)const{
        return cost>o.cost;
    }
};

void solve(int tc){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char c;
            cin>>c;
            map[i][j]=c-'0';
            dist[i][j]=1e9;
        }
    }

    priority_queue<Node> pq;
    dist[0][0]=0;
    pq.push({0,0,0});

    while(!pq.empty()){
        Node cur=pq.top();
        pq.pop();

        if(cur.y==N-1 && cur.x==N-1){
            cout<<"#"<<tc<<" "<<cur.cost<<'\n';
            return;
        }

        if(cur.cost>dist[cur.y][cur.x]) continue;

        for(int i=0; i<4; i++){
            int ny=cur.y+dy[i];
            int nx=cur.x+dx[i];

            if(ny<0||ny>=N||nx<0||nx>=N) continue;

            int next_cost=cur.cost+map[ny][nx];
            if(next_cost<dist[ny][nx]){
                dist[ny][nx]=next_cost;
                pq.push({ny,nx,next_cost});
            }
        }
    }
}

int main(){
    cin>>T;
    for(int t=1; t<=T; t++) solve(t);
    return 0;
}