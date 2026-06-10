#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, P, jn, pn;
    cin >> N >> P;

    vector<stack<int>>music(7); // 줄이 6개 정해짐. // 줄의 번호는 N보다 작거나 같은 자연수. . .. 

    int cnt = 0;
    for(int i=0;i<N;i++){
        cin >> jn >> pn;
        if(music[jn].empty()) cnt ++;
        if(!(music[jn].empty()) && music[jn].top() < pn) cnt ++;
        if(!(music[jn].empty()) && music[jn].top() > pn){
            while(1){
                if(music[jn].empty() || music[jn].top() < pn) {
                    cnt ++;
                    break;
                }
                if(music[jn].top() == pn) break;

                music[jn].pop();
                cnt ++;
            }
        }
        
        if(!(music[jn].empty()) && music[jn].top() == pn) continue; // top이랑 똑같으면 push 안 함!! 

        music[jn].push(pn);
    }

    cout << cnt << '\n';
    return 0;
}