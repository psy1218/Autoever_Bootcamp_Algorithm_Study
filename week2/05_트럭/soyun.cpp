#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, w, L, a, time = 0, weight = 0, index = 0;

    cin >> n >> w >> L;

    deque<int>dq(w, 0);
    int list[1001] = {0, }; // 밑 조건문 index > n 안 쓸 거면 list 배열 크기 넉넉하게 잡기 
    for(int i=0;i<n;i++){
        cin >> list[i];
    }
    
    while(1){
        time ++; // 단위, 규칙에 맞게 시간은 계속 증가

        // 다리의 길이가 2일 때, [0,0] 으로 시작 
        weight -= dq.front(); // 다리에 존재하는 트럭 무게
        dq.pop_front(); 

        if(index < n && weight + list[index] <= L){ 
            // index < n 꼭 해줘야함. index의 범위가 list의 범위를 넘을 때 (= list 범위 넘을 때까지 push 할 때) 쓰레기 값이 됨. 저 조건문 안 쓰려면 list 범위를 크게 잡는다. 
            dq.push_back(list[index]); // 트럭 지나갈 수 있으면 push 
            weight += list[index]; // 다리에 존재하는 트럭 무게 추가
            index ++; //다음 트럭 인덱스 
        }
        else {
            dq.push_back(0); // 못 갈 때 0 으로 push
        }

        if(weight == 0) break; // 다리 위에 존재하는 게 없을 떄 중단 
    }

    cout << time << '\n';

    return 0;
}