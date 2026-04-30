import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        arr = new char[C];


        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < C; i++){

            arr[i] = st.nextToken().charAt(0);
        }

        hs = new HashSet<>();
        hs.add('a');
        hs.add('e');
        hs.add('i');
        hs.add('o');
        hs.add('u');

        Arrays.sort(arr);

        findSequence(0, 0, 0, 0, new char[L]);


        System.out.println(sb.toString());

    } // end of main
    static StringBuilder sb;
    static int L,C;
    static char []arr;
    static HashSet<Character> hs;
    public static void findSequence(int cnt, int id, int m, int j, char[] curr){
        if(cnt == L){
            if(!(m >= 1 && j >=2)) return;
            for(int i = 0 ; i <L; i++){
                sb.append(curr[i]);
            }
            sb.append("\n");
            return;
        }

        for(int i = id ; i < C; i++){
            curr[cnt] = arr[i];
            if(hs.contains(arr[i])) findSequence(cnt+1, i+1, m + 1, j, curr);
            else findSequence(cnt + 1, i + 1, m, j+1, curr);
        }

    }

} // end of class

