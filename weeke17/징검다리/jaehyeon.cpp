#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);

    int ans = 0;

    int st = 1;
    int en = distance;

    while (st <= en) {
        int mid = (st + en) / 2;

        int cnt = 0;
        int prev = 0;

        for (int i = 0; i < rocks.size(); i++) {
            int gap = rocks[i] - prev;

            if (gap < mid) {
                cnt++;
            }
            else {
                prev = rocks[i];
            }
        }

        if (cnt <= n) {
            ans = mid;
            st = mid + 1;
        }
        else {
            en = mid - 1;
        }
    }

    return ans;
}