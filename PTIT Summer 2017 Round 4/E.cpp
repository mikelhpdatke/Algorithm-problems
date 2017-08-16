#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 1000100;
typedef pair<int, int> ii;

int n, k;
string s;
int dd[30];
int diff = 0;
int last = 0;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("test.txt", "r", stdin);
    cin >> n >> k;
    if (n < k || (n > k && k == 1)){
        cout << -1;
        return 0;
    }

    last = 0;
    s = 'a';
    diff = 1;
    dd[s[0]]++;
    int lo = 0;
    while (lo < n - 1){
        char cur = '?';
        for(int i = 0; i < k; i++){
            char ch = i + 'a';
            if (ch != s[lo]){
                cur = ch;
                break;
            }
        }
        if (cur == '?') break;

        int check = 0;
        if (dd[cur] == 0) check = 1;
        if (n - i - 1 >= k - diff - check){
            dd[cur]++;
            if (dd[cur] == 1) diff++, last++;
            s[++lo] = cur;
        }
        else{
            cur = ++last + 'a';
            s[++lo] = cur;
            dd[cur]++;
            if (dd[cur] == 1) diff++;
        }
        if (last > k) {
            cout << -1;
            return 0;
        }
    }

    if (s.size() < n){
        cout << -1;
        return 0;
    }
    cout << s;
    return 0;
}

