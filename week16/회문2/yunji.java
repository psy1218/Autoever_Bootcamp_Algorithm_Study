import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int tc = 1; tc <= 10; tc++) {
            int testCase = Integer.parseInt(br.readLine());

            char[][] board = new char[100][100];

            for (int i = 0; i < 100; i++) {
                String line = br.readLine();
                for (int j = 0; j < 100; j++) {
                    board[i][j] = line.charAt(j);
                }
            }

            int answer = 1;

            for (int len = 100; len >= 1; len--) {
                boolean found = false;

                // 가로 검사
                for (int r = 0; r < 100; r++) {
                    for (int c = 0; c <= 100 - len; c++) {
                        boolean isPalindrome = true;

                        for (int k = 0; k < len / 2; k++) {
                            if (board[r][c + k] != board[r][c + len - 1 - k]) {
                                isPalindrome = false;
                                break;
                            }
                        }

                        if (isPalindrome) {
                            answer = len;
                            found = true;
                            break;
                        }
                    }

                    if (found) break;
                }

                if (found) break;

                // 세로 검사
                for (int c = 0; c < 100; c++) {
                    for (int r = 0; r <= 100 - len; r++) {
                        boolean isPalindrome = true;

                        for (int k = 0; k < len / 2; k++) {
                            if (board[r + k][c] != board[r + len - 1 - k][c]) {
                                isPalindrome = false;
                                break;
                            }
                        }

                        if (isPalindrome) {
                            answer = len;
                            found = true;
                            break;
                        }
                    }

                    if (found) break;
                }

                if (found) break;
            }

            sb.append("#").append(testCase).append(" ").append(answer).append("\n");
        }

        System.out.print(sb);
    }
}