class Solution {
    public int solution(int[] a) {
        int answer = 2;
        if(a.length ==1) return 1;

        boolean [] isLeftMin = new boolean[a.length];
        boolean [] isRightMin = new boolean[a.length];

        int leftMin = a[0];
        for(int i = 1; i < a.length; i++){
            if(leftMin > a[i]) {
                leftMin = a[i];
                isLeftMin[i] = true;
            }
        }

        int rightMin = a[a.length-1];
        for(int i = a.length-2 ; i >= 0; i--){
            if(rightMin > a[i]){
                rightMin = a[i];
                isRightMin[i] = true;
            }
        }

        for(int i = 1; i < a.length-1; i++){
            if(isRightMin[i] || isLeftMin[i]) answer++;
        }

        return answer;
    }
}