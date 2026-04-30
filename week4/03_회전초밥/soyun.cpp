#include <iostream>
#include <vector>
#include <set>
using namespace std;

// M개의 초밥이 중복 가능 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, k, a;

    cin >> N >> M;

    vector<set<int>>sushi(200001); // M+1 이 아님. M개의 초밥이 순서대로라고 적혀 있지 않음. 1, 20000일 수도 있음.
    vector<int>people(N, 0);

    for(int i=0;i<N;i++){
        cin >> k;
        for(int j=0;j<k;j++){
            cin >> a;
            sushi[a].insert(i);
        }
    }

    for(int i=0;i<M;i++){
        cin >> a;
        if((sushi[a].empty())) continue; // 주문 안 한 초밥 건너뛰기
        people[*sushi[a].begin()]++; // 먼저 주문한 사람이 먹기
        sushi[a].erase(sushi[a].begin()); // 먹은 사람 빼기;
    }

    for(auto it : people) cout << it << " " ;

    return 0;
}

/*
1 - 1, 3
2 - 2
3 - 2
4 - 
5 - 2
*/