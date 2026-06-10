#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,pair<int,int>>>info;
int okay[1001] = {0,};

bool compare(pair<int,pair<int,int>> left, pair<int,pair<int,int>>right){

    return left.second.second > right.second.second;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, country, student, grade;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> country >> student >> grade;
        info.push_back({country, {student, grade}});
    }

    sort(info.begin(), info.end(), compare);

    int cnt = 0;
    for(auto it : info){
        if(cnt == 3) break;

        if(okay[it.first] < 2){
            okay[it.first] ++;
            cout << it.first << ' ' << it.second.first << '\n';
            cnt ++;
        }
    }

    return 0;
}