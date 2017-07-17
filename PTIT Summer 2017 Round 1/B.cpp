#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 500000;

int n, k;
int a[maxn];
int c[200];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) a[i] %= k;
    //FOR(i, 1, n) cout << a[i]<<" ";cout << endl;
    FOR(i, 1, n) c[a[i]]++;
    long long ans = 0;
    int mid = k / 2;
    if (k % 2 == 1){
        //chan
        if (c[0] > 0) ans++;
        FOR(i, 1, mid) ans += max(c[i], c[k - i]);
    }
    else {
        if (c[0] > 0) ans++;
        FOR(i, 1, mid - 1) ans += max(c[i], c[k - i]);
        if (c[mid] > 0) ans++;
    }
    cout << ans;
    return 0;
}
