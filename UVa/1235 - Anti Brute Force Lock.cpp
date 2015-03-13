#include <bits/stdc++.h>
#define  pb		push_back
#define  mp		make_pair

using namespace std;

typedef vector<vector<pair<int, int> > > graph;
const string initial_state = "0000";

int find_w ( const string &a, const string &b ) {
	int w = 0;
	for ( int i = 0; i < 4; ++i )
		w += min( abs(a[i] - b[i]), 10 - abs(a[i] - b[i]) );
	return w;
}

int mst ( graph &G ) {
	priority_queue<pair<int, int> > Q;
	vector<bool> seen(G.size());
	Q.push( mp(0, 0) );
	int c = 0, ans = 0;
	while ( c < G.size() ) {
		int u = Q.top().second,
			w = -Q.top().first;
		Q.pop();
		if ( !seen[u] ) {
			seen[u] = true;
			++c;
			ans += w;
			for ( int i = 0; i < G[u].size(); ++i )
				Q.push( mp(-G[u][i].second, G[u][i].first) );
		}
	}
	return ans;
}

int main ( ) {
	int T, n;
	cin >> T;
	while ( T-- ) {
		cin >> n;
		vector<string> keys(n);
		int initial = 0x7fffffff;
		for ( int i = 0; i < n; ++i ) {
			cin >> keys[i];
			initial = min(initial, find_w(keys[i], initial_state) );
		}

		graph G(n);
		for ( int i = 0; i < n; ++i )
			for ( int j = i + 1; j < n; ++j ) {
				int w = find_w(keys[i], keys[j]);
				G[i].pb( mp(j, w) );
				G[j].pb( mp(i, w) );
			}

		cout << mst(G) + initial << '\n';
	}
}
