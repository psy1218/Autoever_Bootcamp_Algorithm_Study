#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    if(enemy.size() <= k) return enemy.size();
    
    priority_queue<int, vector<int>, greater<int>>pq;
    
    for(int i=0;i<enemy.size();i++){
        pq.push(enemy[i]);
        if(i < k) continue;
        n -= pq.top();
        pq.pop();
        
        if(n<0){
            return i;
        }
    }
    // 끝까지 가능할 때의 경우도 꼭 처리해줘야함!!! 
    return enemy.size();
}

/*
	[4, 2, 4, 5, 3, 3, 1]
    
    4
    2 4
    2 4 4 
    2 4 4 5 
    2 3 4 4 5
    2 3 3 4 4 5
    1 2 3 4 4 5 5
*/


/*
-  priority_queue 내부는 완전 정렬 배열이 아니라, top()만 항상 최소값이 보장돼.

새 라운드 값이 들어올 때마다
그 값이 앞으로 무적권 후보가 될 만큼 큰 값인지 아직 모름.

그래서 일단 pq에 넣어봄.

그런데 pq 크기가 k보다 커지면
무적권 후보가 너무 많아진 거니까
그중 가장 작은 값을 빼서 병사로 막음.

그러면 pq 안에는 계속 큰 값 k개만 남게 됨.
*/