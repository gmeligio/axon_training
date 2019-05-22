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

//  recurrence equation f(n, b, m) = f(n - 1, b, m) + f(n, b - bn, m - 1);

// -----------------------------------------------
//                       MLE (Recursion + memoization)
// int rec(int m, int p, int b, vector<int> & bugs, int mod, 
//     vector<vector<vector<int>>> & memo) {
//     if(p < 0) {
//         if(m == 0 and b == 0) return 1;
//         return 0;
//     }

//     if(m <= 0) {
//         if(b >= 0) return 1;
//         return 0;
//     }

//     if(memo[m][p][b] != -1) return memo[m][p][b];

//     int &acc = memo[m][p][b];
//     acc = rec(m, p - 1, b, bugs, mod, memo);


//     if(b - bugs[p] >= 0) {
//         acc += rec(m - 1, p, b - bugs[p], bugs, mod, memo);
//         acc %= mod;
//     }
    
//     return acc;

// }

// void solveH(){
//     int n, m, b, mod;
//     cin >> n >> m >> b >> mod;

//     vector<int> bugs(n);
//     for(auto & it : bugs) {
//         cin >> it;
//     }

//     auto memo = vector<vector<vector<int>>>
//                 (m + 5, vector<vector<int>>(bugs.size() + 5, vector<int>(b + 5, -1)));

//     int ret = rec(m, bugs.size() - 1, b, bugs, mod, memo);
//     cout << ret ;
// }

// -----------------------------------------------
//                MLE (dp + full states)
// void solveH(){
//     int n, m, b, mod;
//     cin >> n >> m >> b >> mod;

//     vector<int> bugs(n);
//     for(auto & it : bugs) {
//         cin >> it;
//     }

//     auto memo = vector<vector<vector<int>>>
//                  (m + 5, vector<vector<int>>(bugs.size() + 5, vector<int>(b + 5, 0)));

//     int ret = 0;
//     memo[0][0][0] = 1;

//     for(auto pp = 1; pp <= n; ++pp) {
//         auto bug = bugs[pp - 1];
//         for(auto lines = 0; lines <= m; ++lines) {    
//             for(int bb = b; bb >= 0; --bb) {
//                 memo[lines][pp][bb] = memo[lines][pp - 1][bb];
//             }
//         }

//         for(auto lines = 1; lines <= m; ++lines) {    
//             for(int bb = b; bb >= bug; --bb) {
//                 memo[lines][pp][bb] += memo[lines - 1][pp][bb - bug];

//                 cout << "dp["<< lines <<"][" << pp << "][" << bb << "] = ";
//                 cout <<  memo[lines][pp][bb] <<" from ";
//                 cout << "dp["<< (lines - 1) <<"][" << pp << "][" << (bb) << "]";
//                 cout << " = " << memo[lines - 1][pp][bb - bug] << endl;
//             }
//         }
//         cout << endl;
//     }

//     for(auto bb = 0; bb <= b; ++bb) {
//         ret += memo[m][n][bb];
//     }
//     cout << ret ;
// }


// -----------------------------------------------
//                    AC
void solveH(){
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;

    vector<int> bugs(n);
    for(auto & it : bugs) {
        cin >> it;
    }

    auto memo = vector<vector<vector<int>>>
                 (m + 5, vector<vector<int>>(2, vector<int>(b + 5, 0)));


    int ret = 0;
    memo[0][0][0] = 1;

    for(auto pp = 1; pp <= n; ++pp) {
        auto bug = bugs[pp - 1];
        for(auto lines = 0; lines <= m; ++lines) {    
            for(int bb = b; bb >= 0; --bb) {
                memo[lines][pp % 2][bb] = memo[lines][(pp + 1) % 2][bb];
            }
        }

        for(auto lines = 1; lines <= m; ++lines) {    
            for(int bb = b; bb >= bug; --bb) {
                memo[lines][pp % 2][bb] += memo[lines - 1][pp % 2][bb - bug];
                memo[lines][pp % 2][bb] %= mod;
            }
        }
    }

    for(auto bb = 0; bb <= b; ++bb) {
        ret += memo[m][n % 2][bb];
        ret %= mod;
    }
    cout << ret ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveH();
    return 0;
}
