import java.io.*;
import java.util.*;

public class Solution {

    static int N;
    static int[][] map;
    static int[][] dist;

    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};

    static class Node implements Comparable<Node> {
        int r;
        int c;
        int cost;

        Node(int r, int c, int cost) {
            this.r = r;
            this.c = c;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node other) {
            return this.cost - other.cost;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            N = Integer.parseInt(br.readLine());

            map = new int[N][N];
            dist = new int[N][N];

            for (int i = 0; i < N; i++) {
                String line = br.readLine();

                for (int j = 0; j < N; j++) {
                    map[i][j] = line.charAt(j) - '0';
                    dist[i][j] = Integer.MAX_VALUE;
                }
            }

            int answer = dijkstra();

            sb.append("#").append(tc).append(" ").append(answer).append("\n");
        }

        System.out.print(sb);
    }

    static int dijkstra() {
        PriorityQueue<Node> pq = new PriorityQueue<>();

        dist[0][0] = 0;
        pq.offer(new Node(0, 0, 0));

        while (!pq.isEmpty()) {
            Node now = pq.poll();

            if (now.cost > dist[now.r][now.c]) {
                continue;
            }

            if (now.r == N - 1 && now.c == N - 1) {
                return now.cost;
            }

            for (int d = 0; d < 4; d++) {
                int nr = now.r + dr[d];
                int nc = now.c + dc[d];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                    continue;
                }

                int newCost = now.cost + map[nr][nc];

                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.offer(new Node(nr, nc, newCost));
                }
            }
        }

        return dist[N - 1][N - 1];
    }
}