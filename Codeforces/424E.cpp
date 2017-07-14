#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 100000 + 10;

int n;
int a[maxn];
long long T[maxn];

void update(int x, int val)
{
    for(; x < maxn; x += x & (-x)) T[x]+=val;
}

long long  get(int x)
{
    long long ans = 0;
    for(;x>0;x -= x &(-x)) ans += T[x];
    return ans;
}

long long calc(int dau, int cuoi)
{
    if (dau <= cuoi) return get(cuoi) - get(dau - 1);
    else return get(n) - get(dau - 1) + get(cuoi);
}

set<int> S[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) S[a[i]].insert(i);
    FOR(i, 1, n) update(i, 1);
    long long ans = 0;
    int prev = 1;
    FOR(val, 1, maxn - 10){
        while (S[val].size() > 0){
            set<int> :: iterator it = S[val].lower_bound(prev);
            if (it == S[val].end()) it = S[val].begin();
            ans += calc(prev, *it);
            update(*it, -1);
            prev = *it;
            S[val].erase(it);
        }
    }
    cout << ans;
    return 0;
}
