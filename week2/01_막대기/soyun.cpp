#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, num;
    cin >> N;

    stack<int>s;
    for(int i=0;i<N;i++){
        cin >> num;
        s.push(num);
    }

    int Max = 0, cnt = 0;
    while(!s.empty()){
        int cur = s.top();
        if(cur > Max) {
            Max = cur;
            cnt++;
        }

        s.pop();
    }

    cout << cnt << '\n';
    return 0;
}