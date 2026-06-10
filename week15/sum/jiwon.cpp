#include <iostream>
#include <algorithm>
using namespace std;

int tc;
int arr[100][100];

int main(){
    for(int t=0; t<10; t++){
        cin>>tc;
        int ans=0;

        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                cin>>arr[i][j];
            }
        }
        int d1=0, d2=0; // d1: 좌상->우하 대각선, d2: 우상->좌하 대각선
        for(int i=0; i<100; i++){
            int row_sum=0, col_sum=0;
            for(int j=0; j<100; j++){
                row_sum+=arr[i][j];
                col_sum+=arr[j][i]; // 행과 열을 동시에 계산
            }
            ans=max({ans, row_sum, col_sum});
            d1+=arr[i][i];
            d2+=arr[i][99-i];
        }
        ans=max({ans, d1, d2});

        cout<<"#"<<tc<<" "<<ans<<'\n';
    }
    return 0;
}