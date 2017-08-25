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
const int maxn = 100101;

int n, m;
long long k;
string a[maxn];

long long f[110][2010];

long long dp(int cur, int len)
{
    //cout << cur<<" "<<len<<endl;
    if (f[cur][len] > 0) return f[cur][len];
    if (len > m) return 0;
    if (len == m){
        f[cur][len] = 1;
        return 1;
    }

    long long ans = 0;
    FOR(i, 1, n) if (a[i].size() + len <= m){
        ans += dp(i, len + a[i].size());
    }
    f[cur][len] = ans;
    return ans;
}

string trace(int cur, int len, int rem)
{
    int last = 0;
    FOR(i, 1, n){
        if (rem > f[i][len + a[i].size()]){
            rem -= f[i][len + a[i].size()];
            last = i;
        } else break;
    }
    //cout << cur <<" "<<len<<" "<<rem<<" "<<last<<endl;
    if (last == n || len + a[last + 1].size() > m) return "";
    return  a[last + 1] + trace(last + 1, len + a[last + 1].size(), rem);
}
int main()
{
    freopen("ENGLISH.inp", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    //cout <<"??"<<endl;

    dp(0, 0);
    string ans = trace(0, 0, k);
    if (ans.size() < m || k > dp(0, 0)) cout <<"-";
    else cout << ans;
    return 0;
}
