#include <bits/stdc++.h> 
using namespace std; 

long long T;
long long dp[32][32];

long long go(int whole, int half){
	if(whole==0 && half==0) return 1; //먹는 방법 1 추가 
	long long &res=dp[whole][half];
	if(res) return res;
	if(whole>0) res += go(whole-1, half+1); //전체 있을때 
	if(half>0) res+= go(whole, half-1); //반 있을때 
	return res;
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	while(cin>>T){
		if(T==0) break;
		cout<<go(T,0)<<'\n';
	}
}