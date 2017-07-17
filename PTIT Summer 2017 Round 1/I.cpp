#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;

string s;
map<char, int> M;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
   // freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--){
        cin >> s;
        M.clear();
        for(int i = 0; i < s.size(); i++) M[s[i]]++;
        int old = 0;
        for(map<char, int> :: iterator it = M.begin(); it != M.end(); it++){
            if ((it -> second) % 2 == 1) old++;
            //cout << (it -> second) << endl;
        }
        if (old >=4) cout<<"NO"<<endl;
        else cout <<"YES"<<endl;
    }
    return 0;
}
