#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 

int T,N;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N;
        int cnt=0;
        int mn=1e9;
        v.clear();
        for(int j=0; j<N; j++){
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(), v.end());
        for(auto it : v){
            if(it.second<mn){
                cnt++;
                mn=it.second;
            }
        }
        cout<<cnt<<'\n';
    }
}