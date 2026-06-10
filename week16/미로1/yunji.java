import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int[] dy = {-1, 1, 0, 0};
        int[] dx = {0, 0, -1, 1};

        for (int tc = 1; tc <= 10; tc++) {
            int testCase = Integer.parseInt(br.readLine());

            int[][] maze = new int[16][16];
            boolean[][] visited = new boolean[16][16];

            int startY = 0;
            int startX = 0;

            for (int i = 0; i < 16; i++) {
                String line = br.readLine();

                for (int j = 0; j < 16; j++) {
                    maze[i][j] = line.charAt(j) - '0';

                    if (maze[i][j] == 2) {
                        startY = i;
                        startX = j;
                    }
                }
            }

            int result = 0;

            Queue<int[]> queue = new LinkedList<>();
            queue.offer(new int[]{startY, startX});
            visited[startY][startX] = true;

            while (!queue.isEmpty()) {
                int[] current = queue.poll();

                int y = current[0];
                int x = current[1];

                if (maze[y][x] == 3) {
                    result = 1;
                    break;
                }

                for (int d = 0; d < 4; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];

                    if (ny < 0 || ny >= 16 || nx < 0 || nx >= 16 || visited[ny][nx] || maze[ny][nx] == 1) {
                        continue;
                    }

                    visited[ny][nx] = true;
                    queue.offer(new int[]{ny, nx});
                }
            }

            sb.append("#").append(testCase).append(" ").append(result).append("\n");
        }

        System.out.print(sb);
    }
}