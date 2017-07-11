#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const int maxn = 3 * 1e6 + 10;
const int base = 1e6;
const int mm = 3 * 1e6 + 10;
int n, a[maxn];
int c[maxn];
pair<int, int> b[maxn];

typedef pair<long long, long long> LL;

LL T_gr[maxn];
LL T_lo[maxn];
long long M[maxn];
int encode[maxn];

void update_gr(int x, int value)
{
    for(;x > 0; x -= x & -x) T_gr[x].first++, T_gr[x].second += value;
}

LL get_gr(int x)
{
    LL ans = LL(0, 0);
    for(;x < mm; x += x & -x) ans.first += T_gr[x].first, ans.second += T_gr[x].second;
    return ans;
}


void rm_gr(int x, int value)
{
    for(; x > 0; x -= x & -x) T_gr[x].first--, T_gr[x].second -= value;
}

// second TREE

void update_lo(int x, int value)
{
    for(;x < mm; x += x & -x){
        T_lo[x].first++, T_lo[x].second += value;
        //cout <<x<<"??"<<endl;
    }
}

LL get_lo(int x)
{
    LL ans = LL(0, 0);
    for(;x > 0; x -= x & -x) ans.first += T_lo[x].first, ans.second += T_lo[x].second;
    return ans;
}


void rm_lo(int x, int value)
{
    for(; x < mm; x += x & -x) T_lo[x].first--, T_lo[x].second -= value;
}

long long vitri = INF;
int top = 0;
long long ans = 1234567891234567891LL;
long long val, res;

int main()
{
    scanf("%d", &n);
    FOR(i, 1, n){
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }

    // init treee

    FOR(i, 0, mm - 1){
        T_gr[i].first = T_gr[i].second = 0;
        T_lo[i].first = T_lo[i].second = 0;
    }
    //

    FOR(i, 1, n + n) b[++top].first = i + 1 - a[i], b[top].second = i;
    FOR(i, 1, n) b[++top].first = i, b[top].second = n + n + i;
    //FOR(i, 1, n) cout << b[i].first<<" ";cout << endl;

    sort(b + 1, b + top + 1);
    FOR(i, 1, top){
        int j = b[i].second;
        if (j <= n + n)
        {
            c[j] = lower_bound(b + 1, b + top + 1, pair<int,int>(j + 1 - a[j], 0) ) - b;
            encode[base + j + 1 - a[j]] = c[j];
            M[c[j]] = j + 1 - a[j];
        }
        else
        {
            c[j] = lower_bound(b + 1, b + top + 1, pair<int,int>(b[i].first, 0)) - b;
            encode[base + b[i].first] = c[j];
            M[c[j]] = b[i].first;

        }
    }

    FOR(i, n + 1, n + n - 1){
        update_gr(encode[base + i + 1 - a[i]], M[encode[base + i + 1 - a[i]]]);
        update_lo(encode[base + i + 1 - a[i]], M[encode[base + i + 1 - a[i]]]);
    }
    //cout <<"wtf"<<endl;
    FORD(i, n, 1){
        val = i + 1 - a[i];

        update_gr(encode[base + val], M[encode[base + val]]);
        update_lo(encode[base + val], M[encode[base + val]]);

        LL cur = get_gr(encode[base + i]);

        res = cur.second - 1ll * i * cur.first;


        cur = get_lo(encode[base + i] - 1);

        res = res + i * cur.first * 1ll - cur.second;

        if (res < ans){
            ans = res;
            vitri = n - i + 1;
        }

        int last = i + n - 1;

        rm_gr(encode[base + last + 1 - a[last]], M[encode[base + last + 1 - a[last]]]);
        rm_lo(encode[base + last + 1 - a[last]], M[encode[base + last + 1 - a[last]]]);
        }

    if (vitri == n) vitri = 0;
    //cout <<ans<< " "<<vitri;
    printf("%I64d %I64d", ans, vitri);
    return 0;
}
