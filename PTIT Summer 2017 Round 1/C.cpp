#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000007

const long long maxn = 200000 + 50;
int n;
long long a[maxn];
long long gt[maxn];
long long mul(long long x, long long y)
{
    return ((x % INF) * (y % INF)) % INF;
}

long long power(long long a, long long x)
{
    if (x == 0) return 1;
    long long tmp = power(a, x / 2);
    if (x % 2 == 1) return mul(mul(tmp, tmp), a);
    else return mul(tmp, tmp);
}

long long C(long long n, long long k)
{
    return mul(gt[n], mul(power(gt[k], INF - 2), power(gt[n - k], INF - 2)));
}

int x[10];


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    gt[0] = 1;
    FOR(i, 1, maxn - 1) gt[i] = mul(gt[i - 1], i);

    cin >> n;
    long long m = n - 1;
    long long cur = C(2 * m + 1, m + 1);
    cout << (cur * 2 - n + INF) % INF << endl;
    //cout << C(5000,2466);
    return 0;
}
