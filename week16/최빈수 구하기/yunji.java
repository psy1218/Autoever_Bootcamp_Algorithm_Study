import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {

            int testCase = Integer.parseInt(br.readLine());

            int[] count = new int[101];

            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int i = 0; i < 1000; i++) {
                int score = Integer.parseInt(st.nextToken());
                count[score]++;
            }

            int maxCount = 0;
            int answer = 0;

            for (int i = 0; i <= 100; i++) {
                if (count[i] >= maxCount) {
                    maxCount = count[i];
                    answer = i;
                }
            }

            sb.append("#").append(testCase).append(" ").append(answer).append("\n");
        }

        System.out.print(sb);
    }
}