#include <bits/stdc++.h>
#define  INF	10005

using namespace std;

const int MAX = 105;
int m[MAX][MAX];

int sum ( int i, int j, int k, int h ) {
	int n = m[k][h];
	if ( i ) n -= m[i - 1][h];
	if ( j ) n -= m[k][j - 1];
	if ( i && j ) n += m[i - 1][j - 1];
	return n;
}

int main ( ) {
	int N, M;
	while ( cin >> M >> N ) {
		if ( !M && !N ) break;
		for ( int i = 0; i < M; ++i )
			for ( int j = 0; j < N; ++j ) {
				cin >> m[i][j];
				m[i][j] = (m[i][j] ? -INF : 1);
			}
		for ( int j = 1; j < N; ++j )
			m[0][j] += m[0][j - 1];
		for ( int i = 1; i < M; ++i )
			m[i][0] += m[i - 1][0];
		for ( int i = 1; i < M; ++i )
			for ( int j = 1; j < N; ++j )
				m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];

		int ans = 0;
		for ( int i = 0; i < M; ++i )
			for ( int j = 0; j < N; ++j )
				for ( int k = i; k < M; ++k )
					for ( int h = j; h < N; ++h )
						ans = max(ans, sum(i, j, k, h));
		cout << ans << '\n';
	}
}
