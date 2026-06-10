import java.io.*;
import java.util.*;

public class yunji {
    static int N;
    static int cnt;
    static int[][] board;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for(int t = 1; t <=T; t++){
            N = Integer.parseInt(br.readLine());
            board = new int[N][N];
            cnt = 0;

            dfs(0);

            sb.append("#").append(t).append(" ").append(cnt).append("\n");
        }

        System.out.print(sb);
    }

    static void dfs(int row) {
        if (row == N) {
            cnt++;
            return;
        }

        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                mark(row, col, 1);
                dfs(row + 1);
                mark(row, col, -1);
            }
        }
    }

    static void mark(int row, int col, int value) {
        for (int r = row; r < N; r++) {
            board[r][col] += value;
        }

        int r = row;
        int c = col;
        while (r < N && c < N) {
            board[r][c] += value;
            r++;
            c++;
        }

        r = row;
        c = col;
        while (r < N && c >= 0) {
            board[r][c] += value;
            r++;
            c--;
        }
    }

}