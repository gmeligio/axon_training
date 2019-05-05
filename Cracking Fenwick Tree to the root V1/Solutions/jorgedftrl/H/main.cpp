#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

template <class Key, class Val>
using hmap = gp_hash_table<Key, Val>;


class ft {
        vector<int> t;
    public:
        ft(int n) {
            t.assign(n, 0);
            for (int i = 1; i < n; ++i) {
                t[i] = i & -i;
            }
        }

        void off(int x) {
            while (x < (int)t.size()) {
                --t[x];
                x += x & -x;
            }
        }

        int get(int x) {
            int ret = 0;
            while (x) {
                ret += t[x];
                x -= x & -x;
            }
            return ret;
        }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int precision = 13;
    cout.precision(precision);
    cout.setf(ios_base::fixed);

    int k; cin >> k;
    while (k--) {
        int n; cin >> n;
        ft b(2 * n + 1);
        auto ans = vector<int>(n);
        for (int i = 1, r = n, last = 1; i <= n; ++i, --r) {
            int rem = i % r + 1;
            int offset = b.get(last - 1);
            int lo = last + 1;
            int hi = 2 * n;
            while (lo != hi) {
                int m = (lo + hi) / 2;
                int acc = b.get(m);
                if (acc - offset < rem) {
                    lo = m + 1;
                } else {
                    hi = m;
                }
            }
            if (lo > n) lo -= n;
            b.off(lo);
            b.off(n+lo);
            last = lo;
            ans[lo-1] = i;
        }
        for (auto i : ans) cout << i << " ";
        cout << endl;
    }


    return 0;
}
