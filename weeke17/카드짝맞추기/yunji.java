import java.util.*;

class Solution {
    static int[][] board;
    static List<int[]>[] cards;
    static int answer = Integer.MAX_VALUE;

    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};

    public int solution(int[][] inputBoard, int r, int c) {
        board = new int[4][4];
        cards = new ArrayList[7];

        for (int i = 1; i <= 6; i++) {
            cards[i] = new ArrayList<>();
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[i][j] = inputBoard[i][j];

                if (board[i][j] != 0) {
                    cards[board[i][j]].add(new int[]{i, j});
                }
            }
        }

        dfs(r, c, 0);

        return answer;
    }

    static void dfs(int r, int c, int count) {
        boolean finished = true;

        for (int i = 1; i <= 6; i++) {
            if (!cards[i].isEmpty()) {
                finished = false;
                break;
            }
        }

        if (finished) {
            answer = Math.min(answer, count);
            return;
        }

        for (int cardNum = 1; cardNum <= 6; cardNum++) {
            if (cards[cardNum].isEmpty()) {
                continue;
            }

            int[] first = cards[cardNum].get(0);
            int[] second = cards[cardNum].get(1);

            int r1 = first[0];
            int c1 = first[1];
            int r2 = second[0];
            int c2 = second[1];

            // 경우 1: first 먼저 선택 후 second 선택
            int cost1 = bfs(r, c, r1, c1) + bfs(r1, c1, r2, c2) + 2;

            removeCard(cardNum);
            dfs(r2, c2, count + cost1);
            restoreCard(cardNum, first, second);

            // 경우 2: second 먼저 선택 후 first 선택
            int cost2 = bfs(r, c, r2, c2) + bfs(r2, c2, r1, c1) + 2;

            removeCard(cardNum);
            dfs(r1, c1, count + cost2);
            restoreCard(cardNum, first, second);
        }
    }

    static void removeCard(int cardNum) {
        for (int[] pos : cards[cardNum]) {
            board[pos[0]][pos[1]] = 0;
        }

        cards[cardNum].clear();
    }

    static void restoreCard(int cardNum, int[] first, int[] second) {
        cards[cardNum].add(first);
        cards[cardNum].add(second);

        board[first[0]][first[1]] = cardNum;
        board[second[0]][second[1]] = cardNum;
    }

    static int bfs(int sr, int sc, int tr, int tc) {
        boolean[][] visited = new boolean[4][4];
        Queue<int[]> queue = new LinkedList<>();

        queue.offer(new int[]{sr, sc, 0});
        visited[sr][sc] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();

            int r = current[0];
            int c = current[1];
            int dist = current[2];

            if (r == tr && c == tc) {
                return dist;
            }

            for (int d = 0; d < 4; d++) {
                // 일반 방향키 이동
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (isInRange(nr, nc) && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    queue.offer(new int[]{nr, nc, dist + 1});
                }

                // Ctrl + 방향키 이동
                int[] ctrl = moveCtrl(r, c, d);
                nr = ctrl[0];
                nc = ctrl[1];

                if (!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    queue.offer(new int[]{nr, nc, dist + 1});
                }
            }
        }

        return 0;
    }

    static int[] moveCtrl(int r, int c, int d) {
        int nr = r;
        int nc = c;

        while (true) {
            int nextR = nr + dr[d];
            int nextC = nc + dc[d];

            if (!isInRange(nextR, nextC)) {
                break;
            }

            nr = nextR;
            nc = nextC;

            if (board[nr][nc] != 0) {
                break;
            }
        }

        return new int[]{nr, nc};
    }

    static boolean isInRange(int r, int c) {
        return r >= 0 && r < 4 && c >= 0 && c < 4;
    }
}