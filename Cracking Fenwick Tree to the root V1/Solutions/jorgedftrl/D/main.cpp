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
        Bit2D(int n = 1009, int m = 1009) {
            t = vector<vector<int>>(n, vector<int>(m, 0));
        }

        void add(int x, int yy, T v) {
            while (x < (int)t.size()) {
                int y = yy;
                while (y < t[x].size()) {
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

void print(Bit2D<int> &b) {
    for (int x = 1; x <= 10; ++x) {
        for (int y = 1; y <= 10; ++y) {
            printf("%d ", b.get(x, y));
        }
        printf("\n");
    }
    printf("\n");

    for (int x = 1; x <= 10; ++x) {
        for (int y = 1; y <= 10; ++y) {
            printf("%d ", b.rget(x, y, x, y));
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int precision = 13;
    cout.precision(precision);
    cout.setf(ios_base::fixed);

    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case %d:\n", kase);

        Bit2D<int> b;
        //print(b);
        int q; scanf("%d", &q);
        while (q--) {
            int t; scanf("%d", &t);
            if (0 == t) {
                int x, y; scanf("%d%d", &x, &y);
                ++x; ++y;
                int v = b.rget(x, y, x, y);
                if (0 == v) {
                    b.add(x, y, 1);
                }

                //print(b);
            } else {
                int x1, x2, y1, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                ++x1; ++x2; ++y1; ++y2;
                printf("%d\n", b.rget(x1, y1, x2, y2));
            }
        }
    }

    return 0;
}
