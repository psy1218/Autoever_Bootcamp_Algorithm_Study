#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N,M;
int arr[10][10];
int ans=1e9;
const int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};

struct s{
    int x,y,type;
};
vector<s> cctv;

vector<int> dir[6] = {
    {},
    {0},
    {1,3},
    {0,1},
    {0,1,3},
    {0,1,2,3}
};

void watch(int x, int y, int d, int mp[10][10]) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    while (nx >= 0 && ny >= 0 && nx < N && ny < M) {
        if (mp[nx][ny] == 6) break; // 벽을 만나면 중단
        if (mp[nx][ny] == 0) mp[nx][ny] = -1; // 빈칸이면 감시 표시
        nx += dx[d];
        ny += dy[d];
    }
}

void draw(int x, int y, int type, int d, int mp[10][10]){
    for(int i=0; i<dir[type].size(); i++){
        int real_d = (dir[type][i] + d) % 4;
        watch(x, y, real_d, mp);
    }
}

void go(int idx, int current[10][10]){
    if (idx == cctv.size()) {
        // 모든 CCTV 배치가 끝나면 사각지대(0) 개수 계산
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (current[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }
    int x=cctv[idx].x;
    int y=cctv[idx].y;
    int type=cctv[idx].type;

    for(int d=0; d<4; d++){
        int next[10][10];
        memcpy(next,current, sizeof(next));
        draw(x,y,type,d,next);
        go(idx+1, next);
        if(type==5) break;
        if (type == 2 && d == 1) break;
    }
}

int main(){
    cin>>N>>M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 5) {
                cctv.push_back({i, j, arr[i][j]});
            }
        }
    }
    go(0,arr);
    cout << ans << endl;
    return 0;
}