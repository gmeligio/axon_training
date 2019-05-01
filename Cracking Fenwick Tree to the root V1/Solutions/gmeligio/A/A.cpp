#include <bits/stdc++.h>

using namespace std;

int main() {
  // freopen("a.in", "r", stdin);
  // freopen("a.out", "w", stdout);

  cin.sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  scanf("%d %d", &n, &q);

  const int maxn = 3e5 + 5;
  int notif[maxn] = {0};
  int allRead[maxn] = {0};
  int toRead = 0, ans = 0;
  vector<int> ev;

  for (; q--;) {
    int t, a;
    scanf("%d %d", &t, &a);

    switch (t) {
      case 1:
        ++notif[a];
        ++ans;
        ev.push_back(a);
        break;
      case 2:
        ans -= notif[a];
        notif[a] = 0;
        allRead[a] = ev.size();
        break;
      case 3:
        for (; toRead < a; ++toRead) {
          if (allRead[ev[toRead]] < toRead + 1) {
            --notif[ev[toRead]];
            --ans;
          }
        }
        break;
    }

    printf("%d\n", ans);
  }

  return 0;
}
