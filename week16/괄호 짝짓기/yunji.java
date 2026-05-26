import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int tc = 1; tc <= 10; tc++) {
            int len = Integer.parseInt(br.readLine());
            String str = br.readLine();

            Stack<Character> stack = new Stack<>();
            int result = 1;

            for (int i = 0; i < len; i++) {
                char ch = str.charAt(i);

                if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
                    stack.push(ch);
                } else {
                    if (stack.isEmpty()) {
                        result = 0;
                        break;
                    }

                    char open = stack.pop();

                    if ((open == '(' && ch != ')') ||
                            (open == '[' && ch != ']') ||
                            (open == '{' && ch != '}') ||
                            (open == '<' && ch != '>')) {

                        result = 0;
                        break;
                    }
                }
            }

            if (!stack.isEmpty()) {
                result = 0;
            }

            sb.append("#").append(tc).append(" ").append(result).append("\n");
        }

        System.out.print(sb);
    }


}