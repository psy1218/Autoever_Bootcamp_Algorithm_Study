#include <iostream>
#include <queue>
#include <set> 
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<pair<int, int>>dq; // 학생 번호와 선호 메뉴을 묶기 
    
    int n, info, a, b;
    cin >> n;

    set<int>A; //좋아하는 것을 먹은 학생
    set<int>B; // 좋아하지 않는 것을 먹은 학생
    set<int>C; // 못 먹은 학생

    for(int i=0;i<n;i++){
        cin >> info;
        if(info == 1){ // 유형 1일 때, 
            cin >> a >> b; // a: 학생 번호, b: 선호 메뉴 
            dq.push_back({a,b});
        }
        else if(info == 2){ // 유형 2일 때, 
            cin >> b;
            int type = dq.front().second;
            int student = dq.front().first;
            if(type == b){
                A.insert(student);
            }
            else{
                B.insert(student);
            }
            dq.pop_front();
        }
    }

    while(!dq.empty()){ //대기중인 학생 C에 저장 
        int student = dq.front().first;
        C.insert(student);
        dq.pop_front();
    }

    // 학생 수 순차적으로 출력 - set 라이브러리 이용 
    if(A.size() == 0) {
        cout << "None" << '\n';
    }
    else{
        for(auto it:A) cout << it << ' ' ;
        cout << '\n';
    }
    if(B.size() == 0) {
        cout << "None" << '\n';
    }
    else{
        for(auto it:B) cout << it << ' ' ;
        cout << '\n';
    }
    if(C.size() == 0) {
        cout << "None" << '\n';
    }
    else{
        for(auto it:C) cout << it << ' ' ;
        cout << '\n';
    }

    return 0;
}