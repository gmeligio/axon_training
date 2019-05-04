//
// Created by Carlos on 5/4/2019.
// Email: cmpeguerog@gmail.com
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

class Fenwick {
public:

    int n;

    explicit Fenwick(int n) {
        this->n = n;
        tree = vector<int>(static_cast<unsigned int>(n + 1));
    }

    void update(int index, int value){
        for(index ++; index <= n; index += factor(index)) {
            tree[index] += value;
        }
    }

    int sum(int index) {
        int result = 0;
        for(index ++; index > 0; index -= factor(index)) {
            result += tree[index];
        }

        return result;
    }

    int sum(int lower, int upper) {
        return sum(upper) - sum(lower - 1);
    }

    int zeros(int lower, int upper) {
        return (upper - lower + 1) - sum(lower, upper);
    }

private:
    vector<int> tree;

    int factor(int x) {
        return x & (-x);
    }
};

int find(Fenwick *fenwick, int k, int index) {

    int lower = 0, upper = fenwick->n - 1, l = 0;

    if(fenwick->zeros(index + 1, upper) >= k) {
        lower = index + 1;
        l = index + 1;
    } else {
        k -= fenwick->zeros(index + 1, upper);
    }

    int amount = fenwick->zeros(lower, upper);
    k = (k % amount ? k % amount : amount);

    while (lower != upper) {
        int middle = (lower + upper) >> 1;

        if( fenwick->zeros(l, middle) >= k ){
            upper = middle;
        } else {
            lower = middle + 1;
        }
    }

    return lower;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;

    cin >> t;

    for(int i = 0, n; i < t; ++ i){
        cin >> n;

        auto fenwick = new Fenwick(n);

        auto position = vector<int>(static_cast<unsigned int>(n + 1));
        auto sol = vector<int>(static_cast<unsigned int>(n + 1));
        position[0] = -1;
        for(int j = 1; j <= n; ++ j){
            int index = find(fenwick, j + 1, position[j - 1]);
            fenwick->update(index, 1);
            position[j] = index;
            sol[index] = j;
        }

        for(int j = 0; j < sol.size() - 1; ++ j) {
            cout << sol[j] << (j < sol.size() - 2 ? " " : "\n" );
        }
    }
}