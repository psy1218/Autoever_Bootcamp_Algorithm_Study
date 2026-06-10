import java.util.*;

class Solution {
    public int solution(int distance, int[] rocks, int n) {
        Arrays.sort(rocks);

        int left = 1;
        int right = distance;
        int answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (canMake(mid, distance, rocks, n)) {
                answer = mid;
                left = mid + 1;   // 가능하니까 더 큰 최소 거리 도전
            } else {
                right = mid - 1;  // 불가능하니까 거리 줄이기
            }
        }

        return answer;
    }

    private boolean canMake(int minDistance, int distance, int[] rocks, int n) {
        int removed = 0;
        int previous = 0;

        for (int rock : rocks) {
            int gap = rock - previous;

            if (gap < minDistance) {
                removed++;
            } else {
                previous = rock;
            }
        }

        // 마지막 남은 바위와 도착점 사이도 확인
        if (distance - previous < minDistance) {
            removed++;
        }

        return removed <= n;
    }
}