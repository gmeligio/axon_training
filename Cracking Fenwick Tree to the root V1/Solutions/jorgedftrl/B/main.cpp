#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

template <class T>
class bit {
        vector<T> t;
    public:
        bit(int n) {
            t = vector<T>(n, 0);
        }
        bit(vector<T> &a):bit((int)a.size()+1){
            for (int i = 0; i < (int)a.size(); ++i) {
                add(i+1, a[i]);
            }
        }
        void add(int ind, T v) {
            for (int x = ind; x < (int)t.size(); x += x & -x) {
                t[x] += v;
            }
        }

        T query(int ind) {
            T ret = T{};
            for (int x = ind; x > 0; x -= x & -x) {
                ret += t[x];
            }
            return ret;
        }

        T rquery(int from, int to) {
            return query(to) - query(from-1);
        }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int precision = 13;
    cout.precision(precision);
    cout.setf(ios_base::fixed);

    int n;
    int kase = 1;
    bool first = true;
    while(cin >> n) {
        if (n == 0) break;
        if (!first) cout << endl;
        first = false;

        cout << "Case " << kase++ << ":" << endl;
        vector<ll> a(n);
        for (auto &it : a) cin >> it;
        bit<ll> b(a);
        string s;
        while(cin >> s) {
            if ("END" == s) break;
            if ("S" == s) {
                int x, r; cin >> x >> r;
                b.add(x, -b.rquery(x, x));
                b.add(x, r);
            } else if ("M" == s) {
                int x, y; cin >> x >> y;
                cout << b.rquery(x, y) << endl;
            } else {
                cout.flush();
                throw std::invalid_argument("shit");
            }
        }
    }

    return 0;
}
