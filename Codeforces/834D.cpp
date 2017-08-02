#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 55000;
typedef pair<int, int> ii;
int it[maxn * 5], d[maxn * 5];
int n, a[maxn], k;

int f[maxn][51];
set< int > S;

void down(int x, int len)
{
    if (len == 0) return;

    it[x] += d[x];
    if (len > 1){
        d[2 * x] += d[x];
        d[2 * x + 1] += d[x];
    }
    d[x] = 0;
}
int leaf[maxn];
void build(int x, int l, int r, int lo)
{
    if (l == r){
        it[x] = f[l][lo];
        d[x] = 0;
        leaf[l] = x;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x, l, mid, lo);
    build(2 * x + 1, mid + 1, r, lo);
    it[x] = max(it[2 * x], it[2 * x + 1]);
}

void update(int x, int l, int r, int u, int v)
{
    down(x, r - l + 1);
    if (r < u || v < l) return;
    if (u <= l && r <= v){
        d[x]++;
        down(x, r - l + 1);
        return;
    }
    int mid = (l + r) / 2;
    //down(x, r - l + 1);

    update(2 * x, l, mid, u, v);
    update(2 * x + 1, mid + 1, r, u, v);

    it[x] = max(it[2 * x], it[2 * x + 1]);
}

int get(int x, int l, int r, int u, int v)
{
    down(x, r - l + 1);
    if (r < u || v < l) return -1;
    if (u <= l && r <= v)
        return it[x];
    int mid = (l + r) / 2;
    return max(get(2 * x, l, mid, u, v), get(2 * x + 1, mid + 1, r, u, v));
}

int dd[maxn];
int prev[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("test.txt", "r", stdin);
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    memset(f, 0, sizeof(f));
    FOR(i, 1, n){
        S.insert(a[i]);
        prev[i] = 0;
        if (dd[a[i]] > 0) prev[i] = dd[a[i]];
            else prev[i] = 1;
        dd[a[i]] = i;

        f[i][1] = S.size();
    }

    FOR(lo, 2, k){
        FOR(i, 1, 4 * maxn + 100) it[i] = d[i] = 0;
        build(1, 1, n, lo - 1);
        //cout <<"??"<<endl;


        FOR(i, 1, n){
        //cout<<i<<"?"<<prev[i]<<endl;
            //if (i == 2 && lo == 3) cout <<get(1, 1, n, 1, 1)<<"WTF"<<endl;
            if (prev[i] <= i - 1)
                update(1, 1, n, prev[i], i - 1);
           // if (i == 2 && lo == 3) cout <<get(1, 1, n, 1, 1)<<"WTF"<<endl;
            f[i][lo] = max(f[i][lo - 1], get(1, 1, n, 1, i - 1));
        }
    }
    //cout << prev[2]<<"?"<<endl;
    //cout <<f[2][3]<<"??"<<endl;

    cout << f[n][k];
    return 0;
}
