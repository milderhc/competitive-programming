#include <bits/stdc++.h>
#define  L(X)   2 * X + 1
#define  R(X)   2 * X + 2

using namespace std;

const int MAX = 100005;
const int MAX_SIZE = 1 << 18;
int X[MAX], tree[MAX_SIZE];

void create_tree ( int node, int i, int j ) {
    if ( i == j ) {
        tree[node] = (X[i] < 0 ? -1 : (X[i] > 0 ? 1 : 0) );
        return;
    }

    int middle = (i + j)/2;
    create_tree( L(node), i, middle );
    create_tree( R(node), middle + 1, j );

    tree[node] = tree[L(node)] * tree[R(node)];
}

int query ( int node, int i, int j, int l, int r ) {
    if ( i == l && j == r )
        return tree[node];

    int middle = (i + j)/2;
    if ( r <= middle )
        return query( L(node), i, middle, l, r );
    else if ( l > middle )
        return query( R(node), middle + 1, j, l, r );

    int left = query( L(node), i, middle, l, middle );
    int right = query( R(node), middle + 1, j, middle + 1, r );

    return left * right;
}

int update ( int node, int i, int j, int x, int value ) {
    if ( i == x && j == x ) {
        X[x] = value;
        return tree[node] = (value < 0 ? -1 : (value > 0 ? 1 : 0) );
    }

    int middle = (i + j)/2;
    int left, right;

    if ( x > middle ) {
        left = tree[L(node)];
        right = update( R(node), middle + 1, j, x, value );
    } else {
        left = update( L(node), i, middle, x, value );
        right = tree[R(node)];
    }

    return tree[node] = left * right;
}

int main ( ) {
    int N, K;
    while ( cin >> N >> K ) {
        for ( int i = 0; i < N; i++ )
            cin >> X[i];

        create_tree( 0, 0, N - 1 );

        char command;
        while ( K-- ) {
            cin >> command;
            if ( command == 'C' ) {
                int I, V;
                cin >> I >> V;
                I--;
                update( 0, 0, N - 1, I, V );
            } else {
                int I, J;
                cin >> I >> J;
                I--, J--;
                int result = query( 0, 0, N - 1, I, J );
                if ( result > 0 ) cout << '+';
                else if ( result < 0 ) cout << '-';
                else cout << '0';
            }
        }

        cout << '\n';
    }
}
