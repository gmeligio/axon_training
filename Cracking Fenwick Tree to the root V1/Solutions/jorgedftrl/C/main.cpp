#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

template<class T>
class bit {
        vector<T> t;
    public:
        bit(int n) {
            t = vector<T>(n, T{});
        }

        void add(int x, T v) {
            while (x < (int)t.size()) {
                t[x] += v;
                x += x & -x;
            }
        }

        T query(int x) {
            T ret = T{};
            while (x) {
                ret += t[x];
                x -= x & -x;
            }
            return ret;
        }

        T rquery(int x, int y) {
            return query(y) - query(x-1);
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int precision = 13;
    cout.precision(precision);
    cout.setf(ios_base::fixed);

    int T; scanf("%d", &T);
    int test = 1;
    while (T--) {
        printf( "Case %d:\n", test++);
        int n;
        int q;
        scanf("%d%d", &n, &q);
        bit<int> b(n+1);
        for (int i = 0; i < n; ++i) {
            int a; scanf("%d", &a);
            b.add(i+1, a);
        }

        while (q--) {
            int kase; scanf("%d", &kase);
            if (1 == kase) {
                int i; scanf("%d",&i); ++i;
                int tmp = b.rquery(i, i);
                b.add(i, -tmp);
                printf("%d\n", tmp);
            } else if (2 == kase) {
                int i, v; scanf("%d%d", &i, &v); ++i;
                b.add(i, v);
            } else if (3 == kase) {
                int i, j; scanf("%d%d", &i, &j); ++i; ++j;
                if (i > j) swap(i, j);
                printf("%d\n", b.rquery(i, j));
            } else {
                throw std::invalid_argument("shit");
            }
        }
    }

    return 0;
}
