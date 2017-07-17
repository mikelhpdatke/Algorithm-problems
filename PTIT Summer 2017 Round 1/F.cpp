#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000007

const int maxn = 26;

struct data{
    int arr[26][26];
};

int mul(int a, int b)
{
    return 1ll * (1ll * (a % INF) * (b % INF)) % INF;
}

data nhan(data a, data b)
{
    data c;
    FOR(i, 0, 25) FOR(j, 0, 25) c.arr[i][j] = 0;
    FOR(i, 0, 25)
        FOR(j, 0, 25)
            FOR(k, 0, 25) c.arr[i][j] = (c.arr[i][j] + mul(a.arr[i][k],b.arr[k][j]) ) % INF;
    return c;
}

data power(data a, int n)
{
    if (n == 1) return a;
    data tmp = power(a, n / 2);
    if (n % 2 == 1) return nhan(nhan(tmp, tmp), a);
    else return nhan(tmp, tmp);
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
  //  freopen("test.txt", "r", stdin);
    data a;
    int test;
    FOR(i, 0, 25) FOR(j, 0, 25) cin >> a.arr[i][j];
    cin >> test;
    data ini;
    FOR(i, 0, 25) FOR(j, 0,25) ini.arr[i][j] = 0;
    FOR(i, 0, 25) ini.arr[0][i] = 1;
    data res = nhan(ini, a);


    while (test--){
        char ch;
        int n;
        cin >> ch >> n;
        data x = power(a, n - 1);
        //if (n == 2){
            //FOR(i, 0, 25){
            //    FOR(j,0,25) cout << x.arr[i][j]<<" ";cout<<endl;
           // }
        //}
        data res = nhan(ini, x);
        //cout <<ch<<" "<<n<<endl;
//        if (n == 2){
//            FOR(i, 0, 25){
//                FOR(j,0,25) cout << res.arr[i][j]<<" ";cout<<endl;
//            }
//        }
        cout << res.arr[0][ch -'a'] << endl;
    }

    return 0;
}



