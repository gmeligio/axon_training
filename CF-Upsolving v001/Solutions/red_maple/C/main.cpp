/*
    Date 05/13/2019
    Brenda E Ramirez.
*/

/*
    Statement:
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

void solveC(){
    int n, z; cin >> n >> z;
    vector<int> numbers(n);
    for(auto & i : numbers) cin >> i;

    sort(numbers.begin(), numbers.end());

    int pairs = 0;

    int mid = numbers.size() / 2;
    int l = 0, r = mid;

    while(l < mid and r < n) {
        if(numbers[r] - numbers[l] >= z) {
            pairs++;
            l++;
            r++;
        } else {
            r++;
        }
    }

    cout << pairs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveC();
    return 0;
}