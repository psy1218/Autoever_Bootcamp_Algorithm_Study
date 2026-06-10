#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < roads.size(); i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> dist(n + 1, -1);
    
    queue<int> q;
    q.push(destination);
    dist[destination] = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : graph[cur]) {
            if (dist[next] != -1) continue;
            
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
    
    for (int i = 0; i < sources.size(); i++) {
        answer.push_back(dist[sources[i]]);
    }
    
    return answer;
}