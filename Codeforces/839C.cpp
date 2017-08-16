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
const int maxn = 100101;

int n;
vector< int > adj[maxn];
double Ways[maxn];
bool Selected[maxn];
void dfs(int u)
{
    Selected[u] = 1;
    Ways[u] = 0;
    int num = 0;
    int check = 0;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if (!Selected[v]){
            check = 1;
            dfs(v);
            num++;
            //Sum[u] += Sum[v] + Ways[v];
            Ways[u] += Ways[v];
        }
    }
    if (check == 0) Ways[u] = 0;
        else Ways[u] = Ways[u] / num + 1;
}

int main()
{
    freopen("test.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(9);
    cin >> n;
    FOR(i, 1, n - 1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Ways[1] = 0;
    //Sum[1] = 0;
    dfs(1);
    cout << Ways[1] << endl;
    return 0;
}
