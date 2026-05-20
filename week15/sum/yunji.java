import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int t = 0; t < 10; t++) {
            int tc = Integer.parseInt(br.readLine());

            int[][] arr = new int[100][100];

            for (int i = 0; i < 100; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());

                for (int j = 0; j < 100; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int max = 0;

            // 행 합, 열 합
            for (int i = 0; i < 100; i++) {
                int rowSum = 0;
                int colSum = 0;

                for (int j = 0; j < 100; j++) {
                    rowSum += arr[i][j];
                    colSum += arr[j][i];
                }

                max = Math.max(max, rowSum);
                max = Math.max(max, colSum);
            }

            // 대각선 합
            int diagonal1 = 0;
            int diagonal2 = 0;

            for (int i = 0; i < 100; i++) {
                diagonal1 += arr[i][i];
                diagonal2 += arr[i][99 - i];
            }

            max = Math.max(max, diagonal1);
            max = Math.max(max, diagonal2);

            sb.append("#").append(tc).append(" ").append(max).append("\n");
        }

        System.out.print(sb);
    }
}