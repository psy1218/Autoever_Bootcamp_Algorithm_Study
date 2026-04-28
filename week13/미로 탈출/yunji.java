import java.util.*;

class Solution {
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    public int solution(String[] maps) {
        int n = maps.length;
        int m = maps[0].length();

        int[] start = new int[2];
        int[] lever = new int[2];
        int[] exit = new int[2];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = maps[i].charAt(j);
                if (c == 'S') start = new int[]{i, j};
                if (c == 'L') lever = new int[]{i, j};
                if (c == 'E') exit = new int[]{i, j};
            }
        }

        int toLever = bfs(maps, start, lever);
        if (toLever == -1) return -1;

        int toExit = bfs(maps, lever, exit);
        if (toExit == -1) return -1;

        return toLever + toExit;
    }

    private int bfs(String[] maps, int[] start, int[] target) {
        int n = maps.length;
        int m = maps[0].length();

        boolean[][] visited = new boolean[n][m];
        Queue<int[]> q = new LinkedList<>();

        q.offer(new int[]{start[0], start[1], 0});
        visited[start[0]][start[1]] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int dist = cur[2];

            if (x == target[0] && y == target[1]) {
                return dist;
            }

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (visited[nx][ny]) continue;
                if (maps[nx].charAt(ny) == 'X') continue;

                visited[nx][ny] = true;
                q.offer(new int[]{nx, ny, dist + 1});
            }
        }

        return -1;
    }
}