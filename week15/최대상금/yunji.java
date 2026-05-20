import java.io.*;
import java.util.*;

public class Solution {

    static int answer;
    static int changeCount;
    static Set<String>[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            String number = st.nextToken();
            changeCount = Integer.parseInt(st.nextToken());

            answer = 0;
            visited = new HashSet[changeCount + 1];

            for (int i = 0; i <= changeCount; i++) {
                visited[i] = new HashSet<>();
            }

            dfs(number.toCharArray(), 0);

            sb.append("#").append(tc).append(" ").append(answer).append("\n");
        }

        System.out.print(sb);
    }

    static void dfs(char[] arr, int depth) {
        String current = new String(arr);

        if (visited[depth].contains(current)) {
            return;
        }

        visited[depth].add(current);

        if (depth == changeCount) {
            answer = Math.max(answer, Integer.parseInt(current));
            return;
        }

        int len = arr.length;

        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                swap(arr, i, j);
                dfs(arr, depth + 1);
                swap(arr, i, j);
            }
        }
    }

    static void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}