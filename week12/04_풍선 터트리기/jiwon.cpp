#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    // 살아남으려면 왼쪽 최솟값과 오른쪽 최솟값 중 하나 이상보다 작아야함
    int n=a.size();
    vector<int> left(n);
    vector<int> right(n);
    left[0]=a[0];
    right[n-1]=a[n-1];
    for(int i=1; i<n; i++){
        left[i]=min(left[i-1],a[i]);
    }
    for(int i=n-2; i>=0; i--){
        right[i]=min(right[i+1],a[i]);
    }
    for(int i=0; i<n; i++){
        if(i==0 || i==n-1){
            answer++;
        }
        else{
            if(left[i-1]<a[i] && a[i]>right[i+1]) continue;
            answer++;
        }
    }
    return answer;
}