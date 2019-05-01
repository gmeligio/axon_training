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
const int lim = 3e5 + 2;

int n, q, type, xi, ti;

vector<int> adj[lim];
int arr[lim];

// >> FENWICK TREE
int t[lim];

inline int lowBit(int i) {return i&-i;}

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

// << FENWICK TREE


void solve()
{
    cin >> n >> q;

    int len = 1;
    int line = 0;

    while(q--)
    {
        cin >> type;

        if(type == 1)
        {
            cin >> xi;
            // update in the Bit
            update(len, 1);
            arr[len] = 1;
			// add to the collection of applications			
            adj[xi].push_back(len++);

            // answ
            int k = retrieve(lim - 1);
            cout << k << endl;
        }
        else if(type == 2)
        {
            cin >> xi;

            for(int i = 0; i < adj[xi].size(); i++)
            {
                int idx = adj[xi][i];
                if(arr[idx] == 1)
                {
                    arr[idx] = 0;
                    update(idx, -1);
                }
            }
            // clear the vector
            adj[xi].clear();

            // answ
            int k = retrieve(lim - 1);
            cout << k << endl;
        }
        else
        {
            cin >> ti;

            for(line; line <= ti; line++)
            {
                if(arr[line] == 1)
                {
                    arr[line] = 0;
                    update(line, -1);
                }
            }
            // answ
            int k = retrieve(lim - 1);
            cout << k << endl;
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
	IO();

	fastIO();

	solve();
}
