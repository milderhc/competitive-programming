#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000005;
int a[MAX];

struct node {
	node *left, *right;
	int middle, l, r, value;

	node ( int x, int y ) : l(x), r(y) {
		if ( l != r ) {
			middle = (l + r)/2;
			left = new node(l, middle);
			right = new node(middle + 1, r);
			value = max(left->value, right->value);
		} else
			value = a[l];
	}

	int query ( int x, int y ) {
		if ( x == l && y == r ) return value;
		if ( x > middle ) return right->query(x, y);
		if ( y <= middle ) return left->query(x, y);
		return max(left->query(x, middle), right->query(middle + 1, y));
	}
};

int main ( ) {
	int n, k;
	scanf("%d", &n);
	for ( int i = 0; i < n; ++i )
		scanf("%d", &a[i]);
	scanf("%d", &k);
	node tree(0, n - 1);
	for ( int i = 0, j = k - 1; j < n; ++i, ++j ) {
		if ( i ) cout << ' ';
		cout << tree.query(i, j);
	}
}
