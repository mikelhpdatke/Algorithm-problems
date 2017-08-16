#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }
#define PR0(A, n) { cerr << #A << " = "; REP(_, n) cerr << A[_] << ' '; cerr << endl; }
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
using namespace std;
double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }
const int INF = 1000000007;
const int maxn = 2e5 + 10;

int n, k;
long long f[maxn][5];
long long num[maxn];

long long ans = 0 ;
vector< int > adj[maxn];
int pa[maxn];

int sub(int i, int j)
{
    return ( (i % k) - (j % k) + k) % k;
}

void dfs(int u, int depth)
{
    f[u][depth % k] = 1;
    num[u] = 1;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if (v != pa[u]){
            pa[v] = u;
            dfs(v, depth + 1);
            for(int r1 = 0; r1 < k; r1++)
                for(int r2 = 0; r2 < k; r2++){
                    int reminders = sub(r1 + r2, depth * 2);
                    int need = sub(k, reminders);
                    ans += need * f[u][r1] * f[v][r2];
                }
            for(int j = 0; j < k; j++) f[u][j] += f[v][j];
            num[u] += num[v];
            ans += num[v] * (n - num[v]);
        }
    }
    //cout << num[u]<<"??"<<u<<endl;
}

int main()
{
  //  freopen("test.inp", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> k;
    FOR(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    //DEBUG(f[2][0]);
    cout << ans / k;
	return 0;
}
