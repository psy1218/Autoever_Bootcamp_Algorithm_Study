#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T,N;
int price[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>T;
    for(int t=1; t<=T; t++){
        cin>>N;
        for(int i=0; i<N; i++) cin>>price[i];

        long long ans=0;
        int max_val=price[N-1]; // 맨 뒤의 값을 초기 최고가로 설정

        for(int i=N-2; i>=0; i--){
            if(price[i]>max_val) max_val=price[i]; // 더 큰 값을 만나면 최고가 갱신
            else ans+=max_val-price[i]; // 최고가보다 작으면 그 차액만큼 이득 보존
        }
        cout<<"#"<<t<<" "<<ans<<'\n';
    }
    return 0;
}