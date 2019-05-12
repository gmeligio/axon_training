#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define endl '\n'

using namespace std;

class ft {
        vector<int> t;
    public:
        ft(int n){t.assign(n, 0);}
        void put(int x) {
            while (x < (int)t.size()) {
                ++t[x];
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

    int n; cin >> n;
    ft b(1e5+10);
    int mx = 0;
    //using a FT to count how many elements
    //in FT are below certain X
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b.put(x);
        mx = max(mx, x);
    }
    int q; cin >> q;
    while (q--) {
        int m; cin >> m;
        m = min(mx, m);
        cout << b.get(m) << endl;
    }

    return 0;
}
