#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

string s;
int k;
int ans;

set<string> check[11];

void solve(int depth)
{
    if(depth == k)
    {
        ans = max(ans, stoi(s));
        return;
    }

    if(check[depth].count(s)) return;
    check[depth].insert(s);

    int len = s.size();

    for(int a = 0; a < len - 1; a++)
    {
        for(int b = a + 1; b < len; b++)
        {
            swap(s[a], s[b]);

            solve(depth + 1);

            swap(s[a], s[b]);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++)
    {
        cin >> s >> k;

        ans = 0;

        for(int i = 0; i < 11; i++)
        {
            check[i].clear();
        }

        solve(0);

        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}