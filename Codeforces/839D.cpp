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
const long long  INF = 1000000007;
const int maxn = 2001001;

int n;
int a[maxn];

long long mul(long long x, long long y)
{
    return ((x % INF) * (y % INF)) % INF;
}

long long cnt[maxn], ans[maxn];

long long dd[maxn];

long long power(int x, long long n)
{
    if (n == 0) return 1;
    long long tmp = power(x, n / 2);
    if (n % 2 == 0) return mul(tmp, tmp);
    else return mul(x, mul(tmp, tmp));
}

int main()
{
//freopen("test.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) dd[a[i]]++;
    FOR(i, 2, 1000000)
        for(int j = i; j <= 1000000; j+=i) cnt[i] += dd[j];
    FORD(i, 1000000, 2) if (cnt[i] > 0){
        ans[i] = mul(cnt[i], power(2, cnt[i] - 1));
        for(int j = i * 2; j <= 1000000; j+=i) ans[i] = (ans[i] - ans[j] + INF) % INF;
    }
    long long res = 0;
    FOR(i, 2, 1000000) res = (res + mul(i, ans[i])) % INF;
    cout << res;
    return 0;
}
