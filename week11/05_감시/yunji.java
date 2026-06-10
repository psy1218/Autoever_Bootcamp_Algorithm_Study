import java.util.*;
import java.io.*;

public class Main {
    static class CCTV{
        int r;
        int c;
        int type;
        public CCTV(int r, int c, int type){
            this.r = r;
            this.c = c;
            this.type =type;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        cctvList = new ArrayList<>();

        int notDetect = 0;

        for(int i = 0 ; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0 ; j < M; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] <= 5 && map[i][j] >= 1) cctvList.add(new CCTV(i, j, map[i][j]));
                if(map[i][j] == 0) notDetect++;
            }
        }

        minDetect = Integer.MAX_VALUE;

        cctvCnt = cctvList.size();

        cctvDetect(new boolean [N][M], 0, notDetect);

        sb.append(minDetect);

        System.out.println(sb.toString());

    } // end of main
    static int cctvCnt, N, M;
    static int minDetect;
    static ArrayList<CCTV> cctvList;
    static int [] dr = {-1,1,0,0};
    static int [] dc = {0, 0, -1, 1};
    static int [][] map;
    public static void cctvDetect(boolean [][] isVisit, int id, int currDetect){
        if(id == cctvCnt){
            minDetect = Math.min(minDetect, currDetect);
            return;
        }

        int currR = cctvList.get(id).r;
        int currC = cctvList.get(id).c;
        int currT = cctvList.get(id).type;

        if(currT == 1){
            for(int d = 0 ; d < 4; d++){
                List<int []> changed = new ArrayList<>();
                int cntDetect = watch(isVisit, currR, currC, d, changed);

                cctvDetect(isVisit, id + 1, currDetect - cntDetect);

                for(int [] x : changed){
                    isVisit[x[0]][x[1]] = false;
                }
            }
        }else if(currT == 2){
            for(int d = 0; d < 2; d++){
                List<int []> changed = new ArrayList<>();
                int cntDetect = 0;

                cntDetect += watch(isVisit, currR, currC, d, changed);
                cntDetect += watch(isVisit, currR, currC, d + 2, changed);

                cctvDetect(isVisit, id + 1, currDetect - cntDetect);

                for(int [] x : changed){
                    isVisit[x[0]][x[1]] = false;
                }
            }
        }else if(currT == 3){
            for(int d = 0; d < 4; d++){
                List<int []> changed = new ArrayList<>();
                int cntDetect = 0;

                cntDetect += watch(isVisit, currR, currC, d, changed);
                cntDetect += watch(isVisit, currR, currC, (d + 1) % 4, changed);

                cctvDetect(isVisit, id + 1, currDetect - cntDetect);

                for(int [] x : changed){
                    isVisit[x[0]][x[1]] = false;
                }
            }
        }else if(currT == 4){
            for(int d = 0; d < 4; d++){
                List<int []> changed = new ArrayList<>();
                int cntDetect = 0;

                cntDetect += watch(isVisit, currR, currC, d, changed);
                cntDetect += watch(isVisit, currR, currC, (d + 1) % 4, changed);
                cntDetect += watch(isVisit, currR, currC, (d + 2) % 4, changed);

                cctvDetect(isVisit, id + 1, currDetect - cntDetect);

                for(int [] x : changed){
                    isVisit[x[0]][x[1]] = false;
                }
            }
        }else if(currT == 5){
            List<int []> changed = new ArrayList<>();
            int cntDetect = 0;

            for(int d = 0; d < 4; d++){
                cntDetect += watch(isVisit, currR, currC, d, changed);
            }

            cctvDetect(isVisit, id + 1, currDetect - cntDetect);

            for(int [] x : changed){
                isVisit[x[0]][x[1]] = false;
            }
        }

    }

    public static int watch(boolean[][] isVisit, int startR, int startC, int d, List<int[]> changed) {
        int cntDetect = 0;

        int nr = startR + dr[d];
        int nc = startC + dc[d];

        while (nr >= 0 && nc >= 0 && nr < N && nc < M && map[nr][nc] != 6) {
            if (map[nr][nc] == 0 && !isVisit[nr][nc]) {
                isVisit[nr][nc] = true;
                cntDetect++;
                changed.add(new int[]{nr, nc});
            }
            nr += dr[d];
            nc += dc[d];
        }

        return cntDetect;
    }// end of watch

} // end of class

