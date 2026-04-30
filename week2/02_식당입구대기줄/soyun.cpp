#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, info, a, Max_line = 0, student = 0x7fffffff; 
    // info: 유형 정보, a: 학생 번호, Max_line: 최대 줄 길이, student: 가장 길 줄일 때 뒷번호, 최대 줄이 같으면 작은 수로 저장하는 변수 
    cin >> n;
    
    deque<int>dq; // 뒤로 in, 앞으로 out - 큐 썼다가, 맨 뒤 값 알고 싶어서 dequeue 사용 

    for(int i=0;i<n;i++){
        cin >> info;
        if(info == 1){ // 유형 1일 때, 학생 수 대기 
            cin >> a;
            dq.push_back(a);
        }
        else if(info == 2){ // 유형 2일 때, 식사하러 들어감. 
            dq.pop_front();
        }

        if(dq.size() > Max_line){ // 최대 대기줄이면, Max_line 업데이트 및 학생 번호 값 업데이트 
            Max_line = dq.size();
            student = dq.back();
        }
        if(dq.size() == Max_line){  // 최대가 여러개이면 학생 번호 값이 작은 값으로 업데이트 
            if(student > dq.back()){
                student = dq.back();
            }
        }
    }

    cout << Max_line << " " << student << '\n';

    return 0;
}