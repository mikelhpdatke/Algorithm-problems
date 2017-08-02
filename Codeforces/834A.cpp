#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 500000;
typedef pair<int, int> ii;

map<char, int> M;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("test.txt", "r", stdin);
    M['>'] = 2;
    M['<'] = 4;
    M['v'] = 3;
    M['^'] = 1;
    char c1, c2;
    int n;
    bool ok1,ok2;
    ok1 = 0;
    ok2 = 0;
    cin >> c1 >> c2 >> n;
    int discw=0;

    if (M[c1] > M[c2]) discw = 4 - abs(M[c1] - M[c2]);
    else discw = M[c2] - M[c1];

    if ((n - discw) % 4 == 0) ok1 = 1;
    discw = 4 - discw;
    if ((n - discw) % 4 == 0) ok2 = 1;

    if (ok1 && ok2) cout <<"undefined";
    else if (ok1) cout <<"cw";else cout <<"ccw";
    return 0;
}
