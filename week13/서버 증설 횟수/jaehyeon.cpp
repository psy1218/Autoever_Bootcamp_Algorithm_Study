#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> server(48, 0);
    
    for(int i=0; i<24; i++)
    {
        if(players[i]/m>server[i])
        {
            int up=(players[i]/m-server[i]);
            answer+=up;
            for(int j=i; j<i+k; j++)
            {
                server[j]+=up;
            }
        }
    }
    
    return answer;
}