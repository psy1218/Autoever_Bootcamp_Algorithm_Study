#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

int N,K,ans;
vector<int> v, diff;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>N>>K;
    if(N<K){
        cout<<0;
        return 0;
    }
    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    // for(auto a : v){
    //     cout<< a<<' ';
    // }
    // cout<<endl;
    for(int i=1; i<v.size(); i++){
        diff.push_back({v[i]-v[i-1]});
    }
    sort(diff.begin(), diff.end());
    // for(auto a : diff){
    //     cout<< a<<' ';
    // }
    for(int i=0; i<N-K; i++){
        ans+=diff[i];
    }
    cout<<ans;
}