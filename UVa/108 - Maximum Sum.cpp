#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
int board[MAX][MAX];

int sum ( int a, int b, int c, int d ) {
	int top = (a > 0 ? board[a - 1][d] : 0);
	int left = (b > 0 ? board[c][b - 1] : 0);
	int top_left = (a > 0 && b > 0 ? board[a - 1][b - 1] : 0);
	return board[c][d] - top - left + top_left;
}

int main ( ) {
	int N;
	cin >> N;
	for ( int i = 0; i < N; ++i )
		for ( int j = 0; j < N; ++j )
			cin >> board[i][j];
	for ( int i = 1; i < N; ++i ) {
		board[0][i] += board[0][i - 1];
		board[i][0] += board[i - 1][0];
	}
	for ( int i = 1; i < N; ++i )
		for ( int j = 1; j < N; ++j )
			board[i][j] += board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1];

	int ans = board[0][0];
	for ( int i = 0; i < N; ++i )
		for ( int j = 0; j < N; ++j )
			for ( int k = i; k < N; ++k )
				for ( int h = j; h < N; ++h )
					ans = max(ans, sum(i, j, k, h));
	cout << ans << '\n';
}
