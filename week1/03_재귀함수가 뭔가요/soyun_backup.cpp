#include <iostream>
using namespace std;

int N;
string space = "";

void dfs(int cnt, string space){
    cout << space << "\"재귀함수가 뭔가요?\"" << '\n';
    
    if(cnt == N) {
        cout << space << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << '\n';
        cout << space << "라고 답변하였지." << '\n';
        return;
    }
    
    cout << space << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << '\n';
    cout << space << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << '\n';
    cout << space << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << '\n';

    dfs(cnt + 1, space + "____");
    
    cout << space << "라고 답변하였지." << '\n';
}

int main(){
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
    
    int cnt=0;
    dfs(cnt,space);
    return 0;
}

#if 0
#include <iostream>
using namespace std;

int N;
string space = "";

void dfs(int cnt, string space){
    
    space = "";
    for(int i=0;i< 4*cnt; i++){
        space += "_"; // space.append(" "); 도 가능 
    }
    cout << space << "\"재귀함수가 뭔가요?\"" << '\n';
    
    if(cnt == N) {
        cout << space << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << '\n';
        cout << space << "라고 답변하였지." << '\n';
        return;
    }
    
    cout << space << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << '\n';
    cout << space << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << '\n';
    cout << space << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << '\n';

    dfs(cnt + 1, space);
    
    cout << space << "라고 답변하였지." << '\n';
}

int main(){
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
    
    int cnt=0;
    dfs(cnt,space);
    return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

int N;

void dfs(int _i){
    int _space = _i * 4;
    for(int i=0;i<_space;i++){
        cout << "_";
    }
    cout << "\"재귀함수가 뭔가요?\"" << '\n';
    for(int i=0;i<_space;i++){
        cout << "_";
    }
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\"";
    for(int i=0;i<_space;i++){
        cout << "_";
    }cout << "\"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\"";
    for(int i=0;i<_space;i++){
        cout << "_";
    }
    cout << "\"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";


     if(N-1 == _i){
        return;
     }
}

int main(){
    cin >> N;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';

    for(int i=0;i<N;i++){
        dfs(i);
        
    }

    return 0;
}
#endif