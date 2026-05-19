#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int T,N,ans;
string s;
bool visited[10][1000000]; // [교환횟수][숫자값] 중복 체크

void dfs(int cnt){
    if(cnt==N){
        ans=max(ans, stoi(s));
        return;
    }
    int cur_val=stoi(s);
    if(visited[cnt][cur_val]) return; // 이미 같은 횟수에서 확인한 숫자면 가지치기
    visited[cnt][cur_val]=true;

    int len=s.length();
    for(int i=0; i<len-1; i++){
        for(int j=i+1; j<len; j++){
            swap(s[i], s[j]);
            dfs(cnt+1);
            swap(s[i], s[j]);
        }
    }
}

int main(){
    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>s>>N;
        ans=0;
        memset(visited, false, sizeof(visited));
        
        dfs(0);
        
        cout<<"#"<<t<<" "<<ans<<'\n';
    }
    return 0;
}