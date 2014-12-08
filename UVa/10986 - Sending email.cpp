#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<pair<int, int> > > graph;
typedef priority_queue<pair<int, int>, vector<pair<int, int> >,
					   greater<pair<int, int> > > min_heap;

vector<int> T, D;
void shortest_path ( graph &G, int node ) {
	T = vector<int>( G.size(), INT_MAX );
	D = vector<int>( G.size(), -1 );

	min_heap Q;
	Q.push( make_pair(0, node) );
	T[node] = 0;

	int count = 0;
	while ( count < G.size() && !Q.empty() ) {
		int u = Q.top().second,
			d = Q.top().first;

		Q.pop();
		if ( D[u] == -1 ) {
			D[u] = d;
			count++;

			for ( int i = 0; i < G[u].size(); i++ ) {
				int v = G[u][i].first,
					w = G[u][i].second;

				if ( T[u] + w < T[v] ) {
					T[v] = T[u] + w;
					Q.push( make_pair(T[v], v) );
				}
			}
		}
	}
}

int main() {
	int N, n, m, S, T;

	cin >> N;
	for ( int i = 1; i <= N; i++ ) {

		cin >> n >> m >> S >> T;
		graph G(n);

		int a, b, c;
		for ( int j = 0; j < m; j++ ) {
			cin >> a >> b >> c;
			G[a].push_back( make_pair(b, c) );
			G[b].push_back( make_pair(a, c) );
		}

		shortest_path(G, S);
		cout << "Case #" << i << ": ";
		if ( D[T] != -1 ) cout << D[T] << '\n';
		else cout << "unreachable" << '\n';
	}
}
