#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s) {
    if(n>s) return {-1};
    int a=s/n;
    int b=s%n;
    vector<int> answer(n,a);
    for(int i=0; i<b; i++){
        answer[n-1-i]++;
    }
    return answer;
}