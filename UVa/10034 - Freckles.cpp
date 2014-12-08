#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
pair<double, double> freckles[MAX];
int parent[MAX], rank[MAX];

struct edge {
    int u, v;
    double w;

    edge ( int a, int b, double x ) : u(a), v(b), w(x) { }

    bool operator < ( const edge &other ) const {
        return w < other.w;
    }
};

double dist ( const pair<double, double> &a, const pair<double, double> &b ) {
    double X = a.first - b.first;
    double Y = a.second - b.second;
    return sqrt( X*X + Y*Y );
}

void make_set ( int n ) {
    for ( int i = 0; i < n; i++ ) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find_set ( int x ) {
    if ( parent[x] == x ) return x;
    return parent[x] = find_set( parent[x] );
}

bool union_set( int x, int y ) {
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

double kruskal ( vector<edge> &edges ) {
    sort( edges.begin(), edges.end() );

    double sum = 0;
    int trees = edges.size();

    for ( int i = 0; i < edges.size() && trees > 1; i++ ) {
        if ( union_set( edges[i].u, edges[i].v ) ) {
            trees--;
            sum += edges[i].w;
        }
    }

    return sum;
}

int main ( ) {
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);

    int T, n;

    cin >> T;
    while ( T-- ) {
        cin >> n;

        for ( int i = 0; i < n; i++ )
            cin >> freckles[i].first >> freckles[i].second;

        vector<edge> edges;
        for ( int u = 0; u < n; u++ )
            for ( int v = u + 1; v < n; v++ )
                edges.push_back( edge(u, v, dist(freckles[u], freckles[v]) ) );

        make_set(n);
        cout << kruskal(edges) << '\n';

        if ( T ) cout << '\n';
    }
}
