#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const int maxn = 1e6 + 10;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("test.inp", "r", stdin);

    int n, v0, a, v1, l;
    cin >> n >> v0 >> v1 >> a >> l;
    int res = 0, cur = v0;
    while (n > 0){
        if (res == 0){
            res++;
            n -= cur;
        } else{
            res++;
            n -= cur - l;
        }
        cur = min(a + cur, v1);
    }
    cout << res;
    return 0;
}
