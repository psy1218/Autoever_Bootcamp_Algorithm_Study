#include <string>
#include <vector>
#include <iostream>
#include <climits>

// 이분탐색

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int Min = INT_MAX, Max = 0;
    for(int i=0;i<stones.size();i++){
        if(Min > stones[i]) Min = stones[i];
        if(Max < stones[i]) Max = stones[i];
    }
    
    
    int mid = 0;
    
    while(1){
        int cnt = 0;
        bool possible = true;

        if(Max <  Min) break;
        mid = (Max + Min) / 2;
           
        for(int i=0;i<stones.size();i++){
            if(stones[i] - mid < 0){ 
                cnt++;
            }
            else cnt = 0;
            
            if(cnt >= k) {// 징검다리 갈수 있는 상태가 넘을 때! 
                possible = false;
            }
        }
        
        // mid 관리는 나중에! 해야함. mid 범위 다 봤으니까 1씩 옮겨주기! 
        if(possible){
            answer = mid;
            Min = mid + 1;
        }
        else{
            Max = mid - 1;
        }
        
    }
    return answer;
}