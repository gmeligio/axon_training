#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define endl '\n'

using namespace std;

int main() {

    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    multiset<int> st;

    //Using a two-finger technik to keep track of
    //a valid interval.
    //Invariant: from lo to hi there are only two different values
    //Complexity: O(N log(N)) Could be improved to O(N) by observing that
    // we only have at most 3 different values at any time inside the pointers range.
    // Therefore, we could keep a counter for 3 different values instead of a multiset.
    int ans = 0;
    for (int lo = 0, hi = 0; hi < n; ++hi) {
        //This migh break the invariant
        st.insert(a[hi]);
        int diff = abs(*st.begin() - *st.rbegin());
        //Fix invariant
        while (lo <= hi and 1 < diff) {
            st.erase(st.find(a[lo++]));
            diff = abs(*st.begin() - *st.rbegin());
        }
        if (diff <= 1) {
            ans = max(ans, hi - lo + 1);
        }
    }

    cout << ans;

    return 0;
}
