class Solution {
    public boolean solution(int[][] key, int[][] lock) {
        int m = key.length;
        int n = lock.length;

        int size = n + (m - 1) * 2;

        for (int rotate = 0; rotate < 4; rotate++) {
            key = rotateKey(key);

            for (int x = 0; x <= size - m; x++) {
                for (int y = 0; y <= size - m; y++) {

                    int[][] board = new int[size][size];

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            board[i + m - 1][j + m - 1] = lock[i][j];
                        }
                    }

                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j < m; j++) {
                            board[x + i][y + j] += key[i][j];
                        }
                    }

                    // lock 영역이 전부 1이면 성공
                    if (check(board, m, n)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    private int[][] rotateKey(int[][] key) {
        int m = key.length;
        int[][] rotated = new int[m][m];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                rotated[j][m - 1 - i] = key[i][j];
            }
        }

        return rotated;
    }

    private boolean check(int[][] board, int m, int n) {
        for (int i = m - 1; i < m - 1 + n; i++) {
            for (int j = m - 1; j < m - 1 + n; j++) {
                if (board[i][j] != 1) {
                    return false;
                }
            }
        }

        return true;
    }
}