#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

string S,T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>S>>T;
    while(T.size()>S.size()){
        if(T.back()=='A'){
            T.pop_back();
        }
        else{
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    if(T==S) cout<<1;
    else cout<<0;
}