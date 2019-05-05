#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class Key>
class Fenwick2d {
public:

    explicit Fenwick2d(int upper) {
        this->upper = upper;
    }

    void update(int x, int y, int value) {
        for(x ++; x <= upper; x += factor(x)) {
            for(int j = y + 1; j <= upper; j += factor(j)) {
                tree[merge(x, j)] += value;
            }
        }
    }

    int sum(int x, int y) {
        int result = 0;

        for(x ++; x > 0; x -= factor(x)){
            for(int j = y + 1; j > 0; j -= factor(j)) {
                auto it = tree.find(merge(x, j));
                if(it != tree.end()) {
                    result += it->second;
                }
            }
        }

        return result;
    }
private:
    int upper;
    unordered_map<Key, int> tree;

    Key merge(int x, int y) {
        return (((Key) x) << 32LL) ^ y;
    }

    int factor(int x) {
        return x & (-x);
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto fenwick = new Fenwick2d<long long>(10000);

    fenwick->update(2, 3, 12);
    fenwick->update(224, 24, 13);
    fenwick->update(1, 8, 1);

    cout << fenwick->sum(1, 1) << endl;
    cout << fenwick->sum(2, 3) << endl;
    cout << fenwick->sum(1, 8) << endl;
    cout << fenwick->sum(1000, 1000) << endl;
}