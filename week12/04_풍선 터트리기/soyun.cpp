#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    vector<int>leftMin(a.size());
    vector<int>rightMin(a.size());
    
    int Min = INT_MAX;
    for(int i=0;i<a.size();i++){
        Min = min(Min, a[i]);
        leftMin[i] = Min;
    }
    
    Min = INT_MAX;
    for(int i=a.size()-1;i>=0 ;i--){
        Min = min(Min, a[i]);
        rightMin[i] = Min;
    }
    

    int cnt = 0;
    for(int i=1;i<a.size()-1;i++){ // 어차피 양 끝은 무조건 가능함.
                                   // 가장 작은 거 찾고 큰 거 터트리고 마지막에 작은 거 터트리면 됨.
        if(a[i] > leftMin[i-1] && a[i] > rightMin[i+1])  continue;
        cnt++;
    }
    
    answer = cnt + 2;
    
    // for(auto it:leftMin){
    //     cout << it << ' ';
    // }
    // cout << '\n';
    // for(auto it:rightMin){
    //     cout << it << ' ';
    // }
    // cout << '\n';
    
    return answer;
}

/*
인접한 두 풍선 중에서 번호가 더 작은 풍선을 터트리는 행위는 최대 1번만 할 수 있습니다. 즉, 어떤 시점에서 인접한 두 풍선 중 번호가 더 작은 풍선을 터트렸다면, 그 이후에는 인접한 두 풍선을 고른 뒤 번호가 더 큰 풍선만을 터트릴 수 있습니다.
= 양쪽에 각각 나보다 더 작은 애가 있으면 불가능. 
= 양쪽 다 적으면 적은 거 두 개 다 터트려야해서, 불가능. 
= 양쪽 다 봐야하는 이유가 어차피 터트리고 터트리면 결국 작은 거 남아니까! 

[-16,27,65,-2,58,-92,-71,-68,-61,-33]


*/