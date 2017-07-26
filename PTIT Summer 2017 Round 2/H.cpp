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

char x[4];
char a[] ={'R', 'Y', 'G', 'B'};

bool match(char x, char y)
{
    if (x == 'R' && y == 'B') return 1;
    if (x == 'Y' && y == 'G') return 1;
    if (x == y) return 1;
    return 0;
}

bool same(char x, char y, char z)
{
    if (x == y || y == z) return 1;
    if (x == 'Y' && y == 'R' && z == 'G') return 1;
    return 0;
}
int dem = 0;
void update()
{
    //cout <<"??"<<endl;

    FOR(i, 0, 1){
        if (match(x[i], x[i + 1]) || match(x[i + 1], x[i])) return;
        if (i == 0 && (same(x[i], x[i + 1], x[i + 2]) ||
            same(x[i + 2], x[i + 1], x[i])) ) return;
    }
    FOR(i, 0, 2) cout << x[i];cout << endl;
    dem++;
}
void thu(int i)
{
    FOR(j, 0, 3){
        x[i] = a[j];
        if (i == 2) update();
        else thu(i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.inp", "r", stdin);
    thu(0);
    cout << dem<<endl;
   // cout << same('Y', 'R', 'Y')<<"??"<<endl;
    return 0;
}
