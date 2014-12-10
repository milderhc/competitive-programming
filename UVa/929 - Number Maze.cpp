#include <bits/stdc++.h>
#define mp  make_pair
#define pb  push_back

using namespace std;

const int MAX = 1005;
int board[MAX][MAX];

typedef vector<vector<pair<int, int> > > graph;
typedef priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >,
                       greater<pair<int, pair<int, int> > > > min_heap;

int N, M;
vector<int> D, S;
void relax ( int u, int v, int i, int j, min_heap &Q ) {
    int w = board[i][j];
    if ( S[u] + w < S[v] ) {
        S[v] = S[u] + w;
        Q.push( mp( S[v], mp(i, j) ) );
    }
}

void dijkstra ( ) {
    int nodes = N * M;
    S = vector<int>( nodes, INT_MAX );
    D = vector<int>( nodes, -1 );

    min_heap Q;
    Q.push( mp(0, mp(0, 0) ) );
    S[0] = 0;

    int p = 0;

    while ( p < nodes ) {
        int i = Q.top().second.first,
            j = Q.top().second.second;
        int d = Q.top().first,
            u = i*M + j;

        Q.pop();
        if ( D[u] == -1 ) {
            D[u] = d;
            p++;

            if ( i > 0 ) relax(u, u - M, i - 1, j, Q);
            if ( j > 0 ) relax(u, u - 1, i, j - 1, Q);
            if ( i < N - 1 ) relax(u, u + M, i + 1, j, Q);
            if ( j < M - 1 ) relax(u, u + 1, i, j + 1, Q);
        }
    }
}

int main ( ) {
    int T;

    cin >> T;
    while ( T-- ) {
        cin >> N >> M;

        for ( int i = 0; i < N; i++ )
            for ( int j = 0; j < M; j++ )
                cin >> board[i][j];

        dijkstra();
        cout << D.back() + board[0][0] << '\n';
    }
}
