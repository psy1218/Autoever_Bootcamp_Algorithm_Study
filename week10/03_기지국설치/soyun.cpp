#if 1
#include <iostream>
#include <vector>
using namespace std;
/*
1. 기지국으로 전파 도달 가능한 곳 배열 만들기
2. 전파 불가능한 시작점과 끝 점 찾기
3. 중요! -> 이전의 끝과 현재의 시작점이 겹치거나 시작점이 더 작다면 하나로 연결해줘야함.
4. 전파 불가능한 거리 구하고 기지국 개수 파악 

지금 코드는 ‘구간을 저장하고 다시 해석’해서 복잡해졌고, 
더 좋은 코드는 ‘빈 구간을 발견하는 즉시 계산’해서 끝낸다. ㅜㅜ 
*/

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<int>dist;

    vector<pair<int,int>>info;
    int start = 1, end = n;
    for(int i=0;i<stations.size();i++){
        int index = stations[i];
        if(index - w < 1) start = 1;
        else start = index - w;
        
        if(index + w > n) end = n;
        else end = index + w;
        
        if(i != 0) {
            if(info[info.size()-1].second >= start){ // 구간이 겹칠 때 = 끝과 시작이 같거나 더 전일 때
                                                     // 처리를 해야함. 난 이어줌. 
                int First = info[info.size()-1].first;
                info.pop_back();
                info.push_back({First, end});
                continue;
            }
        }
        info.push_back({start,end});
    }
    
    // cout << "info\n";
    // for(auto x : info){
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    
    int s = 1, e = n, flag = 0;
    for(int i=0;i<info.size();i++){
        if(info[i].first == 1){
            dist.push_back(info[i].second+1);
            continue;
        }
        if(info[0].first != 1 && flag == 0) {
            dist.push_back(s);
            flag = 1;
        }

        if(info[i].second == n){
            dist.push_back(info[i].first-1);
            continue;
        }
        
        dist.push_back(info[i].first-1); // end
        dist.push_back(info[i].second+1); // start 
    }
    if(dist.size()%2==1) dist.push_back(n);

    // cout << "dist\n";    
    // for(auto x: dist){
    //     cout << x << ' ';
    // }
    
    for(int i=0;i<dist.size()-1;i+=2){
        if(((dist[i+1]-dist[i]+1) % ((w*2)+1)) == 0){
            answer += (int)((dist[i+1]-dist[i]+1) / ((w*2)+1));
        }
        else answer += ((int)((dist[i+1]-dist[i]+1) / ((w*2)+1)) + 1);
    }
    
    
    return answer;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    vector<int>v(n+1, 0);
    for(int i=0;i<stations.size();i++){
        int index = stations[i];
        for(int j=0;j<=w;j++){
            if(index-j >= 1){
                v[index-j] = 1;
            } 
            if(index+j <= n) {
                v[index+j] = 1;
            }   
        }
    }
    
    // for(auto x: v){
    //     cout << x << ' ';
    // }
    
    vector<int>dist;
    int flag_in = 0, flag_out = 0;
    for(int i=1;i<=n;i++){
        if(v[i] == 0 && flag_in == 0){
            dist.push_back(i);
            flag_in = 1;
            flag_out = 0;
        }
        if(v[i] == 1 && flag_out == 0){
            dist.push_back(i-1);
            flag_in = 0;
            flag_out = 1;
        }
    }
    if(dist.size()%2==1) dist.push_back(n);
    
    // for(auto x: dist){
    //     cout << x << ' ';
    // }
    
    for(int i=0;i<dist.size()-1;i+=2){
        if(((dist[i+1]-dist[i]+1) % ((w*2)+1)) == 0){
            answer += (int)((dist[i+1]-dist[i]+1) / ((w*2)+1));
        }
        else answer += ((int)((dist[i+1]-dist[i]+1) / ((w*2)+1)) + 1);
    }
    
    
    return answer;
}
#endif

/*

map
3 - 1
4 - 1
5 - 1
10 - 1
11 - 1
12 - 1 

1 2 6 9 
2/3 -> 1
4/3 -> 2

6/5 -> 2
5/5 -> 1



*/