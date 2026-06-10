#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 시작부터 끝까지 하나씩 중심을 잡고 left, right 설정해서 살펴봄.
// 짝수일 때, 홀수일 때 둘 다 봐야함... 난.. 한 개만 봄 ㅜ
// 예를 들어서 bbbbb 이면 5가 나와야하는데 짝수만 봐서 4가 계속 나왔음.
// i와 i+1이 같은지를 판단해서 홀수 짝수 나눴음. 

int solution(string s){
    int answer = 0;
    int flag = 0, left, right;
    int cnt = 1, Max = 1, k = 1;
    
    for(int i=0;i<s.size();i++){
        left = i - 1;
        k = i+1;
        
        if(k < s.size() && s[i] == s[k]){
            right = i + 2;
            cnt = 1;
            flag = 0;
            
            while(1){
                if(left < 0 || right >= s.size() || s[left] != s[right] ) {
                    if(flag == 1) Max = max(Max, cnt * 2 - 1);
                    else Max = max(Max, cnt * 2);
                    cnt = 1;
                    break;
                }
                cnt++;
                left--;
                right++;
            }   
        }
        left = i - 1;

        cnt = 1;
        right = i + 1;
        flag = 1;

        while(1){
            if(left < 0 || right >= s.size() || s[left] != s[right] ) {
                if(flag == 1) Max = max(Max, cnt * 2 - 1);
                else Max = max(Max, cnt * 2);
                cnt = 1;
                break;
            }
            cnt++;
            left--;
            right++;
        }     
        
    }
    answer = Max;
    return answer;
}



// s의 처음부터 끝까지 보려고 함. 
/*
int solution(string s)
{
    int answer=0;
    int Max = 1;

    int real_right = s.size() - 1, left = 0;
    int cnt = 1;

    for(int i=0;i<s.size();i++){
        left = i;
        int right = real_right;
        
        cnt = 0;
        while(left < right){
            if(s[left] == s[right]){
                cnt += 1;
                left++;
                right--;
                Max = max(Max, cnt);
            }
            else{
                Max = max(Max, cnt);
                cnt = 1;
                right--;
            }
        }
    }
    
    cout << Max << ' ';
    if(Max % 2 == 1) answer = Max*2 - 1;
    else answer = Max*2 - 2;
    return answer;
}


*/