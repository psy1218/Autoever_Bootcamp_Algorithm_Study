#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
set<set<int>> res;
set<int> s;

void dfs(set<int>& s, int idx, const vector<vector<int>>& users){
    int b=users.size();
    if(idx==b){
        if(s.size()==b){
            res.insert(s);
            // for(int a:s){
            //     cout<<a<<endl;
            // }
        }
        return;
    }
    for(int i=0; i<users[idx].size(); i++){
        int user_val=users[idx][i];
        if (s.find(user_val) == s.end()) {
            // set 자체가 중복을 막아주는 것은 맞지만, 우리는 "중복해서 넣으려고 시도한 그 상황 자체"를 무효 처리해야 하기 때문에 if 문이 필요함
            // if 문이 없으면 DFS의 깊이(단계)는 끝까지 가는데, 결과물(set)의 내용물 개수가 부족해짐
            s.insert(user_val);
            dfs(s,idx+1,users);
            s.erase(user_val);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    int b=banned_id.size();
    vector<vector<int>> idx(b);
    for(int i=0; i<b; i++){ // banned_id
        for(int k=0; k<user_id.size(); k++){ // user_id 인덱스
            int cnt=0;
            int len=banned_id[i].size();
            for(int j=0; j<len; j++){ // banned_id 하나의 글자수
                if(user_id[k].size()!=len) break;
                else if(banned_id[i][j]=='*' || banned_id[i][j]==user_id[k][j]){
                    cnt++;
                }
                else break;
            }
            // cout<<cnt<<endl;
            if(cnt==len){
                idx[i].push_back(k);
            }
        }
    }
    // for(int i=0; i<b; i++){
    //     for(int j=0; j<idx[i].size(); j++){
    //         cout<<idx[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    dfs(s,0,idx);
    answer=res.size();
    return answer;
}