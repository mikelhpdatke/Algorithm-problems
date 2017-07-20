// Finite Automata
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
const int maxn = 1000001;
string s, pat;

int Go[maxn][256];
int lps = 0;
int m;
int n;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    s = "GEEKS FOR GEEKS";
    pat = "GEEKS";

    n = pat.size();
    m = s.size();
    memset(Go, 0, sizeof(Go));
    Go[0][pat[0] ] = 1;
    lps = 0;

    FOR(i, 1, n){
        FOR(j, 0, 255) Go[i][j] = Go[lps][j];
        Go[i][pat[i] ] = i + 1;
        if (i < n) lps = Go[lps][pat[i] ];
    }

    int state = 0;
    FOR(i, 0, m - 1){
        state = Go[state][s[i] ];
        if (state == n){
            cout << i - n + 1 << " ";
        }
    }

    return 0;
}
