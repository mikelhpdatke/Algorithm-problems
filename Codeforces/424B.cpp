#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

string s1, s2;
string s;
map<char, char> M;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
   // freopen("input.txt", "r", stdin);
    cin >> s1 >> s2;
    //cout <<s1<<" "<<s2<<endl;
    cin >> s;
    for(int i = 0; i < s1.size(); i++) M[tolower(s1[i])] = tolower(s2[i]);
    M['1'] = '1';
M['2'] = '2';
M['3'] = '3';
M['4'] = '4';
M['5'] = '5';
M['6'] = '6';
M['7'] = '7';
M['8'] = '8';
M['9'] = '9';
M['0'] = '0';

    string res ="";
    for(int i = 0; i < s.size(); i++){
        res += M[tolower(s[i])];
        //cout << s[i]<<" "<<M[tolower(s[i])]<<endl;
        if ('A' <= s[i] && s[i] <= 'Z') res[res.size() - 1] = toupper(res[res.size() - 1]);
    }
    cout << res;
    return 0;
}
