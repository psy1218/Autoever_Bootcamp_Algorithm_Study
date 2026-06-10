#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int N, res;
int a[1001];
int cnt[1001];

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    for(int i=0; i<N; i++){
        int val=0;
        for(int j=0; j<i; j++){
            if(a[i]<a[j] && val<cnt[j]){
                val=cnt[j];
            }
        }
        cnt[i]=val+1;
        res=max(res,cnt[i]);
    }
    cout<<res;
}