import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        char [] manOrWoman = new char[N+1];

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <=N; i++){
            manOrWoman[i] = (st.nextToken()).charAt(0);
        }




        PriorityQueue<int []> pq = new PriorityQueue<>((a,b) ->{
            return a[2] - b[2];
        });


        for(int i= 0; i< M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b =Integer.parseInt(st.nextToken());
            int dis = Integer.parseInt(st.nextToken());

            if(manOrWoman[a] == manOrWoman[b]) continue;
            pq.add(new int[]{a,b,dis});
        }

        parent = new int[N+1];
        for(int i = 1; i <=N; i++) parent[i] = i;

        int minValue = 0;
        int cnt = 0;
        while(cnt<N-1 && !pq.isEmpty()){
            int [] curr = pq.poll();
            if(!union(curr[0], curr[1])) continue;
            minValue += curr[2];
            cnt++;

        }

        if(cnt == N-1) sb.append(minValue);
        else sb.append(-1);

        System.out.println(sb.toString());

    } // end of main
    static int [] parent;
    static boolean union(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return false;

        parent[pb] = pa;
        return true;
    }
    static int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

} // end of class

