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

int N, x, y;
string str;
ll arr[lim];

// >> FENWICK TREE
ll tree[lim];

void build()
{
    for(int i = 0; i < lim; i++)
        tree[i] = 0;
}

int lowBit(int i) {return i&-i;}

void update(int idx, int upd)
{
    for(int i = idx; i < lim; i+= lowBit(i))
    {
        tree[i]+= upd;
    }
}

ll retrieve(int idx)
{
    ll sum = 0;
    for(int i = idx; i > 0; i-= lowBit(i))
        sum += tree[i];
    return sum;
}


// << FENWICK TREE

void solve()
{
    int cs = 1;
    sf("%d", &N);
    while(N != 0)
    {
        build();
        pf("Case %d:\n", cs++);
        // reading integers
        for(int i = 1; i <= N; i++)
        {
            sf("%lld", &arr[i]);
            update(i, arr[i]);
        }

        //
        sf("%s", str.c_str());
        while(str[0] != 'E')
        {
            sf("%d%d", &x, &y);
            if(str[0] == 'S')
            {
                ll k = arr[x];
                arr[x] = y;
                update(x, y-k);
            }
            else
            {
                ll k = retrieve(y) - retrieve(x-1);
                pf("%lld\n", k);
            }
            sf("%s", str.c_str());
        }

        sf("%d", &N);
        if(N == 0)
            return;
        pf("\n");
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
	//IO();

	//fastIO();

	solve();
}
