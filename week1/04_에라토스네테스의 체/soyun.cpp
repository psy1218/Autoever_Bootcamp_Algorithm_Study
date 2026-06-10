#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N, K;
    cin >> N >> K;

    vector<int>v(N+1, 1);

    int cnt = 0, std = 2, increasing = 1; // 개수, 소수 시작, 증가 
    while(1){
        cnt += 1;

        if(v[std*increasing] == 0){ // 배수가 겹칠 때
            while(1){
                increasing += 1; // 배수가 안 겹칠 때까지 증가 
                if (std*increasing > N) break; // 늘어나는 배수가 N보다 크면 x
                if(v[std*increasing] == 1) break; // 배수가 안 겹칠 때 탈출
            }
        }

        // 위에서 안 되는 경우 처리해서 밑 조건문에서 std 변경함. 
        if(std*increasing > N) { // 늘어나는 배수가 N보다 크면 / 기준값이 변경되어야함.
            increasing = 1;  // 증가하는 변수도 초기화 
            while(1){
                std += 1;

                if(v[std] == 1) break;
            }
        }

        v[std*increasing] = 0; // 소수가 아닌 것은 0 

        if(cnt == K) {
            cout << std*increasing << '\n'; 
            break;  
        }

        increasing += 1; //다음 소수가 아닌 값 준비. 

    }

    return 0;
}