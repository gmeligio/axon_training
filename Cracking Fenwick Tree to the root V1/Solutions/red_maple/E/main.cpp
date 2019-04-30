
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


class BIT {
private:
    int n;
    vector<int> arr;
public:
    BIT(int n) {
        this->n = n;
        arr = vector<int>(n, 0);
    }

    void add(int y){
        for(; y < n; y |= (y + 1)) {
            arr[y]++;
        }
    }

    int query(int y) {
        int acc = 0;
        for(;y >= 0; y = (y & (y + 1)) - 1) {
            acc += arr[y];
        }
        return acc;
    }

    int rquery(int l, int r) {
        return query(r) - query(l - 1);
    }

    int getAcc() {
        return query(n);
    }
};

void solveE(){
    int t; scanf("%d", &t);

    for(auto tt = 1; tt <= t; ++tt) {
        printf("Case %d:\n", tt);

        int p, q; scanf("%d%d", &p, &q);

        vector<pair<int, int>> points(p);
        vector<vector<int>> queries(q, vector<int>(4, 0));

        set<int> xCoords, yCoords;
        for(auto &it: points) {
            scanf("%d%d", &it.first, &it.second);
            xCoords.insert(it.first);
            yCoords.insert(it.second);
        }

        for(auto &it:queries) {
            scanf("%d%d%d%d", &it[0], &it[1], 
                              &it[2], &it[3]);
            xCoords.insert(it[0]);
            xCoords.insert(it[2]);

            yCoords.insert(it[1]);
            yCoords.insert(it[3]);
        }

        unordered_map<int, int> xMap, yMap;
        {
            int i = 0;
            for(auto it : xCoords) {
                xMap[it] = i++;
            }
            i = 0;
            for(auto it : yCoords) {
                yMap[it] = i++; 
            } 

        }
        
        vector<vector<int>> sPoints;
        for(auto &it: points) {
            sPoints.push_back({xMap[it.first], 0, yMap[it.second], 0});
        }

        for(auto qq = 0; qq < (int)queries.size(); ++ qq) {
            auto it = queries[qq];
            int x1 = xMap[it[0]];
            int y1 = yMap[it[1]];
            int x2 = xMap[it[2]];
            int y2 = yMap[it[3]];

            sPoints.push_back({x1, -1, y1, qq}); // open
            sPoints.push_back({x2, 1, y2, qq}); // close
            
        }

        sort(sPoints.begin(), sPoints.end());

        BIT bit(yMap.size() + 5);
        vector<int> qDelta(q, 0);

        for(auto p = 0; p < (int)sPoints.size(); ++p) {
            auto cur = sPoints[p];

            if(cur[1] == 0) { // is a point
                bit.add(cur[2]); // y
            } if(cur[1] == 1) { // is closing

                auto qInd = cur[3];
                auto rect = queries[qInd];
                qDelta[qInd] = bit.rquery(yMap[rect[1]], yMap[rect[3]]) - qDelta[qInd];

            } else if(cur[1] == -1) { // isOpening
                auto qInd = cur[3];
                auto rect = queries[qInd];
                qDelta[qInd] = bit.rquery(yMap[rect[1]], yMap[rect[3]]);
            }
        }

        for(auto qq = 0; qq < (int)queries.size(); ++ qq) {
            printf("%d\n", qDelta[qq]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveE();
    return 0;
}