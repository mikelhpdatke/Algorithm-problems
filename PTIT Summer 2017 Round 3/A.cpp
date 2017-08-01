#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 200000;
typedef pair<int, int> ii;
int n;
int a[maxn];
int L[maxn], R[maxn];

int it[4 * maxn + 100];

int gcd(int x, int y)
{
    if (x == 0) return y;
    if (y == 0) return x;
    return __gcd(x, y);
}

void build(int x, int l, int r)
{
    if (l == r){
        it[x] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    it[x] = gcd(it[2 * x], it[2 * x + 1]);
}

int get(int x, int l, int r, int u, int v)
{
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return it[x];
    int mid = (l + r) / 2;
    return gcd(get(2 * x, l, mid, u, v), get(2 * x + 1, mid + 1, r, u, v));
}

bool comp(ii x, ii y)
{
    if (x.second != y.second) return x.second > y.second;
    else return x.first < y.first;
}

vector<ii> ans;
vector<ii> res;
bool dd[maxn];
ii b[maxn];


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("test.txt", "r", stdin);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    L[1] = 1;
    build(1, 1, n);

    FOR(i, 2, n){
        int d = 1, c = i, g, res = i;
        while (d <= c){
            g = (d + c) / 2;
            if (get(1, 1, n, g, i) == a[i]){
                res = g;
                c = g - 1;
            }
            else d = g + 1;
        }
        //if (i == 6) cout << res<<"???"<<endl;
        L[i] = res;
    }
    int mmax = 0;
    R[n] = n;
    FORD(i, n - 1, 1){
        int d = i, c = n, g, res = i;
        while (d <= c){

            g = (d + c) / 2;
      //       if (i == 1) cout <<d<<"?????"<<c<<" mid "<<g<<" "<<get(1, 1, n, i, g)<<"=="<<a[i]<<endl;
            if (get(1, 1, n, i, g) == a[i]){
                res = g;
                d = g + 1;
                //if (i == 1) cout <<d<<"wtf"<<endl;
            } else c = g - 1;
        }
        R[i] = res;
    }
    FOR(i, 1, n) mmax = max(mmax, R[i] - L[i]);
    FOR(i, 1, n) if (L[i] != R[i] && R[i] - L[i] == mmax) ans.push_back(ii(L[i], R[i]));
    int i = 0;
    while (i < ans.size()){
        int j = i;
        res.push_back(ans[i]);
        while (j + 1 < ans.size() && ans[j + 1].first == ans[i].first && ans[j + 1].second == ans[i].second) j++;
        i = j + 1;
    }
    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) cout << res[i].first <<" "<<res[i].second << endl;

    return 0;
}
