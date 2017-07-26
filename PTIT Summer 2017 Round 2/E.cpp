//#Suffix Array NLogN Algorithm
#include<bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }
#define PR0(A, n) { cerr << #A << " = "; REP(_, n) cerr << A[_] << ' '; cerr << endl; }


#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())

using namespace std;

double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }

const int INF = 1000000007;
const int maxn = 500001;
const int base = 500000;

struct data{
    int p;
    int r[2];
} L[maxn], encode[maxn];

int P[30][maxn], dd[maxn], pos[maxn], lcp[maxn], x[maxn];
int cnt, tmp;
int n, a, b;
string s;
void sx()
{
  FOR(i, 0, max(500, n)) dd[i] = 0;
  FOR(i, 1, n) dd[L[i].r[1]]++;
  FOR(i, 1, max(500, n)) dd[i] += dd[i - 1];
  FORD(i, n, 1) encode[dd[L[i].r[1]]--] = L[i];
  FOR(i, 1, n) L[i] = encode[i];

  FOR(i, 0, max(500, n)) dd[i] = 0;
  FOR(i, 1, n) dd[L[i].r[0]]++;
  FOR(i, 1, max(500, n)) dd[i] += dd[i - 1];
  FORD(i, n, 1) encode[dd[L[i].r[0]]--] = L[i];
  FOR(i, 1, n) L[i] = encode[i];
}

int test;

int it[maxn * 6];
int node[maxn];

void build(int p, int l, int r)
{
    if (l == r){
        it[p] = x[l];
        node[l] = p;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    it[p] = min(it[p * 2], it[p * 2 + 1]);
}

void update(int i)
{
    int p = node[i];
    while (p > 0){
        it[p] = min(it[p], x[i]);
        p /= 2;
    }
}

int get(int p, int l, int r, int u, int v)
{
    if (r < u || v < l) return INF;
    if (u <= l && r <= v) return it[p];
    int mid = (l + r) / 2;
    return min(get(p * 2, l, mid, u, v), get(p * 2 + 1, mid + 1, r, u, v));
}

int f[maxn];
long long G[maxn], pw[maxn];


long long gethash(int l, int r)
{
    return (G[r] - G[l - 1] * pw[r - l + 1]);
}

int cmp(int i, int j, int len)
{
    int l = 1, r = len, g, res = 0;
    while (l <= r){
        g = (l + r) / 2;
        if (gethash(i, i + g - 1) == gethash(j, j + g - 1))
        {
            res = g;
            l = g + 1;
        } else r = g - 1;
    }
    if (res == len) return 0;
    else if (s[i + res - 1] < s[j + res - 1]) return -1;
    else return 1;
}

//long long P = INF;

//bool ch(int x, int y, int len)
//{
//    return (G[x + len - 1] - G[x - 1] * pw[len] == G[y + len - 1] - G[y - 1] * pw[len]);
//}
long long has[maxn],pr[maxn];

inline bool ch(int x,int y,int z){
    return (has[x+z-1]-has[x-1]+INF)*pr[n-x]%INF==(has[y+z-1]-has[y-1]+INF)*pr[n-y]%INF;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.inp", "r", stdin);
    cin >> test;
    while (test--){
    memset(P, 0, sizeof(P));
    memset(L, 0, sizeof(L));
    memset(dd, 0, sizeof(dd));
    memset(encode, 0, sizeof(encode));
    memset(it, 0, sizeof(it));
    memset(x, 0, sizeof(x));
    memset(pos, 0, sizeof(pos));

    cin >>n >> a >> b >> s;
    n = s.size();
    FOR(i, 1, n) P[0][i] = s[i - 1] + 1;
  for(cnt = 1, tmp = 1; cnt <= n; tmp++, cnt *= 2){
    FOR(i, 1, n){
      L[i].r[0] = P[tmp - 1][i];
      L[i].r[1] = (i + cnt <= n ? P[tmp - 1][i + cnt] : 0);
      L[i].p = i;
    }
    sx();
    FOR(i, 1, n)
    P[tmp][L[i].p] = (i > 1 && L[i].r[0] == L[i - 1].r[0] && L[i].r[1] == L[i - 1].r[1] ? P[tmp][L[i - 1].p] : i);
  }
  FOR(i, 1, n) x[P[tmp - 1][L[i].p]] = L[i].p;
  FOR(i, 1, n) pos[x[i]] = i;


    //FOR(i, 1, n) cout << x[i]<<" ";cout << endl;
   // FOR(i, 1, n) cout << pos[i]<<" ";cout << endl;
    //FOR(i, 1, n) cout << s.substr(x[i] - 1, n)<<endl;
    //cout << endl;
    // Initial

    pr[0]=1;
    for (int i=1;i<=n+1;i++) pr[i]=pr[i-1]*349%INF;
    for (int i=1;i<=n + 1;i++) has[i]=(has[i-1]+pr[i]*s[i - 1])%INF;


    build(1, 1, n);
//    pw[0] = 1;
//    FOR(i, 1, maxn - 1) pw[i] = 1ll * pw[i - 1] * base;
//    G[0] = 0;
//    FOR(i, 1, n) G[i] = G[i - 1] * base + s[i - 1];
    //
    f[0] = 0;
    //cout << get(1, 1, n, 1, 2)<<"??"<<endl;
    FOR(i, 1, n){
        f[i] = f[i - 1] + a;
        int l=0;
        int r=i/2+1;
        while (l+1<r){
            int m=(l+r)/2;
            int ll=1;
            int mm,rr=pos[i-m+1];
            while (ll<rr){
                mm=(ll+rr)/2;
                if (ch(x[mm],i-m+1,m))  rr=mm;
                else                    ll=mm+1;
            }
            int L=ll;
            ll=pos[i-m+1];
            rr=n+1;
            while (ll+1<rr){
                mm=(ll+rr)/2;
                if (ch(x[mm],i-m+1,m))   ll=mm;
                else                     rr=mm;
            }
            int R=ll;
            cout <<i<<" "<<L<<" "<<R<<"??"<<endl;
            if (get(1,1,n,L,R)<=i-m*2+1)  l=m;
            else                            r=m;
        }
        f[i] = min(f[i], f[i - l] + b);
    }
    cout << f[n] << endl;
    }



    return 0;
}
