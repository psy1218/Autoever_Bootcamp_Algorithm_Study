#include <bits/stdc++.h> 
using namespace std; 

int N,K,cnt;
bool a[1000];

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>K;
	for(int i=2; i<=N; i++){
		for(int j=0; j<=N-i; j+=i){
			if(!a[i+j]){
				cnt++;
				a[i+j]=true;
//				cout<<i+j<<' '<<'\n';
//				cout<<cnt<<'\n';
			}
			if(cnt==K){
				cout<<i+j;
				exit(0);
			}
		}
	}
}
