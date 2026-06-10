#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 2;
    int n=a.size();
    int l_min[n];
    int r_min[n];
    
    l_min[1]=a[0];
    r_min[n-2]=a[n-1];
    
    for(int i=2; i<n; i++)
    {
        l_min[i]=min(l_min[i-1], a[i-1]);
    }
    
    for(int i=n-3; i>=0; i--)
    {
        r_min[i]=min(r_min[i+1], a[i+1]);
    }
    
    for(int i=1; i<n-1; i++)
    {
        if(a[i]<l_min[i] || a[i]<r_min[i]) 
        {
            //cout<<l_min[i]<<" "<<a[i]<<" "<<r_min[i]<<endl;
            answer++;
        }
    }
    
    return answer;
}