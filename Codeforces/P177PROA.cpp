#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

long long r, X0, Y0, X1, Y1;
int main()
{
    cin >> r >> X0 >> Y0 >> X1 >> Y1;
    double dis = sqrt((X1 - X0) * (X1 - X0) + (Y1 - Y0)*(Y1-Y0));
    int rem = (dis - int(dis) < 0.00001 ? 0 : 1);
    int d = int(dis);
    int res = d / (r * 2);
    if (d % (r * 2) > 0) rem = 1;
    cout << res + rem;
    return 0;
}
