#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

template <class Key, class Val>
using hmap = gp_hash_table<Key, Val>;


using query = pair<pair<int, int>, pair<int, int>>;

class event {
    public:
        pair<int, int> p1, p2;
        int id;
        int type;
        event(int x1, int y1, int x2, int y2, int id, int type) {
            p1 = {x1, y1};
            p2 = {x2, y2};
            this->id = id;
            this->type = type;
        }
};

class ft {
        vector<int> t;
    public:
        ft(int n) {t = vector<int>(n);}

        void add(int x, int v) {
            while (x < (int)t.size()) {
                t[x] += v;
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

        int rget(int x, int y) {
            return get(y) - get(x-1);
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int precision = 13;
    cout.precision(precision);
    cout.setf(ios_base::fixed);

    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        printf("Case %d:\n", kase);
        set<int> sty;
        hmap<int, int> my;

        int p, q; scanf("%d%d", &p, &q);
        vector<pair<int, int>> points(p);
        vector<event> ev;
        for (auto &i : points) {
            scanf("%d%d", &i.first, &i.second);
            ev.push_back(event(i.first, i.second, -1, -1, -1, 0));
            sty.insert(i.second);
        }

        vector<query> queries(q);
        int ind = 0;
        for (auto &i : queries) {
            scanf("%d%d%d%d", &i.first.first, &i.first.second, &i.second.first, &i.second.second);
            sty.insert(i.first.second);
            sty.insert(i.second.second);
            ev.emplace_back(i.first.first, i.first.second, i.first.first, i.second.second, ind, -1);
            ev.emplace_back(i.second.first, i.first.second, i.second.first, i.second.second, ind, 1);
            ++ind;
        }

        {
            int idy = 1;
            for (auto y : sty) {
                my[y] = idy++;
            }
        }

        vector<int> ans(q);

        sort(ev.begin(), ev.end(),
             [](event &e1, event &e2) -> bool {
                 int x1 = e1.p1.first;
                 int x2 = e2.p1.first;
                 if (x1 != x2) return x1 < x2;
                 return e1.type < e2.type;
             });
        ft b(my.size() + 2);
        for (auto e : ev) {
            //cout << " event (" << e.p1.first << ", " << e.p1.second << ") (" << e.p2.first << ", " << e.p2.second
            //     << ") type: " << e.type << " id: " << e.id << endl;
            if (e.type == 0) {
                b.add(my[e.p1.second], 1);
            } else if (e.type == -1) {
                ans[e.id] = -1 * b.rget(my[e.p1.second], my[e.p2.second]);
            } else {
                ans[e.id] += b.rget(my[e.p1.second], my[e.p2.second]);
            }
        }


        for (auto i : ans) printf("%d\n", i);

    }

    return 0;
}
