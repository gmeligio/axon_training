
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

void solveA(){
    int n, k; cin >> n >> k;
    vector<int> walks(n);
    for(auto &it: walks) {
        cin >> it;
    }

    vector<int> ans(n);
    ans[0] = walks[0];

    int acc = 0;
    for(auto i = 1; i < n; ++i) {
        ans[i] = max(walks[i], k - ans[i - 1]);
        acc += ans[i] == walks[i] ? 0 : ans[i] - walks[i];
    }

    cout << acc << endl;
    for(auto it : ans) {
        cout << it << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveA();
    return 0;
}