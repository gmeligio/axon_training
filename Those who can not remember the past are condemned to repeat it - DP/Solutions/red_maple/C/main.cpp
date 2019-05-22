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


void solveC() {
    int n; cin >> n;
    
    vector<int> price(n);
    for(auto &it: price) {
        cin >> it;
    }

    int q; cin >> q;
    
    sort(price.begin(), price.end());

    while(q--) {
        int cur; cin >> cur;
        auto it = upper_bound(price.begin(), price.end(), cur);
        if(it != price.begin()) it--;
        else {
            cout << 0 << endl;
            continue;
        }

        cout << distance(price.begin(), it) + 1 << endl;
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