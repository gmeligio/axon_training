/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1267 - Points in Rectangle (II)
	Online Judge: LightOJ
	Idea: Sweep Line + Segment Tree
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
int p, q;

// Point
struct pt
{
    int x, y;
    pt(){}
    pt(int xx, int yy){x = xx; y = yy;}
};

// Event
struct event
{
    pt fir, sec;
    int type;
    int qNmb;
    int id;

    event(){}
    event(pt f, pt s, int t)
    {fir = f; sec = s; type = t;}
};
vector<event> events;

bool cmp(event a, event b)
{
    if(a.fir.x == b.fir.x)
        return a.type < b.type;

    return a.fir.x < b.fir.x;
}

// >> COORDINATES COMPRESSION
set<int> rbTree;
map<int, int> comp;
// << COORDINATES COMPRESSION

// >> SEGMENT TREE
int t[lim<<2];

void build(int idx, int L, int R)
{
    t[idx] = 0;
    if(L == R)
        return;
    int le = idx*2+1, ri = le+1, mid = (L+R)/2;
    build(le, L, mid);
    build(ri, mid+1, R);
}

void update(int idx, int L, int R, int ii, int upd)
{
    if(L == R)
    {
        t[idx] += upd;
        return;
    }
    int le = idx*2+1, ri = le+1, mid = (L+R)/2;
    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    t[idx] = t[le] + t[ri];
}

int retrieve(int idx, int L, int R, int QL, int QR)
{
    if(L >= QL && R <= QR)
        return t[idx];
    if(L > QR || R < QL)
        return 0;
    int le = idx*2+1, ri = le+1, mid = (L+R)/2;
    int s1 = retrieve(le, L, mid, QL, QR);
    int s2 = retrieve(ri, mid+1, R, QL, QR);
    return s1+s2;
}

// << SEGMENT TREE

// to print answer
int answ[lim];

void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        rbTree.clear();
        comp.clear();
        events.clear();

        pf("Case %d:\n", cs);

        // reading
        sf("%d%d", &p, &q);
        // reading points
        for(int i = 0; i < p; i++)
        {
            int x, y;
            sf("%d%d", &x, &y);
            rbTree.insert(x);
            rbTree.insert(y);
			// create the event
            event e = event(pt(x, y), pt(-1, -1), 1);
			// add the event
            events.push_back(e);
        }

        // reading rectangles
        for(int i = 0; i < q; i++)
        {
            int x1,y1,x2,y2;
            sf("%d%d%d%d", &x1, &y1, &x2, &y2);
            rbTree.insert(x1);
            rbTree.insert(y1);
            rbTree.insert(x2);
            rbTree.insert(y2);

            // create the event
            // opening
            event e1 = event(pt(x1, y1), pt(x1, y2), 0);
            // closing
            event e2 = event(pt(x2, y1), pt(x2, y2), 2);
            e1.id = e2.id = i;
			// add events
            events.push_back(e1);
            events.push_back(e2);
        }

        // compressing
        int cnt = 1;
        for(set<int>::iterator it = rbTree.begin(); it != rbTree.end(); it++)
            comp[(*it)] = cnt++;
        // end compression

        // sort fucking events
        sort(events.begin(), events.end(), cmp);

        // build the SegmentTree
        build(0, 0, cnt);

        // sweeping the fucking line
        for(int i = 0; i < events.size(); i++)
        {
			// current event
            event e = events[i];
			
            if(e.type == 1)
            {
                pt p = e.fir;
                int x = comp[p.x];
                int y = comp[p.y];
				// update (add the point)
                update(0, 0, cnt, y, 1);
            }
            else if(e.type == 0)
            {
                int a = comp[e.fir.y];
                int b = comp[e.sec.y];
				// query the previous points in that interval
                int k = retrieve(0, 0, cnt, a, b);

                answ[e.id] = -k;
            }
            else
            {
                int a = comp[e.fir.y];
                int b = comp[e.sec.y];
				// query the previous points in that interval
                int k = retrieve(0, 0, cnt, a, b);
				// update the answer
                answ[e.id] += k;
            }
        }
        // print the answer
        for(int i = 0; i < q; i++)
            pf("%d\n", answ[i]);
    }
}

int main()
{
	solve();
}
