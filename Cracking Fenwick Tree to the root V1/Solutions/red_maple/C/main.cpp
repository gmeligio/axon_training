
#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>  
#include <numeric>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define endl '\n'
using ll = long long;

const int precision = 16;
const int modulo =  1000000007; // 10^9 + 7
const ll lmodulo =  1000000007; // 10^9 + 7

const double EPS = 1e-9;

class BIT {
private:
    int n;
    vector<int> arr;

    int inner_sum(int ind) {
        int acc = 0;
        for(;ind >= 0; ind = (ind & (ind + 1)) - 1) {
            acc += arr[ind];
        }
        return acc;
    }

public:
    BIT(int n) {
        this->n = n;
        arr = vector<int>(n, 0);
    }

    void inc(int ind, int delta) {
        for(; ind < n; ind |= (ind + 1)) {
            arr[ind] += delta;
        } 
    }

    int sum(int l, int r) {
        return inner_sum(r) - inner_sum(l - 1);
    }

    int reset(int ind) {
        int cur = sum(ind, ind);
        inc(ind, -cur);
        return cur;
    }
};
void solveC(){
    int t; 
    scanf("%d", &t);

    for(auto tt = 1; tt <= t; ++tt) {
        int n, q; scanf("%d%d", &n, &q);

        printf("Case %d:\n", tt);

        BIT bit(n);
        for(auto i = 0; i < n; ++i) {
            int val; scanf("%d", &val);
            bit.inc(i, val);
        }

        while(q--) {
            int query; scanf("%d", &query);
            if(query == 1) {
                int ind; scanf("%d", &ind);
                printf("%d\n", bit.reset(ind));
            } else if(query == 2) {
                int ind, money;
                scanf("%d%d", &ind, &money);
                bit.inc(ind, money);
            } else {
                int l, r; 
                scanf("%d%d", &l, &r);
                printf("%d\n", bit.sum(l, r));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveC();
    return 0;
}