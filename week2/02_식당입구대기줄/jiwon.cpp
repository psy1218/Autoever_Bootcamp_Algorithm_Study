#include <bits/stdc++.h> 
using namespace std; 

int N,a,b;
queue<int> s;
int mx=0;
int stu;

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for (int i=0; i<N; i++){
		cin>>a;
		if(a==1){
			cin>>b;
			s.push(b);
			if(mx==s.size()&&stu>b){
				stu=b;
//				cout<<stu;
			}
			else if(mx<s.size()){
				mx=s.size();
				stu=b;
			}
		}
		else if(!s.empty()){
			s.pop();
		}
	}
	cout<<mx<<' '<<stu;
}
