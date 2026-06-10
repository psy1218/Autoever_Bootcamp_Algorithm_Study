#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> parent;

int find(int x)
{
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x]);
}

void unite(int a, int b)
{
    a=find(a);
    b=find(b);
    
    if(a!=b) parent[b]=a;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt=0;
    
    parent.resize(n);
    
    for(int i=0; i<n; i++) parent[i]=i;
    
    sort(costs.begin(), costs.end(), [](const auto& a, const auto& b){
        return a[2]<b[2];
    });
    
    for(int i=0; i<costs.size(); i++)
    {
        if(find(costs[i][0])==find(costs[i][1])) continue;
        unite(costs[i][0], costs[i][1]);
        answer+=costs[i][2];
        cnt++;
        if(cnt==n-1) break;
    }
    
    
    return answer;
}