//
// Created by Carlos on 5/1/2019.
// Email: cmpeguerog@gmail.com
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct Point {

    int x, y, rect, isLower;

    Point(){}
    Point(int nx, int ny, int nrect, int nIsLower):
            x(nx), y(ny), rect(nrect), isLower(nIsLower) {}

    void operator =(const Point& b) {
        x = b.x, y = b.y; rect = b.rect;
        isLower = b.isLower;
    }

    bool operator <(const Point& b) const {
        return ( x != b.x ? x < b.x :
                 (y != b.y ? y < b.y : isLower < b.isLower));
    }
};

vector<Point> plane, points;
vector<pair<Point, Point>> queries;
vector<int> results;
vector<int> fenwick;
unordered_map<int, int> xMapper, yMapper;
set<int> xSet, ySet;

int xIndex, yIndex;

int p, q;

int factor(int x) {
    return x & (-x);
}

void update(int index, int value) {
    index ++;
    for(; index <= yIndex ; index += factor(index)){
        fenwick[index] += value;
    }
}

int sum(int index) {
    int result = 0; index ++;
    for(; index > 0; index -= factor(index)) {
        result += fenwick[index];
    }
    return result;
}

int sum(int lower, int upper) {
    return sum(upper) - sum(lower - 1);
}

int main() {

//    freopen("test.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;

    scanf("%d", &t);
    for (int j = 0; j < t; ++ j) {
        scanf("%d %d", &p ,&q);

        results.resize(q);

        for(int i = 0, x, y; i < p; ++ i){
            scanf("%d %d", &x, &y);
            xSet.insert(x); ySet.insert(y);

            points.emplace_back(Point(x, y, -1, 0));
        }

        for(int i = 0, xLower, yLower, xUpper, yUpper; i < q; ++ i){
            scanf("%d %d %d %d", &xLower, &yLower, &xUpper, &yUpper);

            xSet.insert(xLower); xSet.insert(xUpper);
            ySet.insert(yLower); ySet.insert(yUpper);

            auto left = Point(xLower, yLower, i, -1);
            auto right = Point(xUpper, yUpper, i, 1);

            queries.emplace_back(make_pair(left,right));
        }

        xIndex = yIndex = 0;
        for(int x: xSet) {
            xMapper[x] = xIndex ++;
        }

        for(int y: ySet) {
            yMapper[y] = yIndex ++;
        }

        for(Point point: points) {
            int x = xMapper[point.x];
            int y = yMapper[point.y];

            plane.emplace_back(Point(x, y, point.rect, point.isLower));
        }

        for(pair<Point, Point> pair: queries) {
            int xLower = xMapper[pair.first.x];
            int yLower = yMapper[pair.first.y];

            plane.emplace_back(Point(xLower, yLower, pair.first.rect, pair.first.isLower));

            int xUpper = xMapper[pair.second.x];
            int yUpper = yMapper[pair.second.y];
            plane.emplace_back(Point(xUpper, yUpper, pair.second.rect, pair.second.isLower));
        }

        sort(plane.begin(), plane.end());

        fenwick.resize(yIndex + 2);
        for(Point point: plane) {
            if( point.isLower == 0 ) {
                update(point.y, 1);
            } else if ( point.isLower == -1 ) {
                int yUpper = yMapper[queries[point.rect].second.y];
                results[point.rect] = sum(point.y, yUpper);
            } else if ( point.isLower == 1 ) {
                int yLower = yMapper[queries[point.rect].first.y];
                results[point.rect] = sum(yLower, point.y) - results[point.rect];
            }
        }

        printf("Case %d:\n", j + 1);
        for(int result: results) {
            printf("%d\n", result);
        }

        points.clear();
        plane.clear();
        results.clear();
        queries.clear();
        fenwick.clear();
        xMapper.clear(); xSet.clear();
        yMapper.clear(); ySet.clear();
    }
}