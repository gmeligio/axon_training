#include <bits/stdc++.h>

using namespace std;

void bit_update(int x, int y, int v, int nx, int ny, vector<vector<int>> &bit) {
  for (int i = y; i <= ny; i += (i & -i)) {
    for (int j = x; j <= nx; j += (j & -j)) {
      bit[i][j] += v;
    }
  }
}

int bit_prefix(int x, int y, vector<vector<int>> &bit) {
  int ans = 0;
  for (int i = y; i >= 1; i -= (i & -i)) {
    for (int j = x; j >= 1; j -= (j & -j)) {
      ans += bit[i][j];
    }
  }

  return ans;
}

int sum(int x1, int y1, int x2, int y2, vector<vector<int>> &bit) {
  return bit_prefix(x2, y2, bit) - bit_prefix(x2, y1 - 1, bit) -
         bit_prefix(x1 - 1, y2, bit) + bit_prefix(x1 - 1, y1 - 1, bit);
}

int main() {
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  scanf("%d", &t);
  // const int maxn = 5e5 + 1;
  for (int iT = 1; iT <= t; ++iT) {
    map<int, int> xs;
    map<int, int> ys;
    vector<pair<int, int>> pt;
    int p, q;
    scanf("%d %d", &p, &q);

    for (int i = 1; i <= p; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      ++x;
      ++y;

      pt.push_back(make_pair(x, y));

      xs[x] = 0;
      ys[y] = 0;
    }

    map<int, int>::iterator it = xs.begin(), itLast = xs.begin();
    int nx = 1;
    if (it->first > 1) {
      xs[1] = nx;
      ++nx;
    }

    it->second = nx;
    ++nx;
    ++it;
    for (; it != xs.end(); ++it, ++nx) {
      if (it->first - itLast->first > 1) {
        xs[itLast->first + 1] = nx;
        ++nx;
      }

      it->second = nx;

      itLast = it;
    }
    xs[itLast->first + 1] = nx;

    it = ys.begin();
    itLast = ys.begin();
    int ny = 1;
    if (it->first > 1) {
      ys[1] = ny;
      ++ny;
    }

    it->second = ny;
    ++ny;
    ++it;
    for (; it != ys.end(); ++it, ++ny) {
      if (it->first - itLast->first > 1) {
        ys[itLast->first + 1] = ny;
        ++ny;
      }

      it->second = ny;

      itLast = it;
    }
    ys[itLast->first + 1] = ny;

    vector<vector<int>> bit(ny + 1, vector<int>(nx + 1));

    // printf("xs\n");
    // for (map<int, int>::iterator mit = xs.begin(); mit != xs.end(); ++mit) {
    //   printf("%d: %d\n", mit->first, mit->second);
    // }

    // printf("ys\n");
    // for (map<int, int>::iterator mit = ys.begin(); mit != ys.end(); ++mit) {
    //   printf("%d: %d\n", mit->first, mit->second);
    // }

    for (int i = 0; i < pt.size(); ++i) {
      bit_update(xs[pt[i].first], ys[pt[i].second], 1, nx, ny, bit);
    }

    printf("Case %d:\n", iT);
    while (q--) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      ++x1;
      ++y1;
      ++x2;
      ++y2;

      map<int, int>::iterator ix1 = xs.upper_bound(x1),
                              iy1 = ys.upper_bound(y1),
                              ix2 = xs.upper_bound(x2),
                              iy2 = ys.upper_bound(y2);

      int nx1 = ix1 == xs.end() ? nx : ix1->second - 1;
      int ny1 = iy1 == ys.end() ? ny : iy1->second - 1;
      int nx2 = ix2 == xs.end() ? nx : ix2->second - 1;
      int ny2 = iy2 == ys.end() ? ny : iy2->second - 1;

      // printf("%d: %d, %d: %d, %d: %d, %d: %d\n", x1, nx1, y1, ny1, x2, nx2,
      // y2, ny2);
      printf("%d\n", sum(nx1, ny1, nx2, ny2, bit));
    }
  }

  return 0;
}
