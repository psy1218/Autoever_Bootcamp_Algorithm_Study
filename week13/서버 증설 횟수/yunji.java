import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;

        int[] expire = new int[24 + k + 1];

        int currentServer = 0;

        for (int i = 0; i < 24; i++) {
            currentServer -= expire[i];

            int need = players[i] / m;

            if (currentServer < need) {
                int add = need - currentServer;
                answer += add;
                currentServer += add;

                expire[i + k] += add;
            }
        }

        return answer;
    }
}