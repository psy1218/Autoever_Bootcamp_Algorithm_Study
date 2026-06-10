#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int>parent(100);

bool compare(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}

int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

void Union(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a == root_b) return;
    parent[root_b] = root_a;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0;i<100;i++){
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), compare);
    
    for(int i=0;i<costs.size();i++){
        if(find(costs[i][0]) == find(costs[i][1])) continue;
        
        Union(costs[i][0], costs[i][1]);
        answer += costs[i][2];
    }
    
//     for(auto it: costs){
        
//             cout << it[0] << ' ' << it[1] << ' ' << it[2] << '\n';
        
//     }
    
    
    return answer;
}