#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 

struct s{
    string word;
    int cnt, len;
    s(string w, int c, int l) : word(w), cnt(c), len(l) {}
};

unordered_map<string, int> umap;
priority_queue<int> pq;
int N,M;
vector<s> v;

bool cmp(struct s A, s B){
    if(A.cnt==B.cnt){
        if(A.len==B.len){
            return A.word<B.word;
        }
        return A.len>B.len;
    }
    return A.cnt>B.cnt;
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        string s;
        cin>>s;
        if(s.size()>=M){
            umap[s]++;
        }
    }
    for(auto it : umap){
        v.push_back({it.first, it.second, it.first.size()});
    }
    // for(auto it : v){
    //     cout<<it.word<<' '<<it.cnt<<' '<<it.len<<endl;
    // }
    sort(v.begin(), v.end(), cmp);
    for(auto it : v){
        cout<<it.word<<'\n';
    }
}