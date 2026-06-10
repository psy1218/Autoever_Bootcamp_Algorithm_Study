#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    
    vector<pair<int, int>> v;
    v.resize(timetable.size());
    
    for(int i=0; i<timetable.size(); i++)
    {
        int a=(timetable[i][0]-'0')*10+timetable[i][1]-'0';
        int b=(timetable[i][3]-'0')*10+timetable[i][4]-'0';
        v[i].first=a;
        v[i].second=b;
    }
    
    sort(v.begin(), v.end());
    
    int hour=9;
    int min=0;
    int s=0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(v[s].first<hour || (v[s].first==hour && v[s].second<=min))
            {
                s++;
            }
            else break;
        }
        min+=t;
        if(min>=60)
        {
            hour++;
            min-=60;
        }
    }
    
    int ans_hour=0, ans_min=0;
    if(v.size()-s<m)
    {
        ans_hour=hour;
        ans_min=min;
    }
    else
    {
        s=s+m-1;
        ans_hour=v[s].first;
        ans_min=v[s].second-1;
        if(ans_min<0)
        {
            ans_hour--;
            ans_min+=60;
        }
        if(ans_hour>hour)
        {
            ans_hour=hour;
            ans_min=min;
        }
        else if(ans_hour==hour && ans_min>min)
        {
            ans_min=min;
        }
    }
    
    cout<<ans_min;
    
    string answer = "";
    answer.resize(5);
    answer[0]=ans_hour/10+'0';
    answer[1]=ans_hour%10+'0';
    answer[2]=':';
    answer[3]=ans_min/10+'0';
    answer[4]=ans_min%10+'0';
    
    
    return answer;
}