#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

int n,w,l,cnt,weight;
queue<int> b;
queue<int> list;

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++){
		int a;
		cin>>a;
		list.push(a);
	}
	// b에 0 채우기
	for (int i = 0; i < w; i++){
		b.push(0);
	}
	while(!b.empty()){
		int out = b.front();
		// 나갈 애가 0이 아니면 weight에서 빼기
		if(out>0){
			weight -= out;
		}
		// cout<<out<<endl;
		b.pop();
		if(!list.empty()){
			int f = list.front();
			if(f+weight<=l){
				b.push(f);
				weight += f;
				list.pop();
			}
			else{
				b.push(0);
			}
		}
		cnt++;
	}
	cout<<cnt;
}