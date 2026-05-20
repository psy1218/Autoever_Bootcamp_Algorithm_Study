#include <iostream>
#include <vector>

using namespace std;

int main()
{
    for(int tc = 1; tc <= 10; tc++)
    {
        int T;
        cin >> T;

        vector<vector<int>> ladder(100, vector<int>(100));

        int x = 99;
        int y = 0;

        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                cin >> ladder[i][j];

                if(ladder[i][j] == 2)
                {
                    x = i;
                    y = j;
                }
            }
        }

        while(x > 0)
        {

            if(y > 0 && ladder[x][y - 1] == 1)
            {
                while(y > 0 && ladder[x][y - 1] == 1)
                {
                    y--;
                }
            }

            else if(y < 99 && ladder[x][y + 1] == 1)
            {
                while(y < 99 && ladder[x][y + 1] == 1)
                {
                    y++;
                }
            }

            x--;
        }

        cout << "#" << T << " " << y << "\n";
    }

    return 0;
}