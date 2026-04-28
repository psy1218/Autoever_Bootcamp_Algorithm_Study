#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int running = 0;
    vector<int>added(24, 0);
    for(int i=0;i<24;i++){
         if (i - k >= 0) { // 서버가 돌아가는 시간 - 서버 다 돌면 뺴줘야함.
            running -= added[i - k];
        }

        
        int need = players[i] / m;
        
        if(running < need){ // 필요한 서버가 현재 있는 서버보다 많을 때! 
            int add = need - running;
            added[i] = add;
            running += add;
            answer += add;
        }
    }
    
    return answer;
}

/*
현재 시간 도착
→ k시간 전에 켠 서버 종료
→ 지금 필요한 서버 수 계산
→ 현재 운영 중인 서버 수와 비교
→ 부족하면 부족한 만큼만 추가
*/