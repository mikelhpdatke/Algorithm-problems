#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;
typedef pair<int, int> ii;

long long X;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("test.txt", "r", stdin);
    cin >> X;
    FOR(i, 1, int (sqrt(X) + 1)){
        long long t1 = 1ll * i * (i + 1) / 2;
        long long t2 = X - t1;
        if (t2 < 1){
            continue;
        }
        long long tmp = t2 * 2;
        long long can = sqrt(tmp);
        if (can * (can + 1) == tmp){
            //cout << t1<<"??"<<t2<<endl;
            cout<<"YES";
            return 0;
        }
    }
    cout <<"NO";
    return 0;
}

