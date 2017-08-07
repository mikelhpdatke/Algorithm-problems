#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 500000;
typedef pair<int, int> ii;

int n;
string s;
int dd[2][2];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("test.txt", "r", stdin);

    cin >> n >> s;
    int ans = INF;
    dd[0][0] = 'b';
    dd[0][1] = 'r';
    dd[1][0] = 'r';
    dd[1][1] = 'b';

    int x = 0, y = 0;
    FOR(lo, 0, 1){
        x = 0, y = 0;
        for(int i = 0; i < n; i++){
            int cur = s[i];
            int pat = dd[lo][i % 2];
            if (cur != pat){
                if (pat == 'b') x++;
                    else y++;
            }
        }
        ans = min(ans, min(x, y) + abs(x - y));
    }
    cout << ans;
    return 0;
}

