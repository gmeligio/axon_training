//
// Created by Carlos on 5/7/2019.
// Email: cmpeguerog@gmail.com
//

#include <bits/stdc++.h>

using namespace std;

int n, q, m;
vector<int> stores;

int main() {

//    freopen("test.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x;
    for(cin >> n; n > 0; n --){
        cin >> x;
        stores.emplace_back(x);
    }

    sort(stores.begin(), stores.end());
    for(cin >> q; q > 0; -- q) {
        cin >> m;

        cout << upper_bound(stores.begin(), stores.end(), m) - stores.begin() << endl;
    }

    return 0;
}