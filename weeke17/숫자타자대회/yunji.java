import java.util.*;

class Solution {
    static final int INF = 1_000_000_000;

    public int solution(String numbers) {
        int[][] pos = {
                {3, 1}, // 0
                {0, 0}, // 1
                {0, 1}, // 2
                {0, 2}, // 3
                {1, 0}, // 4
                {1, 1}, // 5
                {1, 2}, // 6
                {2, 0}, // 7
                {2, 1}, // 8
                {2, 2}  // 9
        };

        int[][] cost = new int[10][10];

        for (int from = 0; from <= 9; from++) {
            for (int to = 0; to <= 9; to++) {
                if (from == to) {
                    cost[from][to] = 1;
                    continue;
                }

                int dr = Math.abs(pos[from][0] - pos[to][0]);
                int dc = Math.abs(pos[from][1] - pos[to][1]);

                int diagonal = Math.min(dr, dc);
                int straight = Math.abs(dr - dc);

                cost[from][to] = diagonal * 3 + straight * 2;
            }
        }

        int[][] dp = new int[10][10];

        for (int i = 0; i < 10; i++) {
            Arrays.fill(dp[i], INF);
        }

        // 시작 위치: 왼손 4, 오른손 6
        dp[4][6] = 0;

        for (int idx = 0; idx < numbers.length(); idx++) {
            int target = numbers.charAt(idx) - '0';

            int[][] nextDp = new int[10][10];

            for (int i = 0; i < 10; i++) {
                Arrays.fill(nextDp[i], INF);
            }

            for (int left = 0; left <= 9; left++) {
                for (int right = 0; right <= 9; right++) {
                    if (dp[left][right] == INF) {
                        continue;
                    }

                    // target 위에 오른손이 있으면 반드시 오른손으로 눌러야 함
                    if (right == target) {
                        nextDp[left][right] = Math.min(
                                nextDp[left][right],
                                dp[left][right] + cost[right][target]
                        );
                        continue;
                    }

                    // target 위에 왼손이 있으면 반드시 왼손으로 눌러야 함
                    if (left == target) {
                        nextDp[left][right] = Math.min(
                                nextDp[left][right],
                                dp[left][right] + cost[left][target]
                        );
                        continue;
                    }

                    // 왼손으로 누르는 경우
                    nextDp[target][right] = Math.min(
                            nextDp[target][right],
                            dp[left][right] + cost[left][target]
                    );

                    // 오른손으로 누르는 경우
                    nextDp[left][target] = Math.min(
                            nextDp[left][target],
                            dp[left][right] + cost[right][target]
                    );
                }
            }

            dp = nextDp;
        }

        int answer = INF;

        for (int left = 0; left <= 9; left++) {
            for (int right = 0; right <= 9; right++) {
                answer = Math.min(answer, dp[left][right]);
            }
        }

        return answer;
    }
}