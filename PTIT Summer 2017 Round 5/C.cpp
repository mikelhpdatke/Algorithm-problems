#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000007

const long long maxn = 2100;
typedef pair<int, int> ii;

int n;
string s;
long long pw[maxn], sa[maxn], sb[maxn];

long long mul(long long x, long long y)
{
    return ((x % INF) * (y % INF)) % INF;
}
long long geta(int l, int r)
{
    return (sa[r] - mul(sa[l - 1], pw[r - l + 1]) + INF) % INF;
}

long long getb(int l, int r)
{
    return (sb[l] - mul(sb[r + 1], pw[r - l + 1]) + INF) % INF;
}

long long  L[maxn], R[maxn];
long long SR[maxn];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
  //  freopen("test.txt", "r", stdin);
    cin >> s;
    n = s.size();
    s = '=' + s;

    pw[0] = 1;
    FOR(i, 1, 2010) pw[i] = mul(pw[i - 1], 123456789);
    //cout <<s[1]<<"??"<<endl;
    sa[0] = 0;
    FOR(i, 1, n) sa[i] = (mul(sa[i - 1], 123456789) + s[i]) % INF;
    sb[n + 1] = 0;
    sb[n] = s[n];
    FORD(i, n - 1, 1) sb[i] = (mul(sb[i + 1], 123456789) + s[i]) % INF;
    //cout <<n<<" "<<s<<endl;
    //cout << geta(1, n) <<" "<<getb(1, n)<<endl;
    //long long res = 0;
    //FOR(i, 1, n) FOR(j, i, n) FOR(ii, j + 1, n) FOR(jj, ii, n) if (geta(i, j) == getb(i, j) && geta(ii, jj) == getb(ii, jj)){
      //  cout << s.substr(i, j - i + 1)<<" "<<s.substr(ii, jj - ii+ 1)<<endl;
     //   res++;
    //}
    //cout << res << endl;
   // cout << s.substr(3, 5)<<" "<<geta(3, 5)<<" "<<getb(3, 5)<<endl;
    FOR(i, 1, n) FOR(j, i, n) if (geta(i, j) == getb(i, j)){
        L[j]++;
        R[i]++;
    }
    SR[n] = R[n];
    FORD(i, n - 1, 1) SR[i] = SR[i + 1] + R[i];
    long long ans = 0;
    FOR(i, 1, n - 1) ans += 1ll * L[i] * SR[i + 1];
    cout << ans;
    return 0;
}

