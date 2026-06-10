#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

int N,M;
vector<int> v[2001];
bool visit[2001];
bool ans;

void DFS(int i, int depth){
    // cout<<depth<<endl;
    if(depth>=4){
        ans=true;
        return;
    }
    visit[i]=true;
    for(int j=0; j<v[i].size(); j++){
        if(!visit[v[i][j]]){
            DFS(v[i][j], depth+1);
            if(ans) break;
        }
    }
    visit[i]=false;
}

int main(){
    cin>>N>>M;
    for (int i=0; i<M; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=0; i<N; i++){
        DFS(i,0);
    }
    if(ans){
        cout<<1;
    }
    else{
        cout<<0;
    }
}