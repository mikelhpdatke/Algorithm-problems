#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;
typedef pair<int, int> ii;

int n, k;
int pos[10][maxn], a[10][maxn];
int f[maxn];

void mmax(int &a, int b)
{
    if (a < b) a = b;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("test.txt", "r", stdin);
    cin >> n >> k;
    FOR(j, 1, k) FOR(i, 1, n) cin >> a[j][i];

    FOR(j, 1, k) FOR(i, 1, n) pos[j][a[j][i]] = i;

    //cout << pos[3][5]<<"??"<<endl;
    f[0] = 0;
    for(int i = 0; i < n; i++){
        for(int ne = i + 1; ne <= n; ne++){
            bool ok = 1;
            for(int j = 1; j <= k; j++){
                int ipos = pos[j][a[1][i]];
                int nepos = pos[j][a[1][ne]];
               // if (i == 1)cout << a[1][i]<<"::"<<"Hang: "<<j<<" ipos="<<ipos<<" nepos="<<nepos<<endl;
                if (ipos > nepos){
                    ok = 0;
                    break;
                }
            }
            if (ok == 1) mmax(f[ne], f[i] + 1);
        }
    }
    int ans = 0;
    //FOR(i, 1, n) cout << f[i]<<" ";cout << endl;
    FOR(i, 1, n) ans = max(ans, f[i]);
    cout << ans;
    return 0;
}
