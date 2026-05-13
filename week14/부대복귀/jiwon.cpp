#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> v(n+1);
    for(int i=0; i<roads.size(); i++){
        v[roads[i][0]].push_back(roads[i][1]);
        v[roads[i][1]].push_back(roads[i][0]);
    }
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(destination);
    dist[destination]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++){
            int y=v[x][i];
            if(dist[y]==-1){
                dist[y]=dist[x]+1;
                q.push(y);
            }
        }
    }
    for(int s : sources){
        answer.push_back(dist[s]);
    }
    return answer;
}