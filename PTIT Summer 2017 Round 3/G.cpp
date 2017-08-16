#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 500000;
typedef pair<int, int> ii;

int n, k;
int a[maxn];
vector<int> v;
vector<ii> L;
int main()
{
    //
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("test.txt", "r", stdin);
    cin >> n >> k;
    int EACH = k;
    FOR(i, 1, n) cin >> a[i];
    //cout<<"??"<<endl;
    int cnt = 0, tmp = 0;
    FOR(i, 1, n) if (a[i] < 0) cnt++;
        else tmp++;

    if (cnt > k){
        cout << -1;
        return 0;
    }

    k -= cnt;
    int ans = 0;
    int i = 1;
    while (i <= n){
        if (a[i] >= 0){
            i++;
            continue;
        }
        int j = i;
        while (j + 1 <= n && a[j + 1] < 0) j++;
        L.push_back(ii(i, j));
        i = j + 1;
    }
    ans = L.size() * 2;
    //cout << L.size()<<"??"<<endl;
    if (L.size() == 0){
        if (tmp <= EACH)
            cout << 0;
        else if (EACH * 2 >= n) cout << 1;
        else cout << -1;
        return 0;
    }
    FOR(i, 1, L.size() - 1) v.push_back(L[i].first - L[i - 1].second - 1);
    sort(v.begin(), v.end());
    //FOR(i, 0, v.size() - 1) cout << v[i]<< " ";cout<<endl;
    //cout << ans<<"??"<<endl;
    //cout <<v.size()<<"??"<<endl;
    int cur = 0;
    while (k > 0){
        if (cur == v.size()) break;
        if (k - v[cur] < 0) break;
        k -= v[cur];
        tmp -= v[cur];
        cur++;
        ans -= 2;
    }
    //cout <<k<<"??"<<ans<<endl;
    int m = L.size() - 1;
    if (L[m].second == n || n - L[m].second <= k){
        ans--;
        tmp -= k - (n - L[m].second);
        k -= n - L[m].second;
    }
    //cout << tmp<< " "<<k<<endl;
    if (tmp - k > EACH) cout<<-1;
    else
        cout << ans;
    return 0;


}
