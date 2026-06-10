import java.util.*;

class Solution {
    public int solution(int n, int[][] lighthouse) {
        List<Integer>[] graph = new ArrayList[n + 1];

        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] edge : lighthouse) {
            int a = edge[0];
            int b = edge[1];

            graph[a].add(b);
            graph[b].add(a);
        }

        int[] parent = new int[n + 1];
        int[] order = new int[n];

        Stack<Integer> stack = new Stack<>();
        stack.push(1);

        int idx = 0;

        // 1번 노드를 루트로 잡고 부모 관계와 방문 순서 만들기
        while (!stack.isEmpty()) {
            int current = stack.pop();
            order[idx++] = current;

            for (int next : graph[current]) {
                if (next == parent[current]) {
                    continue;
                }

                parent[next] = current;
                stack.push(next);
            }
        }

        int[][] dp = new int[n + 1][2];

        // 아래에서 위로 계산해야 하므로 방문 순서를 거꾸로 순회
        for (int i = n - 1; i >= 0; i--) {
            int current = order[i];

            dp[current][0] = 0; // 현재 등대를 끄는 경우
            dp[current][1] = 1; // 현재 등대를 켜는 경우

            for (int next : graph[current]) {
                if (parent[next] != current) {
                    continue;
                }

                // 현재 등대를 끄면 자식 등대는 반드시 켜야 함
                dp[current][0] += dp[next][1];

                // 현재 등대를 켜면 자식은 켜도 되고 꺼도 됨
                dp[current][1] += Math.min(dp[next][0], dp[next][1]);
            }
        }

        return Math.min(dp[1][0], dp[1][1]);
    }
}