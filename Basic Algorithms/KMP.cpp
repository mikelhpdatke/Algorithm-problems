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
const int maxn = 1000005;

string s, x;
int next[maxn];

int main()
{
    ios::sync_with_stdio(0);
    //freopen("test.txt", "r", stdin);
    cin.tie(0);

    cin >> s >> x;
    s = '=' + s;
    x = '=' + x;

    next[1] = 0;
    int m = s.size() - 1;
    int n = x.size() - 1;
    int jj = 0;
    int j = 1;
    while (j <= n){
        while (jj > 0 && x[j] != x[jj]) jj = next[jj];
        j++,jj++;
        if (x[j] == x[jj]) next[j] = next[jj];else next[j] = jj;
    }
    //FOR(i, 1, n + 1) cout << next[i]<<" ";cout<<endl;
    j = 1;
    FOR(i, 1, m){
        while (j > 0 && s[i] != x[j]) j = next[j];
        j++;
        if (j > n){
            cout << i - n + 1<<" ";
            j = next[j];
        }
    }

    return 0;
}
