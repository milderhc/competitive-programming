#include <iostream>
#include <algorithm>
#include <vector>
#define pb  push_back
#define mp  make_pair

using namespace std;

const int MAX = 105;
int parent[MAX], rank[MAX];

struct edge {
    int u, v, w;
    edge ( int a, int b, int c ) :
        u(a), v(b), w(c) { }

    bool operator < ( const edge &other ) const {
        return w < other.w;
    }
};

void make_set ( int n ) {
    for ( int i = 0; i < n; i++ ) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_set ( int x ) {
    if ( parent[x] == x ) return x;
    return parent[x] = find_set(parent[x]);
}

bool union_set ( int x, int y ) {
    int x_root = find_set(x),
        y_root = find_set(y);

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

int kruskal ( vector<edge> &edges, int trees ) {
    sort( edges.begin(), edges.end() );
    int ans = 0;
    for ( int i = 0; i < edges.size() && trees > 1; i++ )
        if ( union_set( edges[i].u, edges[i].v ) ) {
            ans += edges[i].w;
            trees--;
        }
    return ans;
}

int main ( ) {
    int N;
    while ( cin >> N ) {
        make_set(N);
        vector<edge> edges;

        int w;
        for ( int u = 0; u < N; u++ )
            for ( int v = 0; v < N; v++ ) {
                cin >> w;
                if ( u > v )
                    edges.pb( edge(u, v, w) );
            }
        cout << kruskal(edges, N) << '\n';
    }
}
