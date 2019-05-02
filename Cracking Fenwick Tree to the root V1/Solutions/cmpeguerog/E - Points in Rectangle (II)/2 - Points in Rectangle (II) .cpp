//
// Created by Carlos on 5/1/2019.
// Email: cmpeguerog@gmail.com
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MAX 200010

struct Point {
    int x ,y;

    Point():x(0), y(0){}
    Point(int nx, int ny): x(nx), y(ny){}

    bool operator <(const Point& p) const {
        return (y != p.y ? y < p.y : x < p.x);
    }
};

class Fenwick {

public:

    Fenwick(int n) {
        this->n = n;
    }

    void build(const vector<Point> &points) {

        for(auto &point: points){
            for(int x = point.x + 1; x <= n; x += factor(x)){
                tree[x].emplace_back(point.y);
            }
        }
    }

    int sum(int x , int y) {
        int result  = 0;
        for(x ++; x > 0; x -= factor(x)) {
            auto it = upper_bound(tree[x].begin(), tree[x].end(), y) - tree[x].begin();

            result += it;
        }

        return result;
    }
private:

    static int factor(int x) {
        return x & (-x);
    }

    int n;
    vector<int> tree[MAX];
};

int main() {

    int t = 0, p, q;

    scanf("%d", &t);
    for (int j = 0; j < t; ++ j) {
        scanf("%d %d", &p ,&q);

        set<int> xSet;
        vector<Point> points, plane;
        vector<pair<Point, Point>> queries;

        unordered_map<int, int> xMapper;

        for(int i = 0, x, y; i < p; ++ i){
            scanf("%d %d", &x, &y);
            xSet.insert(x);
            points.emplace_back(Point(x, y));
        }

        for(int i = 0, xLower, yLower, xUpper, yUpper; i < q; ++ i){
            scanf("%d %d %d %d", &xLower, &yLower, &xUpper, &yUpper);

            xSet.insert(xLower); xSet.insert(xUpper);

            auto left = Point(xLower, yLower);
            auto right = Point(xUpper, yUpper);

            queries.emplace_back(make_pair(left,right));
        }

        int xIndex = 0;
        for(auto &x: xSet) {
            xMapper[x] = xIndex ++;
        }

        for(auto &point: points) {
            int x = xMapper[point.x];

            plane.emplace_back(Point(x, point.y));
        }

        sort(plane.begin(), plane.end());

        auto fenwick = new Fenwick(xIndex + 1);
        fenwick->build(plane);
        printf("Case %d:\n", j + 1);
        for(auto &query: queries) {
            auto pUpper = query.second;
            auto pLower = query.first;

            int sum = fenwick->sum(xMapper[pUpper.x], pUpper.y)   -
                    fenwick->sum(xMapper[pLower.x] - 1, pUpper.y) -
                    fenwick->sum(xMapper[pUpper.x], pLower.y - 1) +
                    fenwick->sum(xMapper[pLower.x] - 1, pLower.y - 1);

            printf("%d\n", sum);
        }
    }
}