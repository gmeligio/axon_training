/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge:
	Idea:
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

int tc;
int n, q, type, x, y;
int arr[lim];


// >> FENWICK TREE
int t[lim];

inline int lowBit(int i) {return i&-i;}

void build()
{
    for(int i = 0; i < lim; i++)
        t[i] = 0;
}

void update(int idx, int upd)
{
    for(int i = idx; i < lim; i+= lowBit(i))
        t[i] += upd;
}

int retrieve(int idx)
{
    int sum = 0;
    for(int i = idx; i > 0; i-= lowBit(i))
        sum += t[i];
    return sum;
}
int retrieve(int a, int b)
{
    return retrieve(b) - retrieve(a-1);
}

// << FENWICK TREE


void solve()
{
    sf("%d", &tc);

    for(int cs = 1; cs <= tc; cs++)
    {
        pf("Case %d:\n", cs);

        build();

        sf("%d%d", &n, &q);
        // reading n integers
        for(int i = 1; i <= n; i++)
        {
            sf("%d", &arr[i]);
            update(i, arr[i]);
        }
        // reading queries
        while(q--)
        {
            sf("%d", &type);
            if(type == 1)
            {
                sf("%d", &x);
                x++;
                update(x, -arr[x]);
                pf("%d\n", arr[x]);
                arr[x] = 0;
            }
            else if(type == 2)
            {
                sf("%d%d", &x, &y);
                x++;
                update(x, y);
                arr[x] += y;
            }
            else
            {
                sf("%d%d", &x, &y);
                x++; y++;
                int answ = retrieve(x, y);
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
	else if(fopen("/media/luismo/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	

	solve();
}
