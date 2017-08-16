#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;
typedef pair<int, int> ii;

int n, m;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("test.txt", "r", stdin);
    cin >> n >> m;
    int ans = 0;
    FOR(i, 0, max(n, m))
        FOR(j, 0, max(n, m)) if (i * i + j == n && i + j * j == m) ans++;
    cout << ans;
    return 0;
}
