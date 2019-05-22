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

    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int tot = accumulate(a.begin(), a.end(), 0);
    if (tot%360==0) {
        cout << "YES";
        return 0;
    }

    //this problem is an special case of subset sum
    //sol: try all subsets and check which partition
    //     of the initial set can finish at degree 0
    for (int mask = 1; mask < (1<<n); ++mask) {
        int msk_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask&(1<<i)) msk_sum += a[i];
        }
        if (tot >= 2*msk_sum and (tot-2*msk_sum)%360 == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}
