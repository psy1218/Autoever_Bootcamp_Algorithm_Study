#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std; 

int N,K,ans;
vector<int> num;
int arr[9];
int mx=-1;

void func(int depth){
    if(depth<=to_string(N).length()){
        ans=0;
        for(int j=0; j<depth; j++){
            ans+=arr[j]*pow(10,j);
        }
        // cout<<ans<<endl;
        if(ans<=N){
            mx=max(mx,ans);
        }
    }
    else{
        return;
    }
    for(int i=0; i<K; i++){
        arr[depth]=num[i];
        func(depth+1);
    }
}

int main(){
    cin>>N>>K;
    for(int i=0; i<K; i++){
        int a;
        cin>>a;
        num.push_back(a);
    }
    func(0);
    cout<<mx;
}