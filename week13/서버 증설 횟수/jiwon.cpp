#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int N=players.size();
    vector<int> server(N+k,0);
    for(int i=0; i<N; i++){
        int s=players[i]/m;
        if(server[i]<s){
            int a=s-server[i];
            answer+=a;
            for(int j=i; j<i+k; j++){
                server[j]+=a;
            }
        }
    }
    // for(int a : server){
    //     cout<<a<<' ';
    // }
    return answer;
}

// m=3 k=5
// 0 2 3 3 1 2 0 0 0 0 4 2 0 6 0 4 2 13 3 5 10 0 1 5
// 0 0 1 1 1 1 1 0 0 0 1 1 1 2 2 1 1 4  3 3 3  3 0 1

// answer=server[0];
// for(int i=1; i<N; i++){
//     if(server[i-1]<server[i]){
//         answer+=server[i]-server[i-1];
//     }
// }
// server 배열의 변화량을 나중에 계산하면, 기존 서버가 빠지는 타이밍과 새 서버가 들어오는 타이밍이 겹쳐서 데이터가 오염될 수 있음