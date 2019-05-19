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


void solveW(){
   int n; cin >> n;
   int minVal = INT_MAX;

   for(auto i = 1; i <= n; ++i) {
        int in; cin >> in;
       
        int n1 = abs(i - 1);
        int n2 = abs(n - i);
        int v1 = n1 == 0 ? INT_MAX : in / n1;
        int v2 = n2 == 0 ? INT_MAX : in / n2;

        minVal = min(minVal, min(v1, v2));
   }

   cout << minVal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveW();
    return 0;
}


