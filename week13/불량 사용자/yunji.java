import java.util.*;

class Solution {
    static Set<String> resultSet = new HashSet<>();

    public int solution(String[] user_id, String[] banned_id) {
        boolean[] visited = new boolean[user_id.length];
        dfs(user_id, banned_id, visited, 0);
        return resultSet.size();
    }

    private void dfs(String[] user_id, String[] banned_id, boolean[] visited, int depth) {
        if (depth == banned_id.length) {
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < user_id.length; i++) {
                if (visited[i]) {
                    sb.append(i);
                }
            }

            char[] arr = sb.toString().toCharArray();
            Arrays.sort(arr);
            resultSet.add(new String(arr));
            return;
        }

        for (int i = 0; i < user_id.length; i++) {
            if (!visited[i] && isMatch(user_id[i], banned_id[depth])) {
                visited[i] = true;
                dfs(user_id, banned_id, visited, depth + 1);
                visited[i] = false;
            }
        }
    }

    private boolean isMatch(String user, String banned) {
        if (user.length() != banned.length()) return false;

        for (int i = 0; i < user.length(); i++) {
            if (banned.charAt(i) == '*') continue;
            if (user.charAt(i) != banned.charAt(i)) return false;
        }

        return true;
    }
}