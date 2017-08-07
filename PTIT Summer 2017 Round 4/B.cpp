#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 5000;
typedef pair<int, int> ii;

int D[1000001];
void magic() {
    int K = 19;
    for(int b=0; b<K; b++) {
        int f=0, t=(1<<b);
        for(int g=0; g<(1<<(K-1-b)); f+=(1<<(b+1)), t+=(1<<(b+1)), g++)
            for(int i=0; i<(1<<b); i++)
                D[t|i] += D[f|i];
    }
    //cout << D[199]<<"??"<<endl;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("test.txt", "r", stdin);
    magic();
    return 0;
}
