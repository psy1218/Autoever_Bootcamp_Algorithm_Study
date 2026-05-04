#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> num;

bool check(int n){ // 소수인지 확인
    if(n<2) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

bool val(){
    for(int i=0; i<N; i++){
        int n=0;
        for(int j=0; j<=i; j++){
            n+=num[j]*pow(10, i-j);
        }
        if(!check(n)) return false;
    }
    return true;
}

void go(int idx){
    if(num.size()==N){
        if(val()){
            for(int x : num){
                cout<<x;
            }
            cout<<"\n";
        }
        return;
    }
    for(int i=1; i<=9; i++){
        num.push_back(i);
        go(idx+1);
        num.pop_back();
    }
}

int main(){
    cin>>N;
    go(0);
    return 0;
}