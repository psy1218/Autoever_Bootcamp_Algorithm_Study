import java.util.*;

class Solution {
    int[] parent;

    public int solution(int n, int[][] costs) {
        parent = new int[n];


        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }


        Arrays.sort(costs, (a, b) -> a[2] - b[2]);

        int answer = 0;

        for (int[] edge : costs) {
            int a = edge[0];
            int b = edge[1];
            int cost = edge[2];

            // 사이클 안 생기면 연결
            if (find(a) != find(b)) {
                union(a, b);
                answer += cost;
            }
        }

        return answer;
    }

    private int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    private void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            parent[rootB] = rootA;
        }
    }
}