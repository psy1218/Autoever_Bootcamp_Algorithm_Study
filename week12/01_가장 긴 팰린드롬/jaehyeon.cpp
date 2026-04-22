#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=1;
    
    for(int i=0; i<s.size()-1; i++)
    {
        int a=i; //왼쪽으로
        int b=i; //오른쪽으로
        
        while(s[a]==s[b])
        {
            a--;
            b++;
            answer=max(answer, b-a-1);
            if(a==-1 || b==s.size()) break;
        }
        
        a=i; //왼쪽으로
        b=i; //오른쪽으로
        
        if(s[i]==s[i+1])
        {
            b++;
            while(s[a]==s[b])
            {
                a--;
                b++;
                answer=max(answer, b-a-1);
                if(a==-1 || b==s.size()) break;
            }
            
        }
        
        
    }

    

    return answer;
}