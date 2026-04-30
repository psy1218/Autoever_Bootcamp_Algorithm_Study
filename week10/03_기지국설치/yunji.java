class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;

        int range = 2*w + 1;

        for(int i = 0 ; i < stations.length; i++){
            int len = 0;
            if(i != 0)
                len = (stations[i] - w) - (stations[i-1] + w) - 1;
            else len = stations[i] - w - 1;

            if(len <=0) continue;
            answer += (len%range == 0 ? len/range : len/range + 1);
        }

        int len = n - (stations[stations.length-1] + w);
        if(len >0){
            answer += (len%range == 0 ? len/range : len/range + 1);
        }



        return answer;
    }
}