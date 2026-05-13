#include <bits/stdc++.h> 
using namespace std; 

int N,type,a,b;
queue<pair<int, int>> q;
int mx=0;
int stu;
vector<int> A,B,C;

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for (int i=0; i<N; i++){
		cin>>type;
		if(type==1){
			cin>>a>>b;
			q.push({a,b});
		}
		else{
			cin>>a;
			if(a==q.front().second){
				A.push_back(q.front().first);
				q.pop();
			}
			else{
				B.push_back(q.front().first);
				q.pop();
			}
		}
	}
	while(!q.empty()){
		C.push_back(q.front().first);
		q.pop();
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	if(A.empty()){
		cout<<"None";
	}
	else{
		for(auto a : A){
			cout<<a<<' ';
		}
	}
	cout<<endl;
	if(B.empty()){
		cout<<"None";
	}
	else{
		for(auto a : B){
			cout<<a<<' ';
		}
	}
	cout<<endl;
	if(C.empty()){
		cout<<"None";
	}
	else{
		for(auto a : C){
			cout<<a<<' ';
		}
	}
}