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

bool check(vector<vector<int>> & m) {
    for(auto r = 0; r < (int)m.size(); ++r) {
        for(auto c = 1; c < (int)m[0].size(); ++c) {
            if(m[r][c - 1] >= m[r][c]) return false;
        }
    }

    for(auto c = 0; c < (int)m[0].size(); ++c) {
        for(auto r = 1; r < (int)m.size(); ++r) {
            if(m[r - 1][c] >= m[r][c]) return false;
        }
    }
    return true;
}

void solveI(){
    int n, m; cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m)), 
                        b(n, vector<int>(m));

    for(auto &r : a) {
        for(auto &c : r) {
            cin >> c;
        }
    }
    
    for(auto &r : b) {
        for(auto &c : r) {
            cin >> c;
        }
    }

    for(auto r = 0; r < n; ++r) {
        for(auto c = 0; c < m; ++c) {
            if(a[r][c] > b[r][c]) {
                swap(a[r][c], b[r][c]);
            }
        }
    }

    if(check(a) and check(b)) {
        cout << "Possible";
    } else {
        cout << "Impossible";
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
