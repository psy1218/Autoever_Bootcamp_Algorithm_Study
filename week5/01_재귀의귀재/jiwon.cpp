#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std; 

int T,cnt;

int recursion(const string& s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const string& s){
    return recursion(s, 0, s.size()-1);
}

int main(){
    cin>>T;
    for(int i=0; i<T; i++){
        cnt=0;
        string s;
        cin>>s;
        cout<<isPalindrome(s)<<' '<<cnt<<'\n';
    }
}