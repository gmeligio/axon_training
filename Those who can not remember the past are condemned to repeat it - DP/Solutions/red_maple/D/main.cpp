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


void solveD(){
    int n; cin >> n;
    vector<int> vals(n);
    for(auto &it : vals) {
        cin >> it;
    }

    int l = 0, r = 0;
    int maxSize = 0, size = 0;
    map<int, int> seen;

    seen[vals[0]] = 0;

    while(r < vals.size()) {
        int M = seen.rbegin()->first;
        int m = seen.begin()->first;

        // cout << imie(m) << imie(M) << imie(l) << imie(r) << imie(maxSize)<<endl;
        // cout.flush();

        if(abs(vals[r] - m) <= 1 and abs(vals[r] - M) <= 1) {
            seen[vals[r]]++;
            r++;
            size++;
        } else {
            while(l < r and (abs(vals[r] - m) > 1 or abs(vals[r] - M) > 1)) {
                size--;
                seen[vals[l]]--;
                if(seen[vals[l]] == 0) seen.erase(vals[l]);
                l++;
                M = seen.rbegin()->first;
                m = seen.begin()->first;
            }
        }
        maxSize = max(maxSize, size);
    }

    cout << maxSize;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveD();
    return 0;
}