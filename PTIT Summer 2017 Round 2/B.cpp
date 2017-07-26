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
string s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   // freopen("test.inp", "r", stdin);
    cin >> s;
    long long ans = 0;
    if (s[0] == '0' || s[0] == '4' || s[0] == '8') ans = 1;
    FOR(i, 1, s.size() - 1){
        if (s[i] == '0' || s[i] == '4' || s[i] == '8') ans++;
        int tmp = (s[i - 1] - '0');
        tmp = tmp * 10 + (s[i] - '0');
        if (tmp % 4 == 0) ans += i;
    }
    cout << ans;
    return 0;
}
