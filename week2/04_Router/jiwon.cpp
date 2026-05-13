#include <bits/stdc++.h> 
using namespace std; 

int N,a;
queue<int> q;

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	while(cin>>a){
		if(a==-1){
			break;
		}
		else if(a==0){
			q.pop();
		}
		else if(q.size()<N){
			q.push(a);
		}
	}
	if(q.empty()){
		cout<<"empty";
	}
	while(!q.empty()){
		cout<<q.front()<<' ';
		q.pop();
	}
}