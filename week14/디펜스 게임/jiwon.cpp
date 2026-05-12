#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq; // 오름차순

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    if(k>enemy.size()) return enemy.size();
    for(int i=0; i<k; i++){
        pq.push(enemy[i]);
        answer++;
    }
    for(int i=k; i<enemy.size(); i++){
        int f=pq.top();
        if(f<enemy[i]){
            pq.pop();
            n-=f;
            pq.push(enemy[i]);
        }
        else{
            n-=enemy[i];
        }
        if(n<0) break;
        answer++;
    }
    return answer;
}