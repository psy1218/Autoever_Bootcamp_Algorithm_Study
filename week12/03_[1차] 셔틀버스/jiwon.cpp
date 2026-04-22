#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int starttime=540;
string answer = "";

void conv(int ans_m){
    char buf[6];
    int h = ans_m/60, m = ans_m%60;
    sprintf(buf, "%02d:%02d", h, m); 
    answer = buf;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> minute;
    for(string s : timetable){ // 분으로 변환
        int a=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
        minute.push_back(a);
    }
    int idx=0;
    int ans_m;
    sort(minute.begin(), minute.end());
    for(int i=0; i<n; i++){
        int now=0;
        for(int j=idx; j<minute.size(); j++){
            if(starttime+i*t>=minute[j] && now<m){
                if(i==n-1 && now==m-1){  // 한 자리만 남았을 경우
                    ans_m=minute[j]-1;
                    conv(ans_m);
                    return answer;
                }
                idx++;
                now++;
            }
            else break;
        }
    }
    // 자리가 많은 경우 마지막 버스
    ans_m=starttime+t*(n-1);
    conv(ans_m);
    return answer;
}