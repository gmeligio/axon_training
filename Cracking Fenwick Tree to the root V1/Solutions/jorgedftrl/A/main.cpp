#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

class bit {
        vector<int> b;
    public:
        bit(int n) {b = vector<int>(n, 0);}

        void add(int ind, int v = 1) {
            for (int x = ind; x < (int)b.size(); x += (x & (-x))) {
                b[x] += v;
            }
        }
        int query(int ind) {
            int ret = 0;
            for (int x = ind; x > 0; x -= (x & (-x))) {
                ret += b[x];
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

    int n, q; cin >> n >> q;
    vector<set<int>> a(n+1);
    bit b(q+2);
    int eid = 1;
    int readId = 0;
    for (int i = 1; i <= q; ++i) {
        int t; cin >> t;
        switch(t) {
        case 1: {
            int x; cin >> x;
            a[x].insert(eid);
            b.add(eid, 1);
            ++eid;
        }
        break;
        case 2: {
            int x; cin >> x;
            while (a[x].size() and readId >= *a[x].begin()) {
                a[x].erase(a[x].begin());
            }
            while (a[x].size()) {
                b.add(*a[x].begin(), -1);
                a[x].erase(a[x].begin());
            }
        }
        break;
        case 3: {
            int e; cin >> e;
            if (e > readId) {
                b.add(e, -b.query(e));
                readId = e;
            }
        }
        break;
        }
        cout << b.query(i) << endl;
    }

    return 0;
}
