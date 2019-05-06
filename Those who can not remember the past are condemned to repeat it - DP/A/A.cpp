#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int main() {
  // freopen("A.in", "r", stdin);
  // freopen("A.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<int> dp(n + 2);
  dp[0] = dp[n + 1] = k;
  int sol = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> dp[i];

    int add = max(k - dp[i] - dp[i - 1], 0);

    sol += add;
    dp[i] += add;
  }

  cout << sol << '\n';
  cout << dp[1];
  for (int i = 2; i <= n; ++i) {
    cout << ' ' << dp[i];
  }
  cout << '\n';

  return 0;
}
