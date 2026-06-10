import java.io.*;
import java.util.*;

public class Solution {
    static int[][] map = new int[100][100];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int tc = 0; tc < 10; tc++) {
            int testCase = Integer.parseInt(br.readLine());

            int x = 0;
            int y = 99;

            for (int i = 0; i < 100; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());

                for (int j = 0; j < 100; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());

                    if (map[i][j] == 2) {
                        x = j;
                    }
                }
            }

            while (y > 0) {
                // 왼쪽으로 갈 수 있으면 끝까지 이동
                if (x > 0 && map[y][x - 1] == 1) {
                    while (x > 0 && map[y][x - 1] == 1) {
                        x--;
                    }
                }
                // 오른쪽으로 갈 수 있으면 끝까지 이동
                else if (x < 99 && map[y][x + 1] == 1) {
                    while (x < 99 && map[y][x + 1] == 1) {
                        x++;
                    }
                }

                // 위로 이동
                y--;
            }

            sb.append("#").append(testCase).append(" ").append(x).append("\n");
        }

        System.out.print(sb);
    }
}