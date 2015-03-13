#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 205, MAX_C = 25;
int D[MAX_C][MAX_M], K[MAX_C], price[MAX_C][MAX_C];

int main() {
	int N, M, C;
	cin >> N;
	while ( N-- ) {
		cin >> M >> C;
		memset(D, 0, sizeof(D));
		for ( int i = 0; i < C; ++i ) {
			cin >> K[i];
			for ( int j = 0; j < K[i]; ++j )
				cin >> price[i][j];
		}
		for ( int i = 0; i < K[0]; ++i )
			D[0][price[0][i]] = 1;
		for ( int i = 1; i < C; ++i )
			for ( int p = 0; p <= M; ++p ) {
				if ( D[i - 1][p] == 0 ) continue;
				for ( int j = 0; j < K[i]; ++j ) {
					int next_price = p + price[i][j];
					if ( next_price <= M )
						D[i][next_price] = 1;
				}
			}
		int ans = -1;
		for ( int i = 0; i < MAX_M; ++i )
			if ( D[C - 1][i] == 1 && i <= M )
				ans = i;
		if ( ans != -1 ) cout << ans << '\n';
		else 			 cout << "no solution\n";
	}
}
