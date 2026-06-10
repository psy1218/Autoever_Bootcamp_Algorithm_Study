#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>>game;
vector<vector<char>>temp;

int N, Max = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int cnt() { // 난 전체를 다시 카운트하지만,
            //바꾼 거에 대해서 바뀐 2개의 자리의 행과 열만 보는게 더 베스트일 듯!!
    int count = 1, Max_count = 1;

    // 행 카운트
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N - 1; j++) {
            if (temp[i][j] == temp[i][j + 1]) count += 1;
            else {
                if (Max_count < count) Max_count = count;
                count = 1;
            }
        }

        if (Max_count < count) Max_count = count; // for문의 마지막에 와야함! 마지막거 처리를 못 함
             count = 1;
    }

    // 열 카운트 
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N - 1; j++) {
            if (temp[j][i] == temp[j + 1][i]) count += 1;
            else {
                if (Max_count < count) Max_count = count;
                count = 1;
            }
        }

        if (Max_count < count) Max_count = count;
            count = 1;
    }

    return Max_count;
}

void fun() { 
    temp = game; // game 원본은 그대로 유지 
    Max = cnt();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            for (int k = 0; k < 4; k++) { // 좌우상하 확인 
                int cx = i + dx[k];
                int cy = j + dy[k];

                if (cx < 0 || cx >= N || cy < 0 || cy >= N) continue; //인덱스 넘어가면 패스
                if (temp[i][j] == temp[cx][cy]) continue; // 비교대상과 같아도 패스 

                // 아니라면 swap
                char tmp = temp[i][j];
                temp[i][j] = temp[cx][cy];
                temp[cx][cy] = tmp;
                if (Max < cnt()) Max = cnt();
                temp = game; //다시 원본
            }
        }
    }
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    game.assign(N, vector<char>(N));
    temp.assign(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> game[i][j];
        }
    }

    fun();

    cout << Max << '\n';

    return 0;
}