#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int r, c;
    bool operator==(const Point& other) const {
        return r == other.r && c == other.c;
    }
};

struct Node {
    int r, c, count;
};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// Ctrl + 방향키 이동을 처리하는 함수
Point ctrl_move(int r, int c, int dir, const vector<vector<int>>& board) {
    while (true) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        
        // 범위를 벗어나면 직전 위치 반환
        if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) {
            return {r, c};
        }
        
        r = nr;
        c = nc;
        
        // 카드를 만나면 멈춤
        if (board[r][c] != 0) {
            return {r, c};
        }
    }
}

// 현재 위치(start)에서 목표 위치(end)까지의 최단 조작 횟수를 구하는 BFS
int bfs(Point start, Point end, const vector<vector<int>>& board) {
    if (start == end) return 0;

    queue<Node> q;
    vector<vector<bool>> visited(4, vector<bool>(4, false));

    q.push({start.r, start.c, 0});
    visited[start.r][start.c] = true;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.r == end.r && curr.c == end.c) {
            return curr.count;
        }

        for (int i = 0; i < 4; i++) {
            // 1. 일반 방향키 이동 (1칸)
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc, curr.count + 1});
            }

            // 2. Ctrl + 방향키 이동
            Point cp = ctrl_move(curr.r, curr.c, i, board);
            if (!visited[cp.r][cp.c]) {
                visited[cp.r][cp.c] = true;
                q.push({cp.r, cp.c, curr.count + 1});
            }
        }
    }
    return 0;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 987654321; // 최솟값을 찾기 위해 큰 값으로 초기화
    
    // 1. 보드에 존재하는 카드의 종류와 위치 찾기
    vector<vector<Point>> card_positions(7); // 카드 번호는 1~6
    vector<int> card_types;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] > 0) {
                int card = board[i][j];
                if (card_positions[card].empty()) {
                    card_types.push_back(card);
                }
                card_positions[card].push_back({i, j});
            }
        }
    }
    
    // next_permutation을 쓰기 위해 카드 종류를 오름차순 정렬
    sort(card_types.begin(), card_types.end());
    
    // 2. 어떤 카드를 어떤 순서로 지울지 모든 순열 탐색
    do {
        vector<vector<int>> current_board = board;
        Point current_pos = {r, c};
        int total_move = 0;
        
        for (int card : card_types) {
            Point pos1 = card_positions[card][0];
            Point pos2 = card_positions[card][1];
            
            // 케이스 A: pos1을 먼저 방문하고 이어서 pos2 방문
            int move_a = bfs(current_pos, pos1, current_board) + bfs(pos1, pos2, current_board);
            // 케이스 B: pos2를 먼저 방문하고 이어서 pos1 방문
            int move_b = bfs(current_pos, pos2, current_board) + bfs(pos2, pos1, current_board);
            
            if (move_a < move_b) {
                total_move += move_a;
                current_pos = pos2;
            } else {
                total_move += move_b;
                current_pos = pos1;
            }
            
            // 카드 2장을 선택하는 Enter 입력 횟수(+2) 추가
            total_move += 2;
            
            // 지워진 카드는 빈 칸(0)으로 교체
            current_board[pos1.r][pos1.c] = 0;
            current_board[pos2.r][pos2.c] = 0;
        }
        
        answer = min(answer, total_move);
        
    } while (next_permutation(card_types.begin(), card_types.end()));
    
    return answer;
}