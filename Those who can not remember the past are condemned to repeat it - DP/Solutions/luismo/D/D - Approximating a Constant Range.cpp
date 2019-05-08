/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: D - Approximating a Constant Range
	Online Judge: codeforces.com
	Idea: Two Pointers  + Set
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
const int lim = 1e5 + 2;

int n;
int arr[lim];
int hh[lim];

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // the two pointers
    int one = -1, two = 0;
    // keep trace of the max and min
    int mx = -1, mn = mod;

    // Red-Black Tree containing pairs<value, position>
    set<pii> rbTree;

    int answ = 0;

    for(two = 0; two < n; two++)
    {
        int k = arr[two];

        rbTree.insert(mkp(k, two));

        // iterator of the Red-Black Tree
        set<pii>::iterator it;

        if(k > mx && k - mn > 1)
        {
	    // first element (lowest)
            it = rbTree.begin();
            while( k - (*it).first > 1)
            {
                one = max(one, (*it).second);
                rbTree.erase(it);
                it = rbTree.begin();
            }
        }
        else if(k < mn && mx - k > 1)
        {
	    // last element (greatest)
            it = rbTree.end();
            it--;

            while((*it).first - k > 1)
            {
                one = max(one, (*it).second);
                rbTree.erase(it);

                it = rbTree.end();
                it--;
            }
        }

        it = rbTree.begin();
        mn = (*it).first;
        it = rbTree.end(); it--;
        mx = (*it).first;
        // update the answer
        if(two - one > answ)
            answ = two - one;
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
