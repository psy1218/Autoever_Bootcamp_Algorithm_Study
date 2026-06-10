#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<string, int>a, pair<string, int>b){
    if(a.second == b.second){
        if(a.first.size() == b.first.size()){
            return a.first < b.first;
        }
    
        return a.first.size() > b.first.size(); // 영어 아스키 기준 a가 b보다 더 작은데 a 가 앞으로 와야하니까 
    }

    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    string word;
    cin >> N >> M;

    map<string, int>English; //map으로 먼저 개수도 같이 카운트! 

    for(int i=0;i<N;i++){
        cin >> word;
        if(word.size() < M) continue;
        English[word]++; 
    }

    vector<pair<string,int>>study;

    for(auto it : English){ //map 요소 활용할 때 first, second 
        study.push_back({it.first, it.second});
    }

    sort(study.begin(), study.end(), compare);

    for(auto it : study){
        cout << it.first << '\n';
    }

    return 0;
}

/*
append 1
apple 2
sand 3
self 2
*/

#if 0
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool compare(map<string, int> a, map<string, int> b){

    return a[string]
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    string word;
    cin >> N >> M;

    map<string, int>English;

    for(int i=0;i<N;i++){
        cin >> word;
        if(word.size() < M) continue;
        English[word]++;
    }

    sort(English.begin(), English.end(), compare);

    return 0;
}
#endif