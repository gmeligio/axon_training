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


void solveN(){
    int n, m;
    cin >> n >> m;

    if(m <= 1) {
        cout << 1;
        return;
    }
    
    if((n / 2) >= m) {
        cout << m;
    } else {
        cout << n - m;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveN();
    return 0;
}

