#include <bits/stdc++.h>
#define  INF		1 << 10
#define  w(i, j)	(board[i][j] == '1' ? 1 : -INF)

using namespace std;

const int MAX = 30;
string board[MAX];
int m[MAX][MAX];

int sum ( int a, int b, int c, int d ) {
	int top = (a > 0 ? m[a - 1][d] : 0);
	int left = (b > 0 ? m[c][b - 1] : 0);
	int top_left = (a > 0 && b > 0 ? m[a - 1][b - 1] : 0);
	return m[c][d] - top - left + top_left;
}

int main() {
	int T;
	cin >> T;
	getline(cin, board[0]);
	while ( T-- ) {
		getline(cin, board[0]);
		getline(cin, board[0]);
		for ( int i = 1; i < board[0].size(); ++i )
			getline(cin, board[i]);
		int N = board[0].size();
		m[0][0] = w(0, 0);
		for ( int i = 1; i < N; ++i ) {
			m[0][i] = w(0, i) + m[0][i - 1];
			m[i][0] = w(i, 0) + m[i - 1][0];
		}
		for ( int i = 1; i < N; ++i )
			for ( int j = 1; j < N; ++j )
				m[i][j] = w(i, j) + m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];

		int ans = 0;
		for ( int i = 0; i < N; ++i )
			for ( int j = 0; j < N; ++j )
				for ( int k = i; k < N; ++k )
					for ( int h = j; h < N; ++h )
						ans = max(ans, sum(i, j, k, h));

		cout << ans << '\n';
		if ( T ) cout << '\n';
	}
}
