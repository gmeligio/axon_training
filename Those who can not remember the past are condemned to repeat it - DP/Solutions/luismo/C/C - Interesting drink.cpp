/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Interesting drink	
	Online Judge: codeforces.com (I guess)
	Idea: Sort + Binary Search
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


int n, q, x;
int xi[lim];

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> xi[i];
    }
    sort(xi, xi + n);
    xi[n] = mod;
    cin >> q;
    while(q-- > 0)
    {
        cin >> x;
        // upper bound
        int le = 0, ri = n;
        while(le < ri)
        {
            int mid = (le + ri) / 2;
            if(xi[mid] <= x)
                le = mid + 1;
            else ri = mid;
        }
        cout << le << endl;
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
	IO();

	fastIO();

	solve();
}
