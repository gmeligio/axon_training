#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

using hmap = gp_hash_table<int, int>;


class ft {
        vector<ll> t;
    public:
        ft(int n) {t = vector<ll>(n);}

        void add(int x, ll val) {
            while (x < (int)t.size()) {
                t[x] += val;
                x += x & -x;
            }
        }

        void radd(int x, int y, ll val) {
            add(x, val);
            add(y+1, -val);
        }

        ll get(int x) {
            ll ret = 0;
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

    int n, m, c; cin >> n >> m >> c;
    ft b(n+2);

    b.radd(1, n, c);
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        if ("Q" == s) {
            int q; cin >> q;
            cout << b.get(q) << endl;
        } else {
            int l, r; ll q; cin >> l >> r >> q;
            l = max(1, min(n, l));
            r = max(1, min(n, r));
            if (l > r) swap(l, r);
            b.radd(l, r, q);
        }
    }

    return 0;
}
