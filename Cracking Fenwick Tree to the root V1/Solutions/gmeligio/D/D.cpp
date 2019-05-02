#include <bits/stdc++.h>

using namespace std;

void bit_update(int x, int y, int v, int n, vector<vector<int>> &bit) {
  for (int i = y; i <= n; i += (i & -i)) {
    for (int j = x; j <= n; j += (j & -j)) {
      bit[i][j] += v;
    }
  }
}

int bit_prefix(int x, int y, int n, vector<vector<int>> &bit) {
  int ans = 0;
  for (int i = y; i >= 1; i -= (i & -i)) {
    for (int j = x; j >= 1; j -= (j & -j)) {
      ans += bit[i][j];
    }
  }

  return ans;
}

int sum(int x1, int y1, int x2, int y2, int n, vector<vector<int>> &bit) {
  return bit_prefix(x2, y2, n, bit) - bit_prefix(x2, y1 - 1, n, bit) -
         bit_prefix(x1 - 1, y2, n, bit) + bit_prefix(x1 - 1, y1 - 1, n, bit);
}

int main() {
  freopen("D.in", "r", stdin);
  // freopen("a.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  // cin >> t;
  scanf("%d\n", &t);
  const int maxn = 1000 + 2;
  int n = 1001;
  for (int iT = 1; iT <= t; ++iT) {
    vector<vector<int>> bit(maxn, vector<int>(maxn));
    bool listed[maxn][maxn] = {false};

    int q;
    scanf("%d\n", &q);
    printf("Case %d:\n", iT);
    // cin >> q;
    // cout << "Case " << iT << ":\n";

    for (; q--;) {
      int type;
      // cin >> type;
      scanf("%d", &type);
      if (type == 0) {
        int x, y;
        // cin >> x >> y;
        scanf("%d %d", &x, &y);
        ++x;
        ++y;
        if (!listed[y][x]) {
          listed[y][x] = true;
          bit_update(x, y, 1, n, bit);
        }
      } else {
        int x1, y1, x2, y2;
        // cin >> x1 >> y1 >> x2 >> y2;
        // cout << sum(x1 + 1, y1 + 1, x2 + 1, y2 + 1, n, bit) << '\n';
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", sum(x1 + 1, y1 + 1, x2 + 1, y2 + 1, n, bit));
      }
    }
  }

  return 0;
}
