#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;

long long n, k;
long long p;
long long a[maxn], b[maxn];
long long F[5000][5000];

void mmin(long long &x, long long v)
{
    x = min(x, v);
}

long long cost(int human, long long key)
{
    return (abs(human - key) + abs(key - p));
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k >> p;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, k) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);

    FOR(i, 0, 2999) FOR(j, 0, 2999) F[i][j] = 123456789123456789LL;
    F[0][0] = 0;
    FOR(i, 0, n)
    FOR(j, 0, k){
        //chon
        mmin(F[i + 1][j + 1], max(F[i][j], cost(a[i + 1], b[j + 1])) );
        //if (i == 1 && j == 1) cout << F[1][1]<<"??"<<endl;
        if (k - j - 1 >= n - i)
            mmin(F[i][j + 1], F[i][j]);
    }
    //FOR(i, 1, n) cout << a[i]<<" ";cout << endl;
    //FOR(i, 1, k) cout << b[i]<<" ";cout << endl;
    //cout << F[1][1]<<endl;
    cout << F[n][k];
    return 0;
}
