#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

template <class T>
using hmap = gp_hash_table<int, T>;

class ft {
        vector<int> t;
    public:
        ft(int n) {t = vector<int>(n);}

        void set(int x, int val) {
            while (x < (int)t.size()) {
                t[x] += val;
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

    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int q; cin >> q;
    vector<pair<int, int>> queries(q);
    for (auto &p : queries) cin >> p.first >> p.second;

    vector<int> indi(q);
    iota(indi.begin(), indi.end(), 0);
    sort(indi.begin(), indi.end(),
         [&](int i, int j) -> bool {
             auto p1 = queries[i];
             auto p2 = queries[j];
             if (p1.first != p2.first) return p1.first < p2.first;
             return p1.second < p2.second;
         });

    ft b(n+2);
    hmap<deque<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]].push_back(i);
        if (1 == mp[a[i]].size()) {
            b.set(i+1, 1);
            //cout << " putting " << i+1 << " for " << a[i] << endl;
        }
    }

    vector<int> ans(q);
    int lo = 1;
    for (auto ind : indi) {
        auto p = queries[ind];
        int i = p.first;
        int j = p.second;
        //cout << " quering from " << i << " to " << j << endl;
        while (lo < i) {
            int v = a[lo-1];
            int k = mp[v].front(); mp[v].pop_front();
            //cout << " removing " << k+1 << " for " << v << endl;
            b.set(k+1, -1);
            if (mp[v].size()) {
                k = mp[v].front();
                b.set(k+1, 1);
                //cout << " putting " << k+1 << " for " << v << endl;
            }
            ++lo;
        }
        ans[ind] = b.get(j);
    }

    for (auto v : ans) cout << v << endl;

    return 0;
}
