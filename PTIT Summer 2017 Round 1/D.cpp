#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 500;
int m, n;
int a[maxn][maxn], b[maxn][maxn];
typedef pair<char, int> ii;
vector<ii> res;
vector<ii> ans;
bool comp(ii x, ii y)
{
    if (x.first != y.first) return x.first > y.first;
    else return x.second < y.second;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("test.txt", "r", stdin);
    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
    FOR(i, 1, m) FOR(j, 1, n) b[i][j] = a[i][j];

    while (1){
        int mmax = 0, pos = 0;
        FOR(i, 1, m){
            int cur = INF;
            FOR(j, 1, n) cur = min(cur, a[i][j]);
            if (mmax < cur){
                mmax = cur;
                pos = i;
            }
        }
        if (mmax > 0){
            FOR(i, 1, mmax) res.push_back(ii('H', pos));
            FOR(j, 1, n) a[pos][j] -= mmax;
        }
        else{

        int nmax = 0, p = 0;
        FOR(j, 1, n){
            int cur = INF;
            FOR(i, 1, m) cur = min(cur, a[i][j]);
            if (nmax < cur){
                nmax = cur;
                p = j;
            }
        }
        if (nmax > 0){
            FOR(i, 1, nmax) res.push_back(ii('C', p));
            FOR(i, 1, m) a[i][p] -= nmax;
        }
        else break;

        }
    }
    bool ok1 = 1;
    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j] > 0) ok1 = 0;
    ////////////////////
    while (1){
        int nmax = 0, p = 0;
        FOR(j, 1, n){
            int cur = INF;
            FOR(i, 1, m) cur = min(cur, b[i][j]);
            if (nmax < cur){
                nmax = cur;
                p = j;
            }
        }
        if (nmax > 0){
            FOR(i, 1, nmax) ans.push_back(ii('C', p));
            FOR(i, 1, m) b[i][p] -= nmax;
        }
        else{

        int mmax = 0, pos = 0;
        FOR(i, 1, m){
            int cur = INF;
            FOR(j, 1, n) cur = min(cur, b[i][j]);
            if (mmax < cur){
                mmax = cur;
                pos = i;
            }
        }
        if (mmax > 0){
            FOR(i, 1, mmax) ans.push_back(ii('H', pos));
            FOR(j, 1, n) b[pos][j] -= mmax;
        }

        else break;

        }
    }
    bool ok2 = 1;
    FOR(i, 1, m) FOR(j, 1, n) if (b[i][j] > 0) ok2 = 0;

    ///////
    if (ok1 == 0 && ok2 == 0) cout<<-1;
    else{
        if (res.size() < ans.size()){
            cout << res.size() << endl;
            sort(res.begin(), res.end(), comp);
            for(int i = 0; i < res.size(); i++) cout << res[i].first <<" "<<res[i].second << endl;
        }
        else{
            cout << ans.size() << endl;
            sort(ans.begin(), ans.end(), comp);
            for(int i = 0; i < ans.size(); i++) cout << ans[i].first <<" "<<ans[i].second << endl;
        }
    }
    return 0;
}
