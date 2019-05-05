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


class BIT{
private:
    int n;
    vector<int> arr;
public:

    BIT(int n){
        this->n = n;
        arr = vector<int>(n, 0);
    }

    void update(int i, int delta) {
        for(; i < n; i |= (i + 1)) {
            arr[i] += delta;
        }
    }

    int query(int i) {
        int acc = 0;
        for(; i >= 0;  i = (i & (i + 1)) - 1) {
            acc += arr[i];
        }
        return acc;
    }

    void print() {
        for(auto it : arr) {
            cout << it << " ";
        }
        cout <<endl;
    }
};

void solveK(){
    int n; cin >> n;
    vector<int> numbers(n);
    unordered_map<int, queue<int>> occurs;

    BIT bit(n + 5);

    for(auto i = 0; i < (int)numbers.size(); ++i){
        int num; cin >> num;
        numbers[i] = num;
        if(!occurs.count(num)){
            bit.update(i, 1);
        }
        occurs[num].push(i);
    }

    int m; cin >> m;
    vector<vector<int>> queries(m, vector<int>(3, 0));
    for(auto i = 0; i < m; ++i) {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][0]--;
        queries[i][1]--;
        queries[i][2] = i;
    }

    sort(queries.begin(), queries.end());

    vector<int> ansForQueries(m);

    int last = 0;
    for(auto q : queries) {
        int l = q[0];
        int r = q[1];
        int qInd = q[2];

        for(auto i = last; i < l; ++i){
            int num = numbers[i];

            auto dInd = occurs[num].front();
            occurs[num].pop();
            bit.update(dInd, -1);

            if(!occurs[num].empty()) {
                bit.update(occurs[num].front(), 1);
            }
        }

        last = l;
        ansForQueries[qInd] = bit.query(r);
    }

    for(auto it : ansForQueries) {
        cout << it <<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveK();
    return 0;
}

