#include <bits/stdc++.h> 
using namespace std; 

int N;
char a[51][51];
char temp[51][51];
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int m=-1e9;
int cnt;

void check(int dir, int x, int y){
	int nx=x+dx[dir];
	int ny=y+dy[dir];
	if(a[x][y]==a[nx][ny]){
		cnt++;
		check(dir,nx,ny);
	}
	else return;
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	for(int i=0; i<N; i++){
		string s;
		cin>>s; 
		for(int j=0; j<N; j++){
			a[i][j]=s[j];
		}
	} 
	memcpy(temp, a, sizeof(a));
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<4; k++){
				int nx=i+dx[k];
				int ny=j+dy[k];
				if(nx<0||nx>=N||ny<0||ny>=N) break;
				memcpy(a, temp, sizeof(temp));
				if(a[i][j]!=a[nx][ny]){
					char orig=a[i][j];
					a[i][j]=a[nx][ny];
					a[nx][ny]=orig;
					for(int i=0; i<N; i++){
						for(int j=0; j<N; j++){
							for(int k=0; k<4; k++){
								cnt=1;
								check(k,i,j);
//								cout<<cnt;
								m=max(m,cnt);
							}
						}
					}
				}
			}
		}
	}
	cout<<m;
}
