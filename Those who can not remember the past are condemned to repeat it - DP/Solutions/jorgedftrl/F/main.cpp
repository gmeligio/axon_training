#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl '\n'

using ull = unsigned long int;
using ll = long long;

template <class Key, class Val>
using hmap = gp_hash_table<Key, Val>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int precision = 13;
    cout.precision(precision);
    cout.setf(ios_base::fixed);

    int n, s; cin >> n >> s;

    using typ = tuple<int, int>;
    queue<typ> q;
    vector<vector<bool>> seen(s+1, vector<bool>(n+1, false));
    vector<vector<typ>> prev(s+1, vector<typ>(n+1, typ{-1, -1}));
    vector<vector<char>> ch(s+1, vector<char>(n+1, '#'));

    for (int i = 1; i < 10 and i <= s; ++i) {
        q.push(typ{i, i%n});
        seen[i][i%n] = true;
        ch[i][i%n] = '0' + i;
    }

    //Observation: - We only need to cover all the possible {sum, remainders}
    //             pairs to conlude if it possible or not to obtain a multiple
    //             that sum S. This give us an initial idea of what we need to memoize.
    //             - Since we require to obtain the minimun possible value, we can try to
    //             search a solution in such a way that the first solution found is also
    //             the minimun one.
    //Solution: By using BFS and iterating over digits in increasing order we can achieve the second
    //          observation and find a valid solution if exist.
    //Complexity: O(S * N)
    typ ans{-1, -1};
    while (q.size()) {
        auto t = q.front(); q.pop();
        int sum, rem;
        tie(sum, rem) = t;

        if (sum == s and rem == 0) {
            ans = t;
            break;
        }

        for (int d = 0; d < 10 and d <= s; ++d) {
            if ( sum + d <= s) {
                auto tup = typ{sum+d, (rem*10 + d) % n};
                int x, y;
                tie(x, y) = tup;

                if (!seen[x][y]) {
                    seen[x][y] = true;
                    prev[x][y] = t;
                    ch[x][y] = '0' + d;
                    q.push(tup);
                }
            }
        }
    }

    if (-1 == get<0>(ans)) {
        cout << -1;
    } else {
        string s;
        int x, y;
        tie(x, y) = ans;
        while (y != -1) {
            s.push_back(ch[x][y]);
            ans = prev[x][y];
            tie(x, y) = ans;
        }
        reverse(s.begin(), s.end());
        cout << s;
    }

    return 0;
}
