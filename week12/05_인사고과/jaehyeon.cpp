#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1;
    
    int a1=scores[0][0], b1=scores[0][1];
    int wan_score= a1+b1;
    
    for(int i=0; i<scores.size(); i++)
    {
        if(a1>=scores[i][0]) continue;
        if(b1>=scores[i][1]) continue;
        return -1;
    }
    
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>&b)
         {
             if(a[0]==b[0]) return a[1]<b[1];
             return a[0]>b[0];
         });
    
    int max_b=0;
    for(int i=0; i<scores.size(); i++)
    {   
        if(scores[i][1]<max_b) continue; 
        max_b=max(max_b, scores[i][1]);
        if(scores[i][0]+scores[i][1]>wan_score) answer++;
    }
    
    
    return answer;
}