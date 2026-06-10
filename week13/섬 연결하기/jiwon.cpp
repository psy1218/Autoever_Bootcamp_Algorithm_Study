#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

bool cmp(vector<int>& a, vector<int>& b){
    return a[2]<b[2];
}

int findParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x]);
}

void unionParent(int u, int v){
    int a=findParent(u);
    int b=findParent(v);
    if(a<b){
        parent[b]=a;
    }
    else{
        parent[a]=b;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    for(int i=0; i<n; i++){
        parent[i]=i;
    }
    int edge=0;
    for(int i=0; i<costs.size(); i++){
        if(edge==n-1) break;
        int u=findParent(costs[i][0]);
        int v=findParent(costs[i][1]);
        if(u!=v){
            unionParent(costs[i][0],costs[i][1]);
            answer+=costs[i][2];
            edge++;
        }
    }
    return answer;
}