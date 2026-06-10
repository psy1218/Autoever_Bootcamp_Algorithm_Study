// 인접 리스트 

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>list;
vector<int>visited;
int flag = 0;

void dfs(int cur, int depth){
    if(flag) return; // 찾았으면 바로 return , 함수 내부 안 보고 바로 리턴! 

    if(depth == 5){ // 5명의 연결 찾았다! 
        flag = 1;
        return;
    }

    for(int i=0;i<list[cur].size();i++){
        int next = list[cur][i]; // 다음 사람, 없으면 그냥 vistied 순서대로 1,2,3,.. .이렇게 방문하게 됨. 
        if(visited[next] == 1) continue;
        visited[next] = 1;
        dfs(next, depth+1);
        visited[next] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, a, b;
    cin >> N >> M;

    list.assign(N, {});
    visited.assign(N, 0);
   
    for(int i=0;i<M;i++){
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    // for(int i=0;i<N;i++){
    //     cout << i << ": ";
    //     for(int j=0;j<list[i].size();j++){
    //         cout << list[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int i=0;i<N;i++){
        visited[i] = 1;
        dfs(i, 1); // 시작점과 depth
        visited[i] = 0;

        if(flag == 1){
            break;
        }
    }

    if(flag == 1) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}

/*
8 8
1 7
3 7
4 7
3 4
4 6
3 5
0 4
2 7

0 4
1 7
2 7
3 7
3 4 
3 5
4 6
4 7

1 7 4 3 5

  0 1 2 3 4 5 6 7
0 0 0 0 0 1 0 0 0
1 0 0 0 0 0 0 0 1
2 0 0 0 0 0 0 0 1
3 0 0 0 0 1 1 0 1
4 1 0 0 1 0 0 1 1
5 0 0 0 1 0 0 0 0
6 0 0 0 0 1 0 0 0
7 0 1 1 1 1 0 0 0

    for(int i=0;i<list[cur].size();i++){
        if(visited[next] == 1) continue;
        visited[i] = 1;
        dfs(i, depth+1);
        visited[i] = 0;
    }

1: 7 
2: 7 
3: 7 4 5 
4: 7 3 6 0 
5: 3 
6: 4 
7: 1 3 4 2 

*/