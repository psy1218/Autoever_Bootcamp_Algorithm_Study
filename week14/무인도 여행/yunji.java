import java.util.*;

class Solution {
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public int[] solution(String[] maps) {
        int n = maps.length;
        int m = maps[0].length();

        visited = new boolean[n][m];
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (!visited[i][j] && maps[i].charAt(j) != 'X') {
                    int sum = bfs(i, j, maps);
                    result.add(sum);
                }
            }
        }

        if (result.isEmpty()) {
            return new int[]{-1};
        }

        Collections.sort(result);

        int[] answer = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }

        return answer;
    }

    private int bfs(int x, int y, String[] maps) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x, y});
        visited[x][y] = true;

        int sum = maps[x].charAt(y) - '0';

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();

            for (int d = 0; d < 4; d++) {
                int nx = cur[0] + dx[d];
                int ny = cur[1] + dy[d];

                if (nx < 0 || ny < 0 || nx >= maps.length || ny >= maps[0].length()) {
                    continue;
                }

                if (visited[nx][ny]) {
                    continue;
                }

                if (maps[nx].charAt(ny) == 'X') {
                    continue;
                }

                visited[nx][ny] = true;
                sum += maps[nx].charAt(ny) - '0';
                queue.offer(new int[]{nx, ny});
            }
        }

        return sum;
    }
}