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


void solveJ(){
    int n, k; cin >> n >> k;

    unordered_map<int, pair<int, int>> interval;

    for(auto i = 1; i <= k; ++i) {
        int q; cin >> q;
        if(!interval.count(q)) {
            interval[q].first = i;
            interval[q].second = i;
        } else {
            interval[q].second = i;
        }
    } 

    ll acc = 0;

    for(int a = 1; a <= n; ++a) {
        if(!interval.count(a)) {
            acc++; 
        }

        for(int b : {a - 1, a + 1}){
            if(b < 1 or b > n) continue;
            if(!interval.count(b) or !interval.count(a)) {
                acc++;
            } else if(interval[a].first > interval[b].second) {
                acc++;
            } 
        }
    }

    cout << acc;
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
