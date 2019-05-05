#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

template <class Key, class Val>
using hmap = gp_hash_table<Key, Val>;


class ft2 {
        vector<hmap<int, int>> t;
    public:
        ft2(int n) {t.assign(n, {});}

        void put(int y, int zz, int w) {
            while (y < (int)t.size()) {
                int z = zz;
                while (z < (int)t.size()) {
                    if (t[y][z] == 0) t[y][z] = t.size() + 1;
                    t[y][z] = min(w, t[y][z]);
                    z += z & -z;
                }
                y += y & -y;
            }
        }

        int get(int y, int zz) {
            int ret = t.size() + 1;
            while (y) {
                int z = zz;
                while (z) {
                    if (t[y][z] == 0) t[y][z] = t.size() + 1;
                    ret = min(ret, t[y][z]);
                    z -= z & -z;
                }
                y -= y & -y;
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

    int n; cin >> n;
    vector<tuple<int, int, int, int>> a(n);
    for (auto &v : a) {
        int x, y, z, w; cin >> x >> y >> z >> w;
        v = tuple<int, int, int, int>{x, y, z, w};
    };

    sort(a.begin(), a.end());

    int ans = 0;

    ft2 b(n+1);
    for (auto v : a) {
        int x, y, z, w;
        tie (x, y, z, w) = v;
        int mi = b.get(y, z);
        if (w < mi) {
            ++ans;
            b.put(y, z, w);
        }
    }
    cout << ans;

    return 0;
}
