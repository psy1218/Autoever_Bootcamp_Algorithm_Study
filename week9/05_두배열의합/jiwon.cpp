#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int T,n,m;
int a[1001], b[1001];
int aa[1001], bb[1001];
long long cnt;
vector<long long> asum, bsum;

int main(){
    cin>>T>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        aa[i]=aa[i-1]+a[i];
    }
    cin>>m;
    for(int i=1; i<=m; i++){
        cin>>b[i];
        bb[i]=bb[i-1]+b[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<=n; j++){
            asum.push_back(aa[j]-aa[i]);
        }
    }
    for(int i=0; i<m; i++){
        for(int j=i+1; j<=m; j++){
            bsum.push_back(bb[j]-bb[i]);
        }
    }
    sort(bsum.begin(),bsum.end());
    for(int i=0; i<asum.size(); i++){
        int a=asum[i];
        cnt+=upper_bound(bsum.begin(), bsum.end(), T-a) - lower_bound(bsum.begin(), bsum.end(), T-a);
    }
    cout<<cnt;
    return 0;
}