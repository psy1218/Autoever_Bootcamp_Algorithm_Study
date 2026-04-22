class Solution
{
    public int solution(String s)
    {
        int answer = 1;

        int N = s.length();
        int [][] palindrome = new int[N][N];

        for(int i = 0 ; i < N; i++){
            palindrome[i][i] = 1;
            if(i == 0) continue;
            if(s.charAt(i) == s.charAt(i-1)) palindrome[i-1][i] = 1;
            else palindrome[i][i-1] = -1;

            if(palindrome[i-1][i] == 1) {
                answer  = 2;
            }
        }

        for(int i = 2 ; i < N; i++){
            for(int j = 0 ; j < N-i; j++){
                int left = j;
                int right = j+i;
                if(s.charAt(left) == s.charAt(right) && palindrome[left+1][right -1] == 1) palindrome[left][right] = 1;

                if(palindrome[left][right] == 1) {
                    answer  = Math.max(answer, right -left + 1);
                }
            }
        }


        return answer;
    }
}