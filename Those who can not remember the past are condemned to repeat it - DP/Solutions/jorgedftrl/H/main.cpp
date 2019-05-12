#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {

    int n, m, b, mod; cin >> n >> m >> b >> mod;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    //Observation: We can define a recurrence on the 3 imputs
    //             f(n, m, b) = f(n, m-1, b-a[n]) + f(n-1, m, b)
    //             but the implementation of this recurrence will fail due to
    //             memory constraints. Therefore, we need to get ride of one of the
    //             dimentions in the memoization proces. It could be proven that
    //             n is not required in memoization.
    //Complexity: O(N * M * B)
    auto dp = vector<vector<int>>(m+1, vector<int>(b+1));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = a[i]; k <= b; ++k) {
                dp[j][k] += dp[j-1][k-a[i]];
                dp[j][k] %= mod;
            }
        }
    }

    cout << accumulate(dp[m].begin(), dp[m].end(), 0,
                       [&](int a, int b) -> int {return (a+b)%mod;});

    return 0;
}
