#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

void ft_update(const int& p, const int& v, vector<int>& ft) {
  for (int i = p; i < ft.size(); i += (i & -i)) {
    ft[i] += v;
  }
}

int ft_prefix(const int& p, vector<int>& ft) {
  int ans = 0;
  for (int i = p; i >= 1; i -= (i & -i)) {
    ans += ft[i];
  }

  return ans;
}

int sum(const int& low, const int& high, vector<int>& ft) {
  return ft_prefix(high, ft) - ft_prefix(low - 1, ft);
}

class Query {
 public:
  int l, r, i;

  bool operator<(const Query& other) const { return r < other.r; }
};

int main() {
  // freopen("K.in", "r", stdin);
  // freopen("A.out", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  scanf("%d", &n);
  vector<int> number(n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &number[i]);
  }

  int q;
  scanf("%d", &q);
  vector<Query> query(q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d %d", &query[i].l, &query[i].r);
    query[i].i = i;
  }

  sort(query.begin(), query.end());

  unordered_map<int, int> mp;
  vector<int> ft(n + 1);

  for (int i = 0; i < n; ++i) {
    mp[number[i]] = -1;
  }

  int iQ = 0;
  vector<int> ans(q);
  for (int i = 0; i < n; ++i) {
    if (mp[number[i]] != -1) {
      ft_update(mp[number[i]], -1, ft);
    }

    ft_update(i + 1, 1, ft);
    mp[number[i]] = i + 1;

    for (; iQ < q && query[iQ].r == i + 1; ++iQ) {
      ans[query[iQ].i] = sum(query[iQ].l, query[iQ].r, ft);
    }
  }

  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
