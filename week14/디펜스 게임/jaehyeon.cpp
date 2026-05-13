#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue <int> pq;
    
    for(int i=0; i<enemy.size(); i++){
        pq.push(enemy[i]);
        n-=enemy[i];
        if(n<0 && k>0){
            n+=pq.top();
            pq.pop();
            k--;
        }
        if(n<0 && k==0) break;
        answer++;
    }
    
    return answer;
}