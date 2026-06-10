#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

/* 
1. 장르 별로 순위 내기
2. 장르 내 곡 별로 순위 내기
3. 1개 아니면 2개씩 저장 
*/

bool compare(pair<string,int>& a, pair<string,int>& b){
    return a.second > b.second;
}

bool cmp(pair<int,int>& a, pair<int,int>& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int>kind;
    map<string, vector<pair<int,int>>>cnt;
    
    for(int i=0;i<genres.size();i++){
        kind[genres[i]] += plays[i];
        cnt[genres[i]].push_back({plays[i],i});
    }
    
    vector<pair<string,int>>v(kind.begin(), kind.end());
    
    sort(v.begin(), v.end(), compare);
    for(auto & it : cnt){
        sort(it.second.begin(), it.second.end(), cmp);
    }
    // 이렇게 하면 안됨. string이 인덱스가 될 수는 없다. 
    // for(int i=0;i<cnt.size();i++){
    //     sort(cnt[i].begin(), cnt[i].end(),cmp);
    // }
    
    
    for(auto & it : v){
        string genre = it.first;
        if(cnt[genre].size() == 1) {
            answer.push_back(cnt[genre][0].second);
            //cout << cnt[genre][0].second;
            continue;
        }
        for(int i=0;i<2;i++){
            answer.push_back(cnt[genre][i].second);
           // cout << cnt[genre][i].second;
        }
    }
    
    return answer;
}