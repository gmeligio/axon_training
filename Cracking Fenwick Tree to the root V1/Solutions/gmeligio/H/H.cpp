#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int main() {
  // freopen("H.in", "r", stdin);
  // freopen("A.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  scanf("%d", &t);
  for (; t--;) {
    int n;
    scanf("%d", &n);
    vector<int> number(n + 1);
    vector<int> previous(n + 1);
    vector<int> next(n + 1);

    next[0] = 1;
    previous[1] = n;
    next[1] = 2;
    previous[n] = n - 1;
    next[n] = 1;
    for (int i = 2; i < n; ++i) {
      previous[i] = i - 1;
      next[i] = i + 1;
    }

    int p = 0;
    for (int i = 1; i <= n; ++i) {
      int i1 = i + 1;
      for (int j = 1; j <= i1; ++j) {
        p = next[p];
      }

      number[p] = i;
      next[previous[p]] = next[p];
      previous[next[p]] = previous[p];
    }

    printf("%d", number[1]);
    for (int i = 2; i <= n; ++i) {
      printf(" %d", number[i]);
    }
    printf("\n");
  }

  return 0;
}
