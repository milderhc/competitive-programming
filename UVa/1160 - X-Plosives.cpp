#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll, ll> parent;
int find_set ( ll x ) {
	ll &px = parent[x];
	if ( px == 0 ) { px = x; return x; }
	if ( px == x ) return x;
	return px = find_set(px);
}

bool union_set ( ll x, ll y ) {
	ll x_root = find_set(x);
	ll y_root = find_set(y);
	if ( x_root == y_root ) return 1;
	parent[x_root] = y_root;
	return 0;
}

int main() {
	string line;
	ll ans = 0, a, b;
	while ( cin >> a ) {
		if ( a == -1 ) {
			cout << ans << '\n';
			parent.clear();
			ans = 0;
			continue;
		}
		cin >> b;
		++a, ++b;
		ans += union_set(a, b);
	}
}
