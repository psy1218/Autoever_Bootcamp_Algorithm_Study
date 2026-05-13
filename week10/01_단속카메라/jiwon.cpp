#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int cam=routes[0][1];
    for(int i=1; i<routes.size(); i++){
        if(cam<routes[i][0]){
            answer++;
            cam=routes[i][1];
        }
        else {
            cam=min(cam, routes[i][1]);
        }
    }
    return answer;
}