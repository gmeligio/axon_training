#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

template <class Key, class Val>
using hmap = gp_hash_table<Key, Val>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int precision = 13;
    cout.precision(precision);
    cout.setf(ios_base::fixed);

    int n; cin >> n;

    auto jump = [&n](int i, int d) -> int {
        int ret = i + d;
        if (ret > n) ret -= n;
        return ret;
    };

    auto dp = vector<vector<ll>>(n+1, vector<ll>(n+1, 1e18));
    for (int i = 1; i <= n; ++i) {
        dp[i][jump(i, 1)] = 0ll;
        dp[i][jump(i, 2)] = 1ll * i * jump(i, 1) * jump(i, 2);
    }

    for (int d = 3; d < n; ++d) {
        for (int i = 1; i <= n; ++i) {
            int j = jump(i, d);
            for (int k = jump(i, 1); k != j; k = jump(k, 1)) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + i * k * j);
            }
        }
    }

    ll ans = 1e18;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[i][jump(i, n-1)]);
    }
    cout << ans;

    return 0;
}
