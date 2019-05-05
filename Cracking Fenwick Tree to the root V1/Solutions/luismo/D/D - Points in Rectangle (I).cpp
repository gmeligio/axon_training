/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 1266 - Points in Rectangle (I)
    Online Judge: LightOJ
    Idea: Basic use of a Fenwick Tree 2D
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;
 
int tc, q, a, b, c, d, type;
 
// >> FENWICK TREE 2D
 
const int len = 1003;
int tree[len][len];
 
void buildFenwickTree2D()
{
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++)
            tree[i][j] = 0;
}
 
inline int lowBit(int i) {return i&-i;}
 
void update(int r, int c, int upd)
{
    for(int i = r; i < len; i += lowBit(i))
    {
        for(int j = c; j < len; j+= lowBit(j))
            tree[i][j]+= upd;
    }
}
 
int retrieve(int x, int y)
{
    int sum = 0;
    for(int i = x; i > 0; i-= lowBit(i))
    {
        for(int j = y; j > 0; j-= lowBit(j))
            sum+= tree[i][j];
    }
    return sum;
}
 
int rectangleSum(int x1, int y1, int x2, int y2)
{
    // x1 y1 coordinates of the lower-left corner
    // x2 y2 coordinates of the upper right corner
    int s1 = retrieve(x2, y2);
    int s2 = retrieve(x2, y1 - 1);
    int s3 = retrieve(x1 - 1, y2);
    int s4 = retrieve(x1 - 1, y1 - 1);
 
    return s1 - (s3 + s2) + s4;
}
 
// << FENWICK TREE 2D
 
 
void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        pf("Case %d:\n", cs);
 
        buildFenwickTree2D();
 
        sf("%d", &q);
        // reading queries
        while(q-- > 0)
        {
            sf("%d", &type);
 
            if(type == 0)
            {
                sf("%d%d", &a, &b);
                a++; b++;
                // find the sum
                int k = rectangleSum(a, b, a, b);
                // if that cell contains a cero
                if(k == 0)
                    update(a, b, 1);
            }
            else
            {
                sf("%d%d%d%d", &a, &b, &c, &d);
                a++; b++; c++; d++;
                // find the sum
                int answ = rectangleSum(a, b, c, d);
                // print the answer
                pf("%d\n", answ);
            }
        }
 
 
    }
 
}
 
void fastIO()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
}
 
void IO()
{
    if(fopen("d:\\lmo.in","r") != NULL)
    {
        freopen("d:\\lmo.in","r",stdin);
    }
    else if(fopen("/media/Beijing/lmo.in","r") != NULL)
    {
        freopen("/media/Beijing/lmo.in", "r", stdin);
    }
}
 
int main()
{
   
 
    solve();
}