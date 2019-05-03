#include <bits/stdc++.h>

using namespace std;

void ft_update(int x, int y, int ny, vector<vector<int>> &ft) {
  for (int i = y; i <= ny; i += (i & -i)) {
    ft[i].push_back(x);
  }
}

int ft_prefix(int x, int y, vector<vector<int>> &ft) {
  int ans = 0;
  for (int i = y; i >= 1; i -= (i & -i)) {
    int n = upper_bound(ft[i].begin(), ft[i].end(), x) - ft[i].begin();
    ans += n;
  }

  return ans;
}

int sum(int x1, int y1, int x2, int y2, vector<vector<int>> &ft) {
  return ft_prefix(x2, y2, ft) - ft_prefix(x2, y1 - 1, ft) -
         ft_prefix(x1 - 1, y2, ft) + ft_prefix(x1 - 1, y1 - 1, ft);
}

int main() {
  // freopen("E.in", "r", stdin);
  // freopen("E.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  scanf("%d", &t);
  for (int iT = 1; iT <= t; ++iT) {
    map<int, int> ys;
    vector<pair<int, int>> pt;
    int p, q;
    scanf("%d %d", &p, &q);

    for (int i = 1; i <= p; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      ++x;
      ++y;

      pt.emplace_back(x, y);

      ys[y] = 0;
    }

    vector<vector<int>> query;
    for (int i = 0; i < q; ++i) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      ++x1;
      ++y1;
      ++x2;
      ++y2;

      query.emplace_back(vector<int>{x1, y1, x2, y2});

      ys[y1] = 0;
      ys[y2] = 0;
    }

    int yys = 0;
    for (map<int, int>::iterator it = ys.begin(); it != ys.end(); ++it) {
      it->second = ++yys;
    }

    vector<vector<int>> ft(yys + 1);

    // printf("ys\n");
    // for (map<int, int>::iterator it = ys.begin(); it != ys.end(); ++it) {
    //   printf("%d: %d\n", it->first, it->second);
    // }

    sort(pt.begin(), pt.end());
    for (int i = 0; i < pt.size(); ++i) {
      int x1 = pt[i].first;
      int y1 = ys[pt[i].second];

      // printf("point %d;%d\n", x1, y1);
      ft_update(x1, y1, yys, ft);
    }

    printf("Case %d:\n", iT);
    for (int i = 0; i < q; ++i) {
      int nx1 = query[i][0];
      int ny1 = ys[query[i][1]];
      int nx2 = query[i][2];
      int ny2 = ys[query[i][3]];

      // printf("%d,%d ; %d,%d\n", nx1, ny1, nx2, ny2);
      printf("%d\n", sum(nx1, ny1, nx2, ny2, ft));
    }
  }

  return 0;
}
