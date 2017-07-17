#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;
typedef pair<int, int> ii;
ii x[5];


bool check(ii x[])
{
    sort(x, x + 4);
    return (x[0].first == x[1].first && x[0].second == x[2].second
    && x[2].first == x[3].first && x[1].second == x[3].second
    && x[0].first != x[2].first && x[0].second != x[1].second && x[3].second != x[2].second
    && x[1].first != x[3].first);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--){
        FOR(i, 0, 3) cin >> x[i].first >> x[i].second;
        cout << (check(x) == 1 ? "YES" :"NO") << endl;
    }
    return 0;
}
