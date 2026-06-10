#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <string>
 
using namespace std;
 
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
 
    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        cin >> N;
 
        int arr[101] = { 0 };
        for (int i = 0; i < 1000; i++)
        {
            int n;
            cin >> n;
            arr[n]++;
        }
 
        int max = arr[1];
        int bin = 1;
        for (int i = 2; i <= 100; i++)
        {
            if (max <= arr[i])
            {
                max = arr[i];
                bin = i;
            }
        }
 
        cout << "#" << tc << " " << bin << "\n";
    }
 
     
    return 0;
}