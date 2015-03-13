#include <bits/stdc++.h>

using namespace std;

struct tt {
	int h, m, s;
	tt ( int x, int y, int z ) :
		h(x), m(y), s(z) { }

	bool operator < ( const tt &other ) const {
		if ( h != other.h ) return h < other.h;
		if ( m != other.m ) return m < other.m;
		return s < other.s;
	}
};

int main ( ) {
	int N, a, b, c;
	scanf("%d", &N);
	vector<tt> v;
	for ( int i = 0; i < N; ++i ) {
		scanf("%d%d%d", &a, &b, &c);
		v.push_back( tt(a, b, c) );
	}
	sort( v.begin(), v.end() );
	for ( int i = 0; i < N; ++i )
		printf( "%d %d %d\n", v[i].h, v[i].m, v[i].s );
}
