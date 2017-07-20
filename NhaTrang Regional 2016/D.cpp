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
const int maxn = 1000000;

int test;
long long n, M;
int Go[51][51];
int lps;
string s;

long long mul(long long a, long long b)
{
    long long x = a / maxn;
    long long y = a % maxn;
    return ((((x * maxn) % M) * b) % M + (y * b) % M) % M;
}

struct Matrix{
    long long arr[51][51];
    int m, n;
    Matrix(){}
    Matrix(int _m, int _n){
        m = _m; n = _n;
        FOR(i, 0, m) FOR(j, 0, n) arr[i][j] = 0;
    }

    Matrix operator * (Matrix &other){
        int x = m, y = other.n;
        Matrix res(x, y);
        for(int i = 0; i <= x; i++) for(int j = 0; j <= y; j++)
            for(int k = 0; k <= n; k++)
                res.arr[i][j] = (res.arr[i][j] + mul(arr[i][k], other.arr[k][j])) % M;
        return res;
    }
};


Matrix power(Matrix a, long long n)
{
    if (n == 1) return a;
    Matrix tmp;
    tmp = power(a, n / 2);
    if (n % 2 == 1) return tmp * tmp * a;
    else return tmp * tmp;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.inp", "r", stdin);

    cin >> test;
    long long len;
    while(test--){
        cin >> len >> M >> s;
        lps = 0;
        n = SZ(s);
        //cerr << s<<"??"<<endl;
        //cout << mul(56,636) <<"??"<<endl;
        REP(i, 51) REP(j, 51) Go[i][j] = 0;
        Go[0][s[0] - 'a'] = 1;

        FOR(i, 1, n - 1){
            FOR(j, 0, 25) Go[i][j] = Go[lps][j];
            //cout << Go[0][5]<<"??"<<i<<"??"<<endl;
            Go[i][s[i] - 'a'] = i + 1;
            //cout << Go[0][5]<<"??"<<i<<"??"<<endl;
            if (i < n) lps = Go[lps][s[i] - 'a'];
                    //cout << Go[0][5]<<"??"<<i<<"??"<<endl;

        }
        FOR(j, 0, 25) Go[n][j] = n;
//        for(int i = 0; i <= n; i++){
//            for(int j = 0; j <= 25; j++) cout << Go[i][j]<<" ";cout<<endl;
//        }
//        cout << Go[0][5]<<"??"<<endl;
//        //
        Matrix f(n, n);
        f.arr[0][s[0] - 'a'] = 1;

        Matrix base(n, n);

        FOR(j, 0, 25)
            FOR(i, 0, n)
                base.arr[i][Go[i][j]]++;
//        FOR(i, 0, n){
//            FOR(j, 0, n) cout << base.arr[i][j]<<" ";
//            cout << endl;
//        }
        base = power(base, len);
        Matrix ff(n, n);
//        ff = base * base * base;
//        FOR(i, 0, n){
//            FOR(j, 0, n) cout << ff.arr[i][j]<<" ";
//            cout << endl;
//        }
        f = f * base;
        cout << f.arr[0][n] << endl;
    }
    return 0;
}
