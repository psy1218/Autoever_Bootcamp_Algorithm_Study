#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

struct Info{
    int a; // 근무 태도 점수
    int b; // 동료 평가 점수
    int s; // 두 점수의 합
    int Wanho; // 원호인지 아닌지 
};

// a를 내림차순 했으면, b는 오름차순 해야함. 비교해야하는데 문제 생김. a가 똑같아도  b가 더 작다고 판별하여 지우면 안 될 것을 지움.
bool compare(struct Info& l, struct Info& r){
    if(l.a == r.a) return l.b < r.b;
    return (l.a > r.a);
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    
    int w = 0;
    
    vector<Info>info(scores.size());
    for(int i=0;i<scores.size();i++){
        info[i].a = scores[i][0];
        info[i].b = scores[i][1];
        info[i].s = info[i].a + info[i].b;
        if(i == 0) {
            w = info[i].s;
            info[i].Wanho = 1;
        }
        else info[i].Wanho = 0;
    }
    
    sort(info.begin(), info.end(), compare);
    
    
   
// 맵 써서 풀기 -> 그렇게 안 해도 됨... ㅜ    
//     int std = 0;
//     map<int,int>m;
//     for(int i=0;i<info.size();i++){
//         if(std > info[i].b){
//             info[i].s = 0;
//             if(info[i].Wanho == 1) return -1;
//         }
//         else {
//             std = info[i].b;
//             m[info[i].s]++;
//         }
//     }
        
//     // 위의 랭킹 다 봐야함. r그 전만 보면 안 됨.
//     auto it = m.end();
//     int cnt = 0;
//     while(1){
//         if(it -> first == w) break;
        
//         cnt += it -> second;
//         if(it != m.begin()) --it;
//     }
    
//     answer = cnt + 1;
    
//     for(auto it:m){
//         cout << it.first << ' '<< it.second << '\n';
//     }
    
    
    
//     for(auto it:info){
//         cout << it.a << ' ' << it.b << ' ' << it.s << ' '<< it.Wanho '\n';
//     }
    
    int std = 0;
    int cnt = 0;
    for(int i=0;i<info.size();i++){
        if(std > info[i].b){
            info[i].s = 0;
            if(info[i].Wanho == 1) return -1;
        }
        else {
            std = info[i].b;
            if(info[i].s > w) cnt++;
        }
    }
    
    answer = cnt + 1;
    
    return answer;
}

/*
[[2,2],[1,4],[3,2],[3,2],[2,1]]


[3,2] -> 5
[3,2] -> 5
[2,2] -> 4
[2,1] 체크 
[1,4] -> 5



이러면 안됨.  b는 오름차순 해줘야함!!!
[3,5] -> 5
[3,2] -> 5
[2,2] -> 4
[2,1] 체크 
[1,4] -> 5
*/
