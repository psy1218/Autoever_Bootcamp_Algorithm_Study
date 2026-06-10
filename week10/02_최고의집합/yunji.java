class Solution {
    public int[] solution(int n, int s) {
        if(n > s) {
            int [] answer = new int[1];
            answer[0] = -1;
            return answer;
        }
        int[] answer = new int[n];

        int div = s/n;
        int remain = s%n;

        int i;
        for(i = 0 ; i < n-remain; i++){
            answer[i] = div;
        }
        for(i = i ; i <n; i++){
            answer[i] = div+1;
        }

        return answer;
    }
}