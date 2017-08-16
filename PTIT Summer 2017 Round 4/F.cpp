#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int x , y , n , d , dx[22] , dy[22] , F[1111][1111] ;

inline int Calc( int x , int y )
{
	if ( x * x + y * y > d * d ) return 1 ;
	if ( F[x+500][y+500] != -1 ) return F[x+500][y+500] ;
	F[x+500][y+500] = 0 ;
	for ( int i = 0 ; i < n ; i ++ )
	if ( Calc( x + dx[i] , y + dy[i] ) == 0 )
		return F[x+500][y+500] = 1 ;
	return 0 ;
}

int main()
{
	cin >> x >> y >> n >> d ;
	for ( int i = 0 ; i < n ; i ++ )
		cin >> dx[i] >> dy[i] ;
	memset( F , -1 , sizeof( F ) ) ;
	bool ret = Calc( x , y ) ;
	if ( ret ) {
		cout << "Com" << endl ;
	} else {
		cout << "Lua" << endl ;
	}
	return 0 ;
}
