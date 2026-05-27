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

    for (int tc = 1; tc <= 10; tc++)
    {
        int n;
        cin >> n;
        int ans = 1;

        vector<char> v(n);
        
        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;
            
            if (c == '<' || c == '(' || c == '{' || c == '[') v.push_back(c);

            else if (c == '>') {
                if (v.empty()) {
                    ans = 0;
                    continue;
                }
                else if (v.back() == '<') {
                    v.pop_back();
                }
                else {
                    ans = 0;
                    continue;
                }
            }

            else if (c == ')') {
                if (v.empty()) {
                    ans = 0;
                    continue;
                }
                else if (v.back() == '(') {
                    v.pop_back();
                }
                else {
                    ans = 0;
                    continue;
                }
            }

            else if (c == '}') {
                if (v.empty()) {
                    ans = 0;
                    continue;
                }
                else if (v.back() == '{') {
                    v.pop_back();
                }
                else {
                    ans = 0;
                    continue;
                }
            }

            else if (c == ']') {
                if (v.empty()) {
                    ans = 0;
                    continue;
                }
                else if (v.back() == '[') {
                    v.pop_back();
                }
                else {
                    ans = 0;
                    continue;
                }
            }
        }

        cout << "#" << tc << " " << ans << "\n";
    }

    
    return 0;
}