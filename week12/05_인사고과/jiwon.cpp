#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]>b[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int a=scores[0][0], b=scores[0][1];
    int sum=a+b;
    sort(scores.begin(), scores.end(), cmp);
    int MAX=0;
    for(auto& s : scores){
        if(s[1]<MAX){
            if(s[0]==a && s[1]==b) return -1;
        }
        else{
            MAX=max(MAX, s[1]);
            if(s[0]+s[1]>sum) answer++;
        }
    }
    return answer;
}