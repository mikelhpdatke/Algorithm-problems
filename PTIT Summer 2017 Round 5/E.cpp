#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;
typedef pair<int, int> ii;

long long n;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("test.txt", "r", stdin);
    cin >> n;
    if (n < 6){
        cout << n;
        return 0;
    }
    long long tmp = n / 5 + 1;
    int x = log(tmp) / log(2) - 1;
    //cout << x<<endl;
    if ( ((1ll << (x + 1)) - 1) * 5 >= n) x--;
    int cur = 1 << (x + 1);
    int rem = n - ((1ll << (x + 1)) - 1) * 5;
    int res = 1;
    //cout << cur<<" "<<rem<<endl;
    while (rem > cur && cur > 0){
        rem -= cur;
        res++;
    }
    cout << res;
    return 0;
}

