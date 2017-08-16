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

int f[5001][5001];
int n, k, a, b;
int s[5001];
void add(int &a, int value){
    a = (a + value) % INF;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n >> k >>  a >> b;
   // cout << n << k << a << b;
    if (a < b){
        f[a][0] = 1;
        FOR(i, 1, b) s[i] = (s[i - 1] + f[i][0]) % INF;
        //cout << s[b]<<"??"<<endl;
        FOR(loop, 1, k){
            FOR(i, 1, b - 1){
                add(f[i][loop], s[i - 1]);
                int mid = (i + b - 1) / 2;
                //cout <<i<<" "<<mid<<" "<<b<<endl;
                add(f[i][loop], (s[mid] - s[i] + INF) % INF ) ;
                //cout <<loop<<": "<<i<<" "<<f[i][loop]<<endl;
            }
            s[0] = 0;
            FOR(i, 1, b) s[i] = (s[i - 1] + f[i][loop]) % INF;
        }
        int ans = 0;
        FOR(i, 1, b - 1) add(ans, f[i][k]);
        cout << ans;
    }
    else{
        f[a][0] = 1;
        s[b] = 0;
        FOR(i, b + 1, n) s[i] = (s[i - 1] + f[i][0]) % INF;
        FOR(loop, 1, k){
            FOR(i, b + 1, n){
                add(f[i][loop], (s[n] - s[i] + INF) % INF );
                int mid = (i + b) / 2 + 1;
                add(f[i][loop], max(0, (s[i - 1] - s[mid - 1] + INF) % INF ) );
                //cout <<loop<<": "<<i<<" "<<f[i][loop]<<endl;
            }
            s[b] = 0;
            FOR(i, b + 1, n) s[i] = (s[i - 1] + f[i][loop]) % INF;
        }
        int ans = 0;
        FOR(i, b + 1, n) add(ans, f[i][k]);
        cout << ans;
    }
    return 0;
}
