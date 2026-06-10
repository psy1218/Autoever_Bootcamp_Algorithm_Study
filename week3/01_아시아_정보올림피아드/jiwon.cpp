#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

struct s{
    int a,b,c;
};

int N;
vector<s> v;
vector<pair<int, int>> ans;
int cnt[101];

bool cmp(struct  s A, s B){
    return A.c>B.c;
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++){
        int c, stu, score;
        cin>>c>>stu>>score;
        v.push_back({c,stu,score});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto it : v){
        cnt[it.a]++;
        if(cnt[it.a]<3){
            ans.push_back({it.a,it.b});
        }
        if(ans.size()==3) break;
    }
    for(auto it : ans){
        cout<<it.first<<' '<<it.second<<'\n';
    }
    return 0; 
}