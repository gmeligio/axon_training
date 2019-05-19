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


void solveQ(){
  int n; cin >> n;

  vector<vector<int>> poles(n, vector<int>(2));
  for(auto & p : poles) {
    cin >> p[0] >> p[1];
  }

  map<vector<int>, unordered_set<int>> unq;
  ll seen = 0;
  for(auto i = 0; i < n; ++i) {
    for(auto j = i + 1; j < n; ++j) {
      int x0 = poles[i][0], y0 = poles[i][1];
      int x1 = poles[j][0], y1 = poles[j][1];

      int a = y0 - y1;
      int b = x1 - x0;

      int div = __gcd(a, b);

      a /= div;
      b /= div;

      int c = (ll)a * x0 + (ll)b * y0;
      if(!unq.count({a, b}) or !unq[{a, b}].count(c)) {
        seen++;
        unq[{a, b}].insert(c);
      }  
    }
  }

  ll total = (seen * (seen - 1)) / 2;

  for(auto it : unq) {
    if(it.second.size() != 1) {
      int paraSz = it.second.size();
      total -= (paraSz * (paraSz - 1)) / 2;
    }
  }
  cout << total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(precision);
  cout.setf(ios_base::fixed);
  solveQ();
  return 0;
}
