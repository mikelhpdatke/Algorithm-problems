#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;
typedef pair<int, int> ii;

int n, k;
string s;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("test.txt", "r", stdin);
    cin >> n >> k >> s;
    int min_pal = 0;
    if (k > n){
        cout <<"No";
        return 0;
    }
    if (n % 2 == 1){
        for(int i = 0; i < n / 2; i++)
            if (s[i] != s[n - i - 1]) min_pal++;
        if (k < min_pal) cout <<"No";
        else
            cout <<"Yes";
    }
    else{
        for(int i = 0; i <= n / 2 - 1; i++)
            if (s[i] != s[n - i - 1]) min_pal++;
        if (k < min_pal) cout <<"No";
        else
            if (k % 2 == 1)
                if (min_pal > 0) cout <<"Yes";
                else cout <<"No";
            else cout <<"Yes";
    }
    return 0;
}

