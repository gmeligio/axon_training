//
// Created by Carlos on 5/7/2019.
// Email: cmpeguerog@gmail.com
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MAX 501

int values[MAX], dp[MAX], n, k;

int main() {

//    freopen("test.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for(int i = 0; i < n; ++ i){
        cin >> values[i];
    }

    dp[0] = values[0];

    for(int i = 1; i < n; ++ i) {
        dp[i] = min(max(0, k - (dp[i - 1] + values[i])) + values[i], max(0, k - (values[i - 1] + values[i])) + values[i]);
    }

    int sol = 0;
    for(int i = 0; i < n; ++ i){
        sol += dp[i] - values[i];
    }
    cout << sol << endl;

    for(int i = 0; i < n; ++ i){
        cout << dp[i] << (i != n - 1 ? " " : "\n");
    }
}