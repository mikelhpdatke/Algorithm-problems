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
const int maxn = 200000;
int n, k;
int a[maxn];

int dd[maxn];
set< int > S;

int main()
{
    ios::sync_with_stdio(0);
    //freopen("test.inp", "r", stdin);
    cin.tie(0);
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, k){
        dd[a[i]]++;
        if (dd[a[i]] == 1) S.insert(a[i]);
        if (dd[a[i]] > 1) S.erase(a[i]);
    }
    if (S.size() == 0) cout <<"Nothing"  << endl;
    else cout << *S.rbegin() << endl;

    FOR(i, k + 1, n){
        dd[a[i - k]]--;
        if (dd[a[i - k]] == 1) S.insert(a[i - k]);
        if (dd[a[i - k]] == 0) S.erase(a[i - k]);

        dd[a[i]]++;
        if (dd[a[i]] == 1) S.insert(a[i]);
        if (dd[a[i]] > 1) S.erase(a[i]);
        if (S.size() == 0) cout <<"Nothing"  << endl;
    else cout << *S.rbegin() << endl;
    }

    return 0;
}
