#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int paper, interview;

void hire(int N){
    int cnt = 1, Min = 0; // cnt = 1인 이유: 서류 1등은 무조건 합격이니까
    vector<pair<int,int>>grade;
 

    for(int i=0;i<N;i++){
        cin >> paper >> interview;
        grade.push_back({paper, interview});
        if(paper == 1) Min = interview;
    }

    sort(grade.begin(), grade.end());

    for(int i=0;i<N;i++){
        if(grade[i].second < Min){
            cnt ++;
            Min = grade[i].second;
        }
    }

    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N;

    cin >> T;

    for(int i=0;i<T;i++){
        cin >> N;
        hire(N);
    }
    return 0;
}

/*
3 6
7 3
4 2
1 4
5 7
2 5
6 1

1 4 o
2 5 X
3 6 X
4 2 o
5 7 X
6 1 o
7 3 x

1 5 o
2 4 o
3 3 o
4 2 o
5 1 o

1 4
2 3
3 2
4 1
5 5

1 3 o
2 1 o
3 5 x
4 4 x
5 3 x 

=> 서류 오름차순 정렬, 그 다음 면접끼리 비교 했을 때
=> 순차적으로 면접 등수가 더 높으면 그 등수로 비교해서 
=> 둘 다 낮으면 제거 느낌 

-> 서류 점수를 기준으로 오름차순 정렬한 뒤,
앞에서부터 차례대로 보면서 면접 점수를 비교한다.
이때 이전에 확인한 사람들보다 면접 등수가 더 낮다면 탈락시키고,
둘 중 하나라도 더 좋은 경우만 남기는 방식으로 진행한다.

-> 서류를 먼저 정렬해 비교 대상을 줄이고,
면접 성적만으로 살아남을 수 있는지 판단하며 순차적으로 걸러낸다.
*/