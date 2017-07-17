#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 500000;

int n;
int a[maxn];


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("test.txt", "r", stdin);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    long long sum = 0;
    long long mmin = 0;
    long long ans1 = -123456789123456789LL;
    FOR(i, 1, n){
        sum += a[i];
        if (sum - mmin > ans1) ans1 = sum - mmin;
        mmin = min(mmin, sum);
    }

    long long ans2 = 0;
    FOR(i, 1, n) if (a[i] > 0) ans2+=a[i];
    if (*max_element(a + 1, a + n + 1) < 0)
        ans2 = *max_element(a + 1, a + n + 1);
    cout << ans1<<" "<<ans2;
    return 0;
}
