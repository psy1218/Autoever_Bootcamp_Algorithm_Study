#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int L,C;
vector<char> chars, ans;

bool val(){
    int v=0, c=0;
    for(char x : ans){
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
            v++;
        }
        else c++;
    }
    return (v>=1 && c>=2);
}

void go(int idx){
    if(ans.size()==L){
        if(val()){
            for (char x : ans){
                cout<<x;
            }
            cout<<'\n';
        }
        return;
    }
    for(int i=idx; i<C; i++){
        ans.push_back(chars[i]);
        go(i+1);
        ans.pop_back();
    }
}

int main(){
    cin>>L>>C;
    for(int i=0; i<C; i++){
        char c;
        cin>>c;
        chars.push_back(c);
    }
    sort(chars.begin(),chars.end());
    go(0);
    return 0;
}