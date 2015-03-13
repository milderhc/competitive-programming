#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ans[11];

struct point {
    int x, y, z;
    point ( int a, int b, int c ) : x(a), y(b), z(c) {}
};

int sqr ( int x ) { return x * x; }
int dist ( point &a, point &b ) {
    return sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z);
}

int main ( ) {
    int x, y, z;
	memset(ans, 0, sizeof(ans));
	vector<point> p;
	while ( scanf("%d%d%d", &x, &y, &z) ) {
        if ( !x && !y && !z ) break;
        p.push_back( point(x, y, z) );
	}
	for ( int i = 0; i < p.size(); ++i ) {
        int m = INT_MAX;
        for ( int j = 0; j < p.size(); ++j )
            if ( i != j )
                m = min(m, dist(p[i], p[j]));
        m = sqrt(m);
        if ( m < 10 ) ++ans[m];
	}
	for ( int i = 0; i < 10; ++i )
        printf("%4d", ans[i]);
    printf("\n");
}
