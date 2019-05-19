/*
    Date 05/13/2019
    Brenda E Ramirez.
*/

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


void solveO(){
    int n; cin >> n;

    map<int, unordered_set<int>> seenBySize;
    unordered_map<int, int> byId;

    int maxSize = 1;

    for(auto i = 1; i <= n; ++i) {
        int c; cin >> c;
        if(!byId.count(c)) {
            byId[c] = 1;
            seenBySize[1].insert(c);
        } else {
            int size = byId[c];
            seenBySize[size].erase(c);
            if(seenBySize[size].size() == 0) seenBySize.erase(size);
            byId[c]++;
            seenBySize[size + 1].insert(c);
        }

        if(seenBySize.size() == 1) {
            if(seenBySize.begin()->second.size() == 1 or seenBySize.count(1))
                maxSize = i;
        } else if(seenBySize.size() == 2) {
            int z1 = seenBySize.begin()->first;
            int cnt1 = seenBySize.begin()->second.size();

            int z2 = seenBySize.rbegin()->first;
            int cnt2 = seenBySize.rbegin()->second.size();

            if((z2 - 1) == z1 and cnt2 == 1) {
                maxSize = i;
            } else if (cnt1 == 1 and z1 == 1) {
                maxSize = i;
            }
        }
    }

    cout << maxSize;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveO();
    return 0;
}


