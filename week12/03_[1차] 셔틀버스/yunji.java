import java.util.*;

class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        String answer = "";

        int [] timeInt = new int [timetable.length];
        for(int i = 0 ; i < timetable.length; i++){
            StringTokenizer st = new StringTokenizer(timetable[i], ":");
            timeInt[i] = Integer.parseInt(st.nextToken()) * 60;
            timeInt[i] += Integer.parseInt(st.nextToken());

        }

        Arrays.sort(timeInt);


        int id = 0;
        int currTime = 9 * 60;

        while(n >= 2){
            n--;

            int mCopy = m;
            while(id < timeInt.length && mCopy > 0){
                if(timeInt[id] > currTime) break;
                id++;
                mCopy--;
            }
            currTime += t;

        }
        int result = -1;

        if(timetable.length - id  < m) result = currTime;
        else {
            if(timeInt[id+m-1] <= currTime) result = timeInt[id+m-1] -1;
            else result = currTime;
        }

        int hour = result/60;
        int min = result%60;
        if(hour>9) answer += hour;
        else answer += "0" + hour;
        answer += ":";
        if(min >9) answer += min;
        else answer += "0" + min;


        return answer;
    }
}