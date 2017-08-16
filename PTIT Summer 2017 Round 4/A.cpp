#include <stdio.h>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define INF 1000000000 + 7

const long long maxn = 8001;
typedef pair<int, int> ii;

int n, q;
int a[maxn];
int f[maxn][maxn];
int b[maxn + 10], m = 0;
map< int, int  > M;
int df[maxn];
int dd[maxn][maxn];
vector< int > V[maxn];
vector< int> Vi;
vector< int > L;

bool cmp(int x, int y)
{
    return V[x].size() < V[y].size();
}
int main()
{
    //ios::sync_with_stdio(0);cin.tie(0);
    freopen("test.txt", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &n, &q);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, 1, n) b[i] = a[i];
    sort(b + 1, b + n + 1);
    FOR(i, 1, n){
        int cur = lower_bound(b + 1, b + n + 1, a[i]) - b;
        M[a[i]] = cur;
    }
    //cout <<n<<" "<<q<<endl;
    FOR(i, 1, n) a[i] = M[a[i]];
    FOR(i, 1, n) V[a[i]].push_back(i);
    for(map<int, int> :: iterator it = M.begin(); it != M.end(); it++)
        L.push_back(it -> second);
    sort(L.begin(), L.end(), cmp);
    //for(int i = 0; i < L.size(); i++) cout << L[i]<<" ";cout<<endl;
    //cout << V[1][0]<<"//////////??"<<endl;
    for(int i = 0; i < L.size(); i++){
        int c1 = L[i];
        //cout << V[c1].size()<<"????"<<endl;
        Vi.clear();
        Vi.push_back(0);
        for(int j = 0; j < V[c1].size(); j++) Vi.push_back(V[c1][j]);
        Vi.push_back(n + 1);
        df[c1] = 0;
        for(int j = 0; j < Vi.size() - 1; j++){
            int tmp = Vi[j + 1] - Vi[j] - 1;
            df[c1] += tmp * (tmp - 1) / 2 + tmp;
        }
        //cout <<i<<" "<<L.size()<<"?"<<endl;
        for(int j = i + 1; j < L.size(); j++){
            int c2 = L[j];
            Vi.clear();
            Vi.push_back(0);
            int ii = 0, jj = 0;
            while (ii < V[c1].size() || jj < V[c2].size()){
                if (ii < V[c1].size() && jj < V[c2].size()){
                    if (V[c1][ii] < V[c2][jj]) Vi.push_back(V[c1][ii++]);
                        else Vi.push_back(V[c2][jj++]);
                }
                else
                    if (ii == V[c1].size()) Vi.push_back(V[c2][jj++]);
                    else
                    if (jj == V[c2].size()) Vi.push_back(V[c1][ii++]);
            }
            Vi.push_back(n + 1);
            //cout << c1<<" "<<c2<<"??"<<endl;
            //cout << V[c1].size() <<"== "<<V[c2].size()<<endl;
            //if (c1 == 1 && c2 == 3){
            //    for(int i = 0; i < Vi.size(); i++) cout << Vi[i]<<" ";cout << endl;
            //}
            for(int k = 0; k < Vi.size() - 1; k++){
                int tmp = max(0, Vi[k + 1] - Vi[k] - 1);
                //if (c1 == 1 && c2 == 3) cout << tmp<<"????"<<endl;
                f[c1][c2] += tmp * (tmp - 1) / 2 + tmp;
            }
            //if (c1 == 1 && c2 == 3) cout << f[c1][c2]<<"??"<<endl;
            //cout <<c1<<" "<<c2<<"?"<<endl;
            for(int len = 1; len <= min(V[c1].size(), V[c2].size() ); len++){
                //if (c1 == 1 && c2 == 5) cout << len<<"??"<<endl;
                int s2 = 0, f2 = len - 1;
                int s1 = 0, f1 = len - 1;
                int L1 = V[c1][s1], R1 = (f1 == V[c1].size() - 1 ? n + 1 : V[c1][f1 + 1]);
                int L2 = V[c2][s2], R2 = (f2 == V[c2].size() - 1 ? n + 1 : V[c2][f2 + 1]);
                //f[c1][c2] += min(L1, L2);
                int res1 = min(L1, L2), res2;
                res2 = max(0, min(R1, R2) - max(V[c1][f1], V[c2][f2]) );
                f[c1][c2] += res1 * res2;
                /////////
               // if (c1 == 8 && c2 == 3)
                 //   if (len == 1) cout <<f[c1][c2]<<"??"<<res1<<" "<<res2<<endl;
                while (f2 < V[c2].size()){
                    if (V[c1][s1] < V[c2][s2]){
                        if (f1 == V[c1].size() - 1) break;
                        else s1++,f1++;
                    }
                    else if (f2 == V[c2].size() - 1) break;
                        else s2++, f2++;
                    //if (len == 1 && c1 == 1 && c2 == 3) cout << s1<<" "<<f1<<"::"<<s2<< " "<<f2<<endl;
                    int L1 = (s1 == 0 ? 0 : V[c1][s1 - 1]);
                    int L2 = (s2 == 0 ? 0 : V[c2][s2 - 1]);

                    int R1 = (f1 == V[c1].size() - 1 ? n + 1 : V[c1][f1 + 1]);
                    int R2 = (f2 == V[c2].size() - 1 ? n + 1 : V[c2][f2 + 1]);

                    int res1 = max(0, min(V[c1][s1], V[c2][s2]) - max(L1, L2) );
                    res2 = max(0, min(R1, R2) - max(V[c1][f1], V[c2][f2]) );
                    ////cout << len<<" "<<c1<<" "<<c2<<endl;
                    //if (len == 1 && c1 == 1 && c2 == 3)cout <<res1<<"? "<<res2<<endl;
                    f[c1][c2] += res1 * res2;
                    //if (len == 2 && c1 ==1 && c2 == 3) cout << f[c1][c2]<<"??"<<endl;
                }

            }
            f[c2][c1] = f[c1][c2];
        }
    }
    while (q--){
        int x, y;
        scanf("%d%d", &x, &y);
        int dx = M[x], dy = M[y];
        //cout <<dx<<" "<<dy<<endl;
        //cout <<df[dx]<<"??"<<endl;
        //if (x == 6 && y == 2) cout << dx<<" "<<dy<<endl;
        if (dx == dy) printf("%d\n", n * (n - 1) / 2 + n);
        else
            if (dx == 0) printf("%d\n", df[dy]);
            else if (dy == 0) printf("%d\n", df[dx]);
            else

                printf("%d\n", f[M[x]][M[y]]);
       // cout << x<<":"<<M[x]<<" "<<y<<":"<<M[y]<<endl;

        // void trau

//        int ans = 0;
//        FOR(i, 1, n){
//            int dx = 0;
//            int dy = 0;
//            FOR(j, i, n){
//                if (a[j] == x) dx++;
//                if (a[j] == y) dy++;
//                if (dy == dx){
//                    ans++;
//                }
//            }
//        }
//        cout << ans << endl;


        //
    }

    return 0;
}
