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
ll mod = 1e9 + 7;
const int lim = 500 + 2;

int n, m, b;
int ai[lim];

ll dp[lim][lim];

void solve()
{

    // this solutions is heavylly influenced by:
    // https://codeforces.com/blog/entry/17783
    cin >> n >> m >> b >> mod;

    // reading ai
    for(int i = 0; i < n; i++)
        cin >> ai[i+1];

    // base
    dp[0][0] = 1;

    // for each programmer
    for(int pr = 1; pr <= n; pr++)
    {
        // for each possible line to be written
        for(int line = 0; line <= m; line++)
        {
            // for each possible number of bugs
            for(int bugs = 0; bugs + ai[pr] <= b; bugs++)
            {
                dp[line+1][bugs+ai[pr]] += dp[line][bugs];
                dp[line+1][bugs+ai[pr]]%= mod;
            }
        }
    }

    ll answ = 0;
    for(int i = 0; i <= b; i++)
    {
        answ = (answ + dp[m][i]) % mod;
    }
    // print answer
    cout << answ;
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
	IO();

	fastIO();

	solve();
}

