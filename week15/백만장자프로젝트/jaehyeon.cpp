#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++)
    {
        int N;
        cin >> N;

        vector<int> price(N);

        for(int i = 0; i < N; i++)
        {
            cin >> price[i];
        }

        long long answer = 0;
        int maxPrice = 0;

        for(int i = N - 1; i >= 0; i--)
        {
            if(price[i] > maxPrice)
            {
                maxPrice = price[i];
            }
            else
            {
                answer += maxPrice - price[i];
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}