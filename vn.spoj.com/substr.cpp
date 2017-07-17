#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

int next[maxn];
string s, x;
int main()
{
	cin >> s >> x;
	s = ' ' + s;
	x = ' ' + x;
	int j = 1, jj = 0;
	next[1] = 0;
	int n = x.size() - 1;
	while (j <= n){
		while (jj > 0 && x[j] != x[jj]) jj = next[jj];
		j++;jj++;
		if (x[j] == x[jj]) next[j] = next[jj]; else next[j] = jj;
	}
	int i;
	i = 1; // s
	j = 1; // x
	while (i <= s.size() - 1){
		while (j > 0 && s[i] != x[j]) j = next[j];
		i++;j++;
		if (j > n){
			printf("%d ", i - j + 1);
			j = next[j];
		}
	}
}
