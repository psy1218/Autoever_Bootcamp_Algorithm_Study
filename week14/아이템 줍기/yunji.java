import java.util.*;

class Solution {
    static int[][] map = new int[102][102];
    static boolean[][] visited = new boolean[102][102];

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {

        for (int[] r : rectangle) {
            int x1 = r[0] * 2;
            int y1 = r[1] * 2;
            int x2 = r[2] * 2;
            int y2 = r[3] * 2;

            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    if (i > x1 && i < x2 && j > y1 && j < y2) {
                        map[i][j] = 2;
                    }
                    else {
                        if (map[i][j] != 2) {
                            map[i][j] = 1;
                        }
                    }
                }
            }
        }

        return bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2) / 2;
    }

    private int bfs(int startX, int startY, int itemX, int itemY) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{startX, startY, 0});
        visited[startX][startY] = true;

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();

            if (cur[0] == itemX && cur[1] == itemY) {
                return cur[2];
            }

            for (int d = 0; d < 4; d++) {
                int nx = cur[0] + dx[d];
                int ny = cur[1] + dy[d];

                if (nx < 0 || ny < 0 || nx >= 102 || ny >= 102) {
                    continue;
                }

                if (visited[nx][ny]) {
                    continue;
                }

                if (map[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    queue.offer(new int[]{nx, ny, cur[2] + 1});
                }
            }
        }

        return 0;
    }
}