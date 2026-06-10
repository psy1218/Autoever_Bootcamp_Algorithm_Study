#include <iostream>
#include <vector>
using namespace std;

int tc;
int ladder[100][100];

int main(){
    for(int t=0; t<10; t++){
        cin>>tc;
        int x=0, y=99;

        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                cin>>ladder[i][j];
                if(i==99 && ladder[i][j]==2){
                    x=j;
                }
            }
        }
        while(y>0){
            if(x-1>=0 && ladder[y][x-1]==1){
                while(x-1>=0 && ladder[y][x-1]==1) x--;
            }
            else if(x+1<100 && ladder[y][x+1]==1){
                while(x+1<100 && ladder[y][x+1]==1) x++;
            }
            y--;
        }
        cout<<"#"<<tc<<" "<<x<<'\n';
    }
    return 0;
}