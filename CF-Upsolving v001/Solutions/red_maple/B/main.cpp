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

bool isOk( string  s) {
    if(s.size() <= 1) return true;
    if(s.size() == 2) {
        if(abs(s[0] - s[1]) == 1) return false;
        return true;
    }

    for(auto i = 1; i < (int) s.size() - 1; ++i) {
        if(abs(s[i - 1] - s[i]) == 1) return false;
        if(abs(s[i] - s[i + 1]) == 1) return false;
    }
    return true;
}

void solveB() {
    int t;
    cin >> t;

    while(t--) {
        string s; cin >> s;
        auto letters = vector<int>(26);
        for(auto c : s) {
            letters[c - 'a']++;
        }

        string retEven = "", retOdd = "";

        for(auto i = 0; i < (int)letters.size(); ++i) {
            if(i % 2) {
                retOdd += string(letters[i], (i + 'a'));
            } else {
                retEven += string(letters[i], (i + 'a'));
            }
        }
      
        if(isOk(retEven + retOdd)) {
            cout << (retEven + retOdd) << endl;
        } else if(isOk(retOdd + retEven)) {
            cout << (retOdd + retEven) << endl; 
        } else {
            cout << "No answer" << endl;
        }
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