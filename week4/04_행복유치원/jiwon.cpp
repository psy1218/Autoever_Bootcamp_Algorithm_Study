#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 

int N,K,ans;
vector<int> stu;
priority_queue<int, vector<int>, greater<int>> diff;

int main(){
    cin>>N>>K;
    for(int i=0; i<N; i++){
        int h;
        cin>>h;
        stu.push_back(h);
    }
    for(int i=1; i<N; i++){
        diff.push(stu[i]-stu[i-1]);
    }
    // while(!diff.empty()){
    //     cout<<diff.top()<<' ';
    //     diff.pop();
    // }
    for(int i=0; i<N-K; i++){
        ans+=diff.top();
        diff.pop();
    }
    cout<<ans;
}