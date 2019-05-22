/*
    Date 05/13/2019
    Brenda E Ramirez.
*/

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


void solveH(){
    int n, h, m; cin >> n >> h >> m;

    vector<int> profit(n, h);

    for(auto i = 0; i < m; ++i) {
        int l, r, h;
        cin >> l >> r >> h;
        l--; r--;
        for(auto j = l; j <= r; ++j) {
            profit[j] = min(profit[j], h);
        }
    }

    ll acc = 0;
    for(auto it : profit) {
        acc += it * it;
    }

    cout << acc ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveH();
    return 0;
}