#include <bits/stdc++.h> 
using namespace std; 

int x,y,day;
string a[]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>x>>y;
	for(int i=1; i<x; i++){
		if(i==2){
			day+=28;
		}
		else if(i==4 || i==6 || i==9 || i==11){
			day+=30;
		}
		else {
			day+=31;
		}
//		cout<<day<<'\n';
	}
	day+=y;
	if(day%7==0){
		cout<<a[6];
	}
	else cout<<a[day%7-1];
}
