#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> num, v;

void print(){
    for(int i : v){
        cout<<i<<' ';
    }
    cout<<'\n';
}

void go(int idx){
    if(v.size()==M){
        print();
        return;
    }
    for(int i=idx; i<N; i++){
        v.push_back(num[i]);
        go(i);
        v.pop_back();
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        num.push_back(a);
    }
    sort(num.begin(), num.end());
    go(0);
    return 0;
}