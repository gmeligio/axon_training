#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {

    int n, k; cin >> n >> k;
    int prev = k;
    int ans = 0;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        int t = max(ai, k-prev);
        ans += t > ai ? t - ai : 0;
        b[i] = t;
        prev = t;
    }
    cout << ans << endl;
    for (auto i : b) cout << i << " ";

    return 0;
}
