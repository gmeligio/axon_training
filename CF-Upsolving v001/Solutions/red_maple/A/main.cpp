/*
    Date 05/12/2019
    Brenda E Ramirez.
*/

/*
    Statement:
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

void solveA() {
    int n; cin >> n;

    int pp = 0;
    int p = 0;

    ll ret = 0;
    while(n--) {
        int cur; cin >> cur;

        if(cur == p) {
            cout << "Infinite";
            return;
        }

        if(pp == 3 and p == 1 and cur == 2) {
            ret += 2;
        } else {
            int tp = p;
            int tcur = cur;
            if(tp > tcur) swap(tp, tcur);    

            if(tp == 2 and tcur == 3) {
                cout << "Infinite";
                return;
            } else if(tp == 1 and tcur == 2) {
                ret += 3;
            } else if(tp == 1 and tcur == 3) {
                ret += 4;
            }
        }

        pp = p;
        p = cur;
    }

    cout <<"Finite" << endl << ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveA();
    return 0;