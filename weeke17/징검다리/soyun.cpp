#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);

    int left = 1;
    int right = distance;

    while (left <= right) {
        int mid = (left + right) / 2;

        int prev = 0;
        int remove_cnt = 0;

        for (int i = 0; i < rocks.size(); i++) {
            int diff = rocks[i] - prev;

            if (diff < mid) {
                remove_cnt++;
            }
            else {
                prev = rocks[i];
            }
        }

        if (remove_cnt <= n) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return answer;
}