import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            int N = Integer.parseInt(br.readLine());
            int[] price = new int[N];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                price[i] = Integer.parseInt(st.nextToken());
            }

            long profit = 0;
            int maxPrice = 0;

            for (int i = N - 1; i >= 0; i--) {
                if (price[i] > maxPrice) {
                    maxPrice = price[i];
                } else {
                    profit += maxPrice - price[i];
                }
            }

            sb.append("#").append(tc).append(" ").append(profit).append("\n");
        }

        System.out.print(sb);
    }
}