#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > graph;

int solve ( graph &G, int x, int y ) {
	vector<int> dist(20, -1);
	queue<int> Q;
	Q.push(x);

	dist[x] = 0;
	while ( !Q.empty() ) {
		int current = Q.front();
		Q.pop();

		for ( int i = 0; i < G[current].size(); i++ ) {
			int nb = G[current][i];

			if ( dist[nb] == -1 ) {
				dist[nb] = dist[current] + 1;

				if ( nb == y )
					return dist[nb];
				Q.push(nb);
			}
		}
	}
}

void print ( int ans, int x, int y ) {
	if ( x < 10 ) cout << ' ';
	cout << x << " to ";
	if ( y < 10 ) cout << ' ';
	cout << y << ": " << ans << '\n';
}

int main() {
	int X, count = 1;

	while ( cin >> X ) {
		graph G(20);

		int J;
		for ( int i = 0; i < X; i++ ) {
			cin >> J;
			--J;
			G[0].push_back(J);
			G[J].push_back(0);
		}

		for ( int i = 1; i < 19; i++ ) {
			cin >> X;
			for ( int j = 0; j < X; j++ ) {
				cin >> J;
				--J;
				G[i].push_back(J);
				G[J].push_back(i);
			}
		}

		int N, x, y;
		cin >> N;

		cout << "Test Set #" << count++ << '\n';
		for ( int i = 0; i < N; i++ ) {
			cin >> x >> y;
			--x, --y;
			int ans = solve(G, x, y);
			print( ans, x + 1, y + 1 );
		}
		cout << '\n';
	}

}
