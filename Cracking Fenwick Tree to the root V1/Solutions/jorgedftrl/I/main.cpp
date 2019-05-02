#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

template <class T>
class Bit2D {
        vector<vector<T>> t;
    public:
        Bit2D(int n = 2000, int m = 2000) {
            t = vector<vector<T>>(n, vector<T>(m, T{}));
        }

        void add(int x, int yy, T v) {
            while (x < (int)t.size()) {
                int y = yy;
                while (y < (int)t[x].size()) {
                    t[x][y] += v;
                    y += y & -y;
                }
                x += x & -x;
            }
        }

        T get(int x, int yy) {
            T ret = T{};
            while (x) {
                int y = yy;
                while (y) {
                    ret += t[x][y];
                    y -= y & -y;
                }
                x -= x & -x;
            }
            return ret;
        }

        T rget(int x1, int y1, int x2, int y2) {
            --x1; --y1;
            T incl = get(x1, y1) + get(x2, y2);
            T excl = get(x1, y2) + get(x2, y1);
            return incl - excl;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int precision = 13;
    cout.precision(precision);
    cout.setf(ios_base::fixed);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        Bit2D<int> b(n+2, n+2);
        string s; cin >> s;
        while ("END" != s) {
            if ("SUM" == s) {
                int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
                ++x1; ++y1; ++x2; ++y2;
                cout << b.rget(x1, y1, x2, y2) << endl;
            } else {
                int x, y, v; cin >> x >> y >> v;
                ++x; ++y;
                auto cur = b.rget(x, y, x, y);
                b.add(x, y, -cur);
                b.add(x, y, v);
            }
            cin >> s;
        }
    }

    return 0;
}
