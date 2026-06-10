import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        list = new ArrayList<>();
        for(int i = 0; i < N; i++) list.add(new ArrayList<>());

        for(int i = 0 ; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list.get(a).add(b);
            list.get(b).add(a);
        }

        isPos = false;

        for(int i = 0 ; i < N; i++){
            boolean [] isVisit = new boolean[N];
            int cnt = 0;

            isVisit[i] = true;
            findMaxLen5(i, isVisit, cnt);

            if(isPos) {
                System.out.println(1);
                return;
            }
        }

        System.out.println(0);

    } // end of main
    static boolean isPos;
    static List<List<Integer>> list;
    static void findMaxLen5(int start, boolean [] isVisit , int cnt){
        if(cnt >= 4) {
            isPos = true;
            return;
        }

        for(int x : list.get(start)){
            if(isVisit[x]) continue;
            isVisit[x] = true;
            findMaxLen5(x, isVisit, cnt + 1);
            isVisit[x] = false;
        }


    }
} // end of class