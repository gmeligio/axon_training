#include <bits/stdc++.h>

using namespace std;

void bit_update(int p, int v, int n, int *bit) {
  for (int i = p; i <= n; i += (i & -i)) {
    bit[i] += v;
  }
}

int bit_prefix(int p, int n, int *bit) {
  int ans = 0;
  for (int i = p; i >= 1; i -= (i & -i)) {
    ans += bit[i];
  }

  return ans;
}

int sum(int l, int h, int n, int *bit) {
  return bit_prefix(h, n, bit) - bit_prefix(l - 1, n, bit);
}

int main() {
  // freopen("c.in", "r", stdin);
  // freopen("a.out", "w", stdout);

  cin.sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  scanf("%d", &t);
  const int maxn = 1e5 + 1;
  for (int iT = 1; iT <= t; ++iT) {
    int n, q;
    int mon[maxn];
    int bit[maxn] = {0};

    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; ++i) {
      scanf("%d", &mon[i]);
      bit_update(i, mon[i], n, bit);
    }

    printf("Case %d:\n", iT);
    for (; q--;) {
      int type, a, b;
      scanf("%d", &type);

      switch (type) {
        case 1:
          scanf("%d", &a);
          ++a;
          printf("%d\n", mon[a]);
          if (mon[a] > 0) {
            bit_update(a, -mon[a], n, bit);
            mon[a] = 0;
          }
          break;
        case 2:
          scanf("%d %d", &a, &b);
          ++a;
          bit_update(a, b, n, bit);
          mon[a] += b;
          break;
        default:
          scanf("%d %d", &a, &b);
          printf("%d\n", sum(a + 1, b + 1, n, bit));
          break;
      }
    }
  }

  return 0;
}
