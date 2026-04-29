#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool jing(vector<int>& stones, int k, int a)
{
    int sum_jump=0;
    for(int i=0; i<stones.size(); i++)
    {
        if(stones[i]>=a) 
        {
            sum_jump=0;
            continue;
        }
        else
        {
            sum_jump++;
            if(sum_jump>=k) return false;
            continue;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(jing(stones, k, mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    return answer;
}