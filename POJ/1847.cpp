#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define pb push_back
#define mp make_pair

using namespace std;

const int MAX = 105;
vector<pair<int, int> > G[MAX];

vector<int> D, S;
bool dijkstra ( int N, int node ) {
    D = vector<int>( N, -1 );
    S = vector<int>( N, INT_MAX );
    S[node] = 0;

    priority_queue<pair<int, int> > Q;
    Q.push( mp(0, node) );

    int p = 0;
    while ( p < N ) {
        int u = Q.top().second,
            d = -Q.top().first;

        Q.pop();
        if ( D[u] == -1 ) {
            D[u] = d;
            p++;

            for ( int i = 0; i < G[u].size(); i++ ) {
                int v = G[u][i].first,
                    w = G[u][i].second;
                if ( d + w < S[v] ) {
                    S[v] = d + w;
                    Q.push( mp(-S[v], v) );
                }
            }
        }
        if ( p < N && Q.empty() )
            return false;
    }
    return true;
}

int main ( ) {
    int N, A, B, v, c;
    cin >> N >> A >> B;
    --A, --B;
    for ( int i = 0; i < N; i++ ) {
        cin >> c;
        for ( int j = 0; j < c; j++ ) {
            cin >> v;
            --v;
            G[i].pb( mp(v, j > 0) );
        }
    }
    if ( dijkstra(N, A) )
        cout << D[B];
    else
        cout << -1;
}
