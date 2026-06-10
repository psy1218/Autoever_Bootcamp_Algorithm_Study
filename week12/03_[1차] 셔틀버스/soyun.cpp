#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int>Start;
    int s = 9*60;
    for(int i=0;i<n;i++){
        Start.push_back(s);
        s += t;
    }
    
    sort(timetable.begin(), timetable.end());
    
    vector<int>End;
    for(int i=0;i<timetable.size();i++){

        int c_H = stoi(timetable[i].substr(0,2));
        int c_M = stoi(timetable[i].substr(3,2));
        End.push_back((c_H*60 + c_M));
    }
    /*
    540
        480
        481
        482
        483

    540
    550
        480
        549
        550
    */
    int index = 0, cnt = 0;
    for(int i=0;i<Start.size();i++){ // 버스 출발 시간
        cnt = 0; // 버스가 새로 출발할 때 cnt를 0으로 초기화해야함.
        while(1){           
            if(cnt >= m || index >= End.size() || Start[i] < End[index]){ // 크루 버스 태우기
                //cnt = 0;  
                //여기서 버스 cnt 초기화하면, 어떤 상황에서든, 버스가 비든 차든 0으로 만들어 버림.
                break;
            }
            cnt++;
            index++; // 마지막 버스에 마지막으로 탈 수 있는 사람까지 간 거임. 그 이후는 안 간 거임. 
        }
    }
    
    // index 의 마지막엥 ++ 해줬으니까 index-1 이 최종 마지막 버스의 마지막 사람임. 
    int res = 0;
    if(cnt < m){ // 마지막 버스에 자리가 남으면!
        res = Start[Start.size()-1];
    }
    else{
        res = End[index-1] - 1;
    }
    
    //550
    int res_H = res/60;
    int res_M = res%60;
    
    string hh = (res_H < 10 ? "0" : "") + to_string(res_H);
    string mm = (res_M < 10 ? "0" : "") + to_string(res_M);
    
    answer = hh + ":" + mm;
    
    
    // for(auto it:End){
    //     cout << it <<'\n';
    // }
    
    return answer;
}

/*
540
    480
    481
    482
    483
    
540
550
    480
    549
    550
540
    540
    540
    540
    540
540 
    1
    1
    1
    1
    1

*/

// 시와 분을 나눠서 해결하려고 함. 복잡함. 
/*
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<pair<int,int>>Start;
    int H=9, M=0;
    
    for(int i=0;i<n;i++){
        Start.push_back({H, M});
        M += t;
        if(M >= 60) {
            H += 1;
            M -= 60;
        }
    }
    
    sort(timetable.begin(), timetable.end());
    
    int S_size = Start.size();
    for(int i=0;i<Start.size();i++){
        for(int j=0;j<timetable.size();j++){
            int s_H = Start[i].first;
            int s_M = Start[i].second;
            int c_H = stoi(timetable[i].substr((0,2)));
            int c_M = stoi(timetable[i].substr((3,2)));
            if( s_H <= c_H)
        }
    }
    
    for(auto it: timetable){
        cout << it << '\n';
    }
    
    for(auto it:Start){
        cout << it.first << ' ' << it.second <<'\n';
    }
    
    
    return answer;
}
*/

/*
1	1	5	["08:00", "08:01", "08:02", "08:03"]	"09:00"
    9:00 -> 9:00
2	10	2	["09:10", "09:09", "08:00"]	"09:09"
    9:00 -> 08:00
    9:10 -> 9:9
2	1	2	["09:00", "09:00", "09:00", "09:00"]	"08:59"
    9:00 9:00, 9:00
    9:01 -> 자리 남았는지 안 남았는지 파악 8:59
1	1	5	["00:01", "00:01", "00:01", "00:01", "00:01"]	"00:00"
1	1	1	["23:59"]	"09:00"
    
2	10	2	["09:10", "09:09", "08:00"]	"09:09"
9:00 
9:10

*/