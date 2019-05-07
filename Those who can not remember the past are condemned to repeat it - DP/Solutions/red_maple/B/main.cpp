#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>  
#include <numeric>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define endl '\n'
using ll = long long;

const int precision = 16;
const int modulo =  1000000007; // 10^9 + 7
const ll lmodulo =  1000000007; // 10^9 + 7

const double EPS = 1e-9;


bool dfs(int ind, vector<int> & rot, int acc, int add) {
    if(ind >= rot.size()) {
        return ((acc % 360) == 0);
    }

    int toAdd = (acc + add * rot[ind]) % 360; 
    if(dfs(ind + 1, rot, toAdd, 1) or dfs(ind + 1, rot, toAdd, -1)) {
        return true;
    }

    return false;
}

void solveB(){
    int n; cin >> n;
    vector<int> rot(n);
    for(auto &it : rot) {
        cin >> it;
    }

    bool ans = dfs(0,rot, 0, 1) or dfs(0, rot, 0, -1);
    if(ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveB();
    return 0;
}
