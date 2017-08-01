#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;
typedef pair<int, int> ii;

int numNt[maxn];
int n, snt = 0;
long long a[maxn];
vector< long long > tree;

int dp(int cur, vector<long long> &tree, int numChil, int numLeaves)
{
    if (cur > n)
        return (numChil > 1) + numLeaves + n - snt;

    int ans = 123456789;

    for(int i = 0; i < tree.size(); i++) if (tree[i] % a[cur] == 0){
        tree[i] /= a[cur];
        tree.push_back(a[cur]);
        ans = min(ans, dp(cur + 1, tree, numChil + (i == 0), numLeaves + (i == 0 ? numNt[cur] : 0)) );
        tree.pop_back();
        tree[i] *= a[cur];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("test.txt", "r", stdin);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1, greater<long long>());

    FOR(i, 1, n){
        long long x = a[i];
        for(int j = 2; 1ll * j * j <= x; j++){
            while (x % j == 0){
                numNt[i]++;
                x /= j;
            }
        }
        if (x > 1) numNt[i]++;
        if (numNt[i] == 1) snt++;
        //cout << a[i]<<" "<<numNt[i]<<endl;
    }
    tree.push_back(0);

    cout << dp(1, tree, 0, 0);
    return 0;
}
