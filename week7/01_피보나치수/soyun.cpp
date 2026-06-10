#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int arr[46] = {0,};
    arr[0] = 0;
    arr[1] = 1;

    for(int i=2;i<46;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << arr[n] << '\n';

    return 0;
}
/*
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
*/