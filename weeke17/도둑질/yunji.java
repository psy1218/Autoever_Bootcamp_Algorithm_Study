class Solution {
    public int solution(int[] money) {
        int n = money.length;

        int case1 = rob(money, 0, n - 2); // 첫 번째 집 포함, 마지막 집 제외
        int case2 = rob(money, 1, n - 1); // 첫 번째 집 제외, 마지막 집 포함 가능

        return Math.max(case1, case2);
    }

    private int rob(int[] money, int start, int end) {
        int prev2 = 0; // i-2번째까지의 최대값
        int prev1 = 0; // i-1번째까지의 최대값

        for (int i = start; i <= end; i++) {
            int current = Math.max(prev1, prev2 + money[i]);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
}