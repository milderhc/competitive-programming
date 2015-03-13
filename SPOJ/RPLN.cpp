#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000006;
int a[MAX];

struct node {
	node *left, *right;
	int middle, l, r, value;

	node ( int x, int y ) : l(x), r(y) {
		if ( l != r ) {
			middle = (l + r)/2;
			left = new node(l, middle);
			right = new node(middle + 1, r);
			value = min(left->value, right->value);
		} else
			value = a[l];
	}

	int query ( int x, int y ) {
		if ( x == l && y == r ) return value;
		if ( x > middle ) return right->query(x, y);
		if ( y <= middle ) return left->query(x, y);
		return min( left->query(x, middle), right->query(middle + 1, y) );
	}
};

int main ( ) {
	int T, N, Q, x, A, B;
	scanf("%d", &T);
	for ( int c = 1; c <= T; ++c ) {
		scanf("%d%d", &N, &Q);
		for ( int i = 0; i < N; ++i )
			scanf("%d", &a[i]);

		node tree(0, N - 1);
		printf("Scenario #%d:\n", c);
		while ( Q-- ) {
			scanf("%d%d", &A, &B);
			--A, --B;
			printf("%d\n", tree.query(A, B));
		}
	}
}
