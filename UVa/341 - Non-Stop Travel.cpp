#include <bits/stdc++.h>
#define mp  make_pair
#define pb  push_back
#define mem(x, n) memset(x, n, sizeof(x))

using namespace std;

const int MAX = 15;
int W[MAX][MAX], D[MAX][MAX], P[MAX][MAX];

void floyd_warshall ( int N ) {
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < N; j++ ) {
            if ( i != j ) {
                if ( W[i][j] != -1 ) {
                    D[i][j] = W[i][j];
                    P[i][j] = i;
                } else
                    D[i][j] = INT_MAX/2;
            } else
                D[i][i] = 0;
        }

    for ( int k = 0; k < N; k++ )
        for ( int i = 0; i < N; i++ )
            for ( int j = 0; j < N; j++ )
                if ( D[i][k] + D[k][j] < D[i][j] ) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[k][j];
                }
}

vector<int> find_path ( int from, int to ) {
    vector<int> path;
    path.pb(to + 1);
    while ( P[from][to] != from ) {
        path.pb( P[from][to] + 1 );
        to = P[from][to];
    }
    path.push_back(from + 1);
    return path;
}

int main ( ) {
    int N, cases = 1;
    while ( scanf( "%d", &N ) != EOF && N ) {
        for ( int i = 0; i < N; i++ )
            for ( int j = 0; j < N; j++ )
                W[i][j] = -1;
        int c, v, w;
        for ( int i = 0; i < N; i++ ) {
            scanf( "%d", &c );
            while ( c-- ) {
                scanf( "%d", &v );
                scanf( "%d", &w );
                --v;
                W[i][v] = w;
            }
        }
        floyd_warshall(N);

        int from, to;
        scanf( "%d", &from );
        scanf( "%d", &to );
        --from, --to;
        vector<int> path = find_path( from, to );
        printf( "Case %d: Path =", cases++ );
        for ( int i = path.size() - 1; i >= 0; i-- )
            printf( " %d", path[i] );
        printf( "; %d second delay\n", D[from][to] );
    }
}
