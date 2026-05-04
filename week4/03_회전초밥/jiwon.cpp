#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 

// N 손님 M 초밥
int N,M;
vector<int> list[100001];
unordered_map<int, int> umap;
vector<int> cnt;

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int k;
        cin>>k;
        for(int j=0; j<k; j++){
            int a;
            cin>>a;
            list[i].push_back(a);
        }
    }
    for(int i=0; i<M; i++){
        int b;
        cin>>b;
        umap[b]++;
    }
    for(int i=0; i<N; i++){
        int count=0;
        for(int j=0; j<list[i].size(); j++){
            auto it = umap.find(list[i][j]);
            if (it != umap.end() && (*it).second > 0){
                (*it).second--;
                count++;
            }
        }
        cnt.push_back(count);
    }
    for(int a : cnt){
        cout<<a<<' ';
    }
}