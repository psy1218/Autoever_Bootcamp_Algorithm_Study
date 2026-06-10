#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int sz = money.size();

    vector<int> a(sz, 0);
    vector<int> b(sz, 0);

    a[0] = money[0];
    a[1] = max(money[0], money[1]);

    for (int i = 2; i < sz - 1; i++) {
        a[i] = max(a[i - 1], a[i - 2] + money[i]);
    }

    b[1] = money[1];

    for (int i = 2; i < sz; i++) {
        b[i] = max(b[i - 1], b[i - 2] + money[i]);
    }

    int x = a[sz - 2];
    int y = b[sz - 1];

    return max(x, y);
}