#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000000;
typedef pair<int, int> ii;
int n;
int k;
string s;
map<char, int> M;
int dd[10000];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("test.txt", "r", stdin);
    cin >> n >> k;
    cin >> s;
    cout << s<<"?"<<endl;
    for(int i = 0; i < s.size(); i++){
        M[s[i]]++;
    }
    int cur = k;
    int i = 0;
    //cout << M['A']<<"??"<<endl;
    while (i < s.size()){
        char ch = s[i];
        dd[ch]++;
        if (dd[ch] == 1){
            if (cur == 0){
                cout << "YES";
                return 0;
            }
            cur--;
        }


        if (dd[ch] == M[ch]) cur++;
        i++;
    }
    cout<<"NO";
    return 0;
}

