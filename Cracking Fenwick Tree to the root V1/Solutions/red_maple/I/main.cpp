
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

class BIT_2D{
private:
    int n;
    vector<vector<ll>> arr;

public:
    BIT_2D(int n) {
        this->n = n;
        arr = vector<vector<ll>>(n + 5, vector<ll>(n + 5, 0));
    }

    void update(int r, int c, int v) {
        ll cur = query(r, c, r, c);
        int delta = v - cur;
        for(; r < n;  r |= (r + 1)) {
            for(int cc = c; cc < n; cc |= (cc + 1)) {
                arr[r][cc] += delta;
            }
        }
    }

    ll query(int r, int c) {
        ll acc = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1) {
            for(int cc = c; cc >= 0; cc = (cc & (cc + 1)) - 1) {
                acc += arr[r][cc];
            }
        }
        return acc;
    }

    ll query(int r1, int c1, int r2, int c2) {
        ll ret = query(r2, c2);
        ll common = query(r1 - 1, c1 - 1);
        ll sect1 = query(r2, c1 - 1);
        ll sect2 = query(r1 - 1, c2);

        return ret - sect1 - sect2 + common;
    }

};
void solveI() {
    int t; cin >> t;

    while(t) {
        int n; cin >> n;
        BIT_2D bit(n);

        string com; cin >> com;
        while(com != "END") {
            if(com == "SET"){
                int r, c; cin >> r >> c;
                int v; cin >> v;
                bit.update(r, c, v);
            } else if(com == "SUM") {
                int r1, c1, r2, c2;
                cin >> r1 >> c1 >> r2 >> c2;

                cout << bit.query(r1, c1, r2, c2) <<endl;
            } 
            cin >> com;   
        }
        if(t != 1) cout <<endl;
        t--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveI();
    return 0;
}
