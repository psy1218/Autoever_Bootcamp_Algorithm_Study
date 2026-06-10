#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    for(int tc = 1; tc <= 10; tc++)
    {
        int t;
        cin >> t;

        vector<vector<int>> arr(100, vector<int>(100));

        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                cin >> arr[i][j];
            }
        }

        int answer = 0;

        // 행
        for(int i = 0; i < 100; i++)
        {
            int sum = 0;

            for(int j = 0; j < 100; j++)
            {
                sum += arr[i][j];
            }

            answer = max(answer, sum);
        }

        // 열
        for(int j = 0; j < 100; j++)
        {
            int sum = 0;

            for(int i = 0; i < 100; i++)
            {
                sum += arr[i][j];
            }

            answer = max(answer, sum);
        }

        // 왼위 -> 오아
        int diag1 = 0;

        for(int i = 0; i < 100; i++)
        {
            diag1 += arr[i][i];
        }

        answer = max(answer, diag1);

        // 오위 -> 왼아
        int diag2 = 0;

        for(int i = 0; i < 100; i++)
        {
            diag2 += arr[i][99 - i];
        }

        answer = max(answer, diag2);

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}