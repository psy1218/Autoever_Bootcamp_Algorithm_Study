#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    
    int N, num;
    cin >> N;
    
    queue<int>q;
    
    while(1){
        cin >> num;
        if(num == -1) break; // -1이면 멈춤 
        
        if(num == 0) q.pop();
        else if(num != 0 && q.size() < N) { // 버퍼 사이즈가 안 넘었으면 q에 넣기 
            q.push(num);
        }
    }
    
    if(q.empty()) cout << "empty" << '\n';
    else{
        while(!q.empty()){ // 버퍼 q 출력
            cout << q.front() << " ";
            q.pop();
        }
    }

    return 0;
}