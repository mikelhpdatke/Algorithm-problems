//#Suffix Array NLogN Algorithm
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
const int maxn = 100001;

string s;
struct data{
    int p;
    int r[2];
} L[maxn], encode[maxn];

int P[30][maxn], dd[maxn], pos[maxn], lcp[maxn], x[maxn];
int cnt, tmp;
int n;
void sx()
{
  FOR(i, 0, max(300, n)) dd[i] = 0;
  FOR(i, 1, n) dd[L[i].r[1]]++;
  FOR(i, 1, max(300, n)) dd[i] += dd[i - 1];
  FORD(i, n, 1) encode[dd[L[i].r[1]]--] = L[i];
  FOR(i, 1, n) L[i] = encode[i];

  FOR(i, 0, max(300, n)) dd[i] = 0;
  FOR(i, 1, n) dd[L[i].r[0]]++;
  FOR(i, 1, max(300, n)) dd[i] += dd[i - 1];
  FORD(i, n, 1) encode[dd[L[i].r[0]]--] = L[i];
  FOR(i, 1, n) L[i] = encode[i];
}

string st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> s;
    cin >> st;
    n = s.size();
    FOR(i, 1, n) P[0][i] = s[i - 1] + 1;
    for(cnt = 1, tmp = 1; cnt <= n; tmp++, cnt *= 2){
        FOR(i, 1, n){
            L[i].r[0] = P[tmp - 1][i];
            L[i].r[1] = (i + cnt <= n ? P[tmp - 1][i + cnt] : 0);
            L[i].p = i;
        }
        sx();
        FOR(i, 1, n)
        P[tmp][L[i].p] = (i > 1 && L[i].r[0] == L[i - 1].r[0] && L[i].r[1] == L[i - 1].r[1] ? P[tmp][L[i - 1].p] : i);
    }
    FOR(i, 1, n) x[P[tmp - 1][L[i].p]] = L[i].p;
    FOR(i, 1, n) pos[x[i]] = i;

    int k = 0;
    FOR(i, 1, n) if (pos[i] != n){
        int j =  x[pos[i] + 1];
        while (s[i - 1 + k] == s[j - 1 + k]) k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
    FOR(i, 1, n) cout << s.substr(x[i] - 1, n) << endl;


        int i = n;
        int l=0;
        int r=i/2+1;
        while (l+1<r){
            int m=(l+r)/2;
            int ll=1;
            int mm,rr=pos[i-m+1];
            while (ll<rr){
                mm=(ll+rr)/2;
                if (ch(x[mm],i-m+1,m))  rr=mm;
                else                    ll=mm+1;
            }
            int L=ll;
            ll=pos[i-m+1];
            rr=n+1;
            while (ll+1<rr){
                mm=(ll+rr)/2;
                if (ch(x[mm],i-m+1,m))   ll=mm;
                else                     rr=mm;
            }
            int R=ll;
            cout <<L<<" "<<R<<"??"<<endl;
            if (get(1,1,n,L,R)<=i-m*2+1)  l=m;
            else                            r=m;
        }

    }
    return 0;
}
