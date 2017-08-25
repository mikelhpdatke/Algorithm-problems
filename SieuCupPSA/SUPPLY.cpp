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
const int maxn = 200101;

int n, m;
double w;
struct data{
    int id;
    int x, y, w;
    bool operator< (const data & op) const{
        return w < op.w;
    }
};

vector< data > adj[maxn];
pair<int, int> a[maxn];
double dis[2001][2001];
double kc(int a, int b, int x, int y)
{
    return sqrt(1ll * (a - x) * (a - x) + 1ll * (b - y) * (b - y));
}

priority_queue< data, vector<data > > q;
double d[maxn];
int main()
{
    freopen("SUPPLY.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> w;
    FOR(i, 1, n) cin >> a[i].first >> a[i].second;

    FOR(i, 1, n) FOR(j, i + 1, n){
        dis[i][j] = kc(a[i].first, a[i].second, a[j].first, a[j].second);
        if (dis[i][j] > w) dis[i][j] = 123456789123456789LL;
        dis[j][i] = dis[i][j];
    }
    FOR(i, 1, m){
        int x, y;
        cin >> x >> y;
        dis[x][y] = 0;
        dis[y][x] = 0;
    }

    d[1] = 0;
    //cout << dis[1][4]<<"?"<<endl;
    FOR(u, 2, n) d[u] = 123456789123456789LL;
    q.push((data){1, a[1].first, a[1].second, 0});
    while (q.size()){
        int u = q.top().id;
        int x = q.top().x;
        int y = q.top().y;
        int w = q.top().w;
        q.pop();
        //cout <<u<<" "<<endl;
        if (d[u] < w) continue;
        FOR(v, 1, n){
            //cout << d[v]<<" "<<d[u]<<" "<<dis[u][v]<<"??"<<endl;
            if (d[v] > d[u] + dis[u][v]){
                d[v] = d[u] + dis[u][v];
                q.push((data){v, a[v].first, a[v].second, d[v]});
            }
        }
    }
    //cout << d[2]<<endl;
    cout << (d[n] == 123456789123456789LL ? -1 : int(d[n] * 1000ll));
    return 0;
}
