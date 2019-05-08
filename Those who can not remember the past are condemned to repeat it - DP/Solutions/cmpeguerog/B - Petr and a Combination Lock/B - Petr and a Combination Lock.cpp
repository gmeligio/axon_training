//
// Created by Carlos on 5/7/2019.
// Email: cmpeguerog@gmail.com
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MAX 16

int visited[(1 << MAX) - 1];
int degree[MAX], n;

void dfs(int level, int parent ,int node, int cost) {
    visited[node] = (visited[parent] + cost) % 360;

    if( level == n - 1 ) {
        return;
    }

    dfs(level + 1, node, (node << 1), degree[level + 1]);
    dfs(level + 1, node, (node << 1) + 1, 360 - degree[level + 1]);
}

int main() {

//    freopen("test.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; ++ i){
        cin >> degree[i];
    }

    dfs(-1, -1, 1, 0);

    bool sol = false;
    for(int i = (1 << n); i < (1 << (n + 1)); ++ i){
        if(visited[i] == 0) {
            sol = true;
            break;
        }
    }

    cout << (sol ? "YES\n" : "NO\n");
}