#include <stdio.h>
#include <string.h>

void bit_update(const int p, int v, int n, int *bit) {
  int i = p;
  for (; i <= n; i += (i & -i)) {
    bit[i] += v;
  }
}

int bit_prefix(int p, int n, int *bit) {
  int ans = 0;
  int i = p;
  for (; i >= 1; i -= (i & -i)) {
    ans += bit[i];
  }

  return ans;
}

int sum(int l, int h, int n, int *bit) {
  return bit_prefix(h, n, bit) - bit_prefix(l - 1, n, bit);
}

int main() {
  /*freopen("b.in", "r", stdin);*/
  /* freopen("b.out", "w", stdout);*/

  const int maxn = 2e5 + 5;
  int bit[maxn];

  int t = 1;
  int num[maxn];
  int n;
  for (scanf("%d\n", &n); n != 0; scanf("%d\n", &n), ++t) {
    memset(bit, 0, sizeof(int) * (n + 1));
    memset(num, 0, sizeof(int) * (n + 1));

    int i = 1;
    for (; i <= n; ++i) {
      scanf("%d\n", &num[i]);
      bit_update(i, num[i], n, bit);
    }

    char s[4];
    if (t > 1) {
      printf("\n");
    }
    printf("Case %d:\n", t);
    for (scanf("%s", s); s[0] != 'E'; scanf("%s", s)) {
      int a, b;
      scanf("%d %d\n", &a, &b);

      if (s[0] == 'S') {
        bit_update(a, b - num[a], n, bit);
        num[a] = b;
      } else {
        printf("%d\n", sum(a, b, n, bit));
      }
    }
  }

  return 0;
}
