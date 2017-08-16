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

int n, k, odd, even;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    odd = 0; even = 0;
    cin >> n >> k;
    FOR(i, 1, n){
        int x;
        cin >> x;
        if (x % 2 == 1) odd ++; else even++;
    }

    int x = (n - k + 1) / 2;
    int y = n - k - x;

    int res = 0;

    if (n == k) res = odd % 2;
    else {
        if (x >= even && even <= odd && k % 2 == 1) res=1;
        if (y < odd && (n - k) % 2 == 1 && k % 2 == 1) res = 1;
        if (y < min(odd, even) && (n - k) % 2 == 1 && k % 2 == 0) res = 1;
    }
    cout << (res == 0 ? "Youbed" : "GipeHay");
    return 0;
}
