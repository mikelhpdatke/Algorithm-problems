#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;
typedef pair<int, int> ii;

int n;
int a[maxn];
int dd[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("test.txt", "r", stdin);
    //f[0] = 0;
    a[0] = INF;
    cin >> n;
    memset(dd, 0, sizeof(dd));
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) dd[a[i]]++;
    //cout <<n<<"??"<<endl;
    int ans = 0;
    FOR(len, 1, 1000){
        int dem = 0;
        FOR(i, 1, 1000) if (dd[i] > 0){
            dem++;
            dd[i]--;
        }
        if (dem > 0) ans += dem - 1;
    }
    cout << ans;
    return 0;
}

