
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


class BIT{
private:
    int n, m;
    vector<unordered_map<int, int>> arr;
public:

    BIT(int n, int m) {
        this->n = n;
        this->m = m;
        arr = vector<unordered_map<int, int>>(n);
    }

    void update(int x, int y, int val) {
        for(; x < n; x |= (x + 1)) {
            for(int yy = y; yy < m; yy |= (yy + 1)) {
                if(arr[x].count(yy))
                    arr[x][yy] = min(arr[x][yy], val);
                else {
                    arr[x][yy] = val;
                }
            }
        }
    }

    int queryMin(int x, int y) {
        int minVal = INT_MAX;
        for(; x >= 0; x = (x & (x + 1)) - 1) {
            for(int yy = y; yy >= 0; yy = (yy & (yy + 1)) - 1) {
                if(arr[x].count(yy))
                    minVal = min(minVal, arr[x][yy]);
            }
        }   
        return minVal;
    }
};


void solveJ() {
    int n; cin >> n;

    vector<vector<int>> data(n, vector<int>(4, 0));

    vector<int> maxTh(4, INT_MIN);
    for(auto &v : data) {
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        for(auto i = 0; i < 4; ++i) {
            maxTh[i] = max(maxTh[i], v[i]);
        }
    }

    BIT bit(maxTh[1] + 5, maxTh[2] + 5);
    sort(data.begin(), data.end());

    int ans = 0;
    for(auto i = 0; i < (int)data.size(); ++i) {
        auto v = data[i];
        int minSeen = bit.queryMin(v[1], v[2]);
        if(minSeen > v[3]) {
            ans ++;
            bit.update(v[1], v[2], v[]);
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveJ();
    return 0;
}