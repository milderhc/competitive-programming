#include <iostream>
#include <climits>
#include <cstring>
#include <cmath>
#define  mem(x, n) memset(x, n, sizeof(x))
#define  INF       0x3fffffff

using namespace std;

const int MAX = 105;
int W[MAX][MAX], D[MAX][MAX];

void solve ( int N ) {
    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < N; j++ )
            if ( i != j ) {
                if ( W[i][j] != -1 ) D[i][j] = W[i][j];
                else D[i][j] = INF;
            } else
                D[i][i] = 0;

    for ( int k = 0; k < N; k++ )
        for ( int i = 0; i < N; i++ )
            for ( int j = 0; j < N; j++ )
                D[i][j] = min( D[i][j], D[i][k] + D[k][j] );

    int best = INT_MAX, index;
    bool disjoint = true;
    for ( int i = 0; i < N; i++ ) {
        int best_i = 0;
        bool disjoint_i = false;
        for ( int j = 0; j < N; j++ ) {
            disjoint_i |= D[i][j] == INF;
            best_i = max( best_i, D[i][j] );
        }
        if ( best_i < best ) {
            best = best_i;
            index = i;
        }
        disjoint &= disjoint_i;
    }
    if ( disjoint ) cout << "disjoint\n";
    else cout << index + 1 << ' ' << best << '\n';
}

int main ( ) {
    int N;
    while ( cin >> N && N ) {
        mem(W, -1);
        int c, v, w;
        for ( int u = 0; u < N; u++ ) {
            cin >> c;
            while ( c-- ) {
                cin >> v >> w;
                --v;
                W[u][v] = w;
            }
        }
        solve(N);
    }
}
