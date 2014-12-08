#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 1000005;

struct edge {
    int u, v;
    long long w;

    bool operator < ( const edge &other ) const {
        return w < other.w;
    }
} edges[MAX];

int parent[MAX], rank[MAX];

void make_set ( int N ) {
    for ( int i = 0; i < N; i++ ) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_set ( int x ) {
    if ( parent[x] == x ) return x;
    return parent[x] = find_set( parent[x] );
}

bool union_set ( int x, int y ) {
    int x_root = find_set(x);
    int y_root = find_set(y);

    if ( x_root == y_root ) return false;
    if ( rank[x_root] > rank[y_root] )
        parent[y_root] = x_root;
    else {
        parent[x_root] = y_root;
        if ( rank[x_root] == rank[y_root] )
            rank[y_root]++;
    }

    return true;
}

long long kruskal ( int A, int trees ) {
    sort( edges, edges + A );

    long long cost = 0;
    for ( int i = 0; i < A && trees; i++ ) {
        if ( union_set( edges[i].u - 1, edges[i].v - 1 ) ) {
            trees--;
            cost += edges[i].w;
        }
    }

    return cost;
}

int main ( ) {
    int N, M, K;
    bool blank = false;

    while ( cin >> N ) {
        if ( blank ) cout << '\n';
        else         blank = true;

        long long first_cost = 0;
        for ( int i = 0; i < N - 1; i++ ) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            first_cost += edges[i].w;
        }

        cin >> K;
        for ( int i = N - 1; i < N + K - 1; i++ )
            cin >> edges[i].u >> edges[i].v >> edges[i].w;

        cin >> M;
        int a, b, c;
        for ( int i = 0; i < M; i++ )
            cin >> a >> b >> c;

        make_set(N);
        cout << first_cost << '\n' << kruskal(N + K - 1, N) << '\n';
    }
}
