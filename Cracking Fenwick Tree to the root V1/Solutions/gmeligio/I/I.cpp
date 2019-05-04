#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

void ft_update(int x, int y, int v, vector<vector<int>>& ft) {
  for (int i = y; i < ft.size(); i += (i & -i)) {
    for (int j = x; j < ft[i].size(); j += (j & -j)) {
      ft[i][j] += v;
    }
  }
}

int ft_prefix(int x, int y, vector<vector<int>>& ft) {
  int ans = 0;
  for (int i = y; i >= 1; i -= (i & -i)) {
    for (int j = x; j >= 1; j -= (j & -j)) {
      ans += ft[i][j];
    }
  }

  return ans;
}

int sum(int x1, int y1, int x2, int y2, vector<vector<int>>& ft) {
  return ft_prefix(x2, y2, ft) -
         (ft_prefix(x2, y1 - 1, ft) + ft_prefix(x1 - 1, y2, ft)) +
         ft_prefix(x1 - 1, y1 - 1, ft);
}

int main() {
  // freopen("I.in", "r", stdin);
  // freopen("I.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  scanf("%d", &t);
  for (; t--;) {
    int n;
    scanf("%d\n", &n);
    vector<vector<int>> ft(n + 1, vector<int>(n + 1)),
        num(n + 1, vector<int>(n + 1));

    char s[10];
    for (scanf("%s", s); s[0] != 'E'; scanf("%s", s)) {
      if (s[1] == 'E') {
        int x, y, v;
        scanf("%d%d%d\n", &x, &y, &v);
        ++x;
        ++y;
        ft_update(x, y, v - num[y][x], ft);
        num[y][x] = v;
      } else {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d\n", &x1, &y1, &x2, &y2);
        ++x1;
        ++y1;
        ++x2;
        ++y2;

        printf("%d\n", sum(x1, y1, x2, y2, ft));
      }
    }

    printf("\n");
  }

  return 0;
}
