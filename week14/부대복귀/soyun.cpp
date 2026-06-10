#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>>graph(n+1);
    vector<int>dist(n+1, -1);
    for(int i =0;i<roads.size();i++){
        int a = roads[i][0];
        int b = roads[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dist[destination] = 0;
    
    queue<int>q;
    q.push(destination);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0;i<graph[cur].size();i++){ // push_back 하면 인덱스 범위는 0 부터 시작이라서 i = 0  .  i  = 1이 아님. 
            if(dist[graph[cur][i]] == -1){
                dist[graph[cur][i]] = dist[cur] + 1;
                q.push(graph[cur][i]);
            }
        }
    }
    
    for(int i=0;i<sources.size();i++){
        answer.push_back(dist[sources[i]]);
    }
    
    return answer;
}

// 난 보자마자 다익스트라 생각했는데 비용이 1로 똑같아서 bfs 로 푸는게 더 좋은 방법. 
/*
[[1, 2], [1, 4], [2, 4], [2, 5], [4, 5]]	[1, 3, 5]	5	[2, -1, 0]
1: 2, 4
2: 1, 4, 5
3:
4: 1, 2, 5
5: 2, 4

1 2 3 4 5
2  1   1
*/