#include <bits/stdc++.h>

using namespace std;

vector<int> parent, rank;
void make_set ( int n ) {
    parent = vector<int>(n);
    rank = vector<int>(n);
    for ( int i = 0; i < n; i++ )
        parent[i] = i;
}

int find_set ( int x ) {
    if ( parent[x] == x ) return x;
    return parent[x] = find_set( parent[x] );
}

void union_set ( int x, int y ) {
    int x_root = find_set(x);
    int y_root = find_set(y);

    if ( x_root != y_root ) {
        if ( rank[x_root] > rank[y_root] )
            parent[y_root] = x_root;
        else {
            parent[x_root] = y_root;
            if ( rank[x_root] == rank[y_root] )
                rank[y_root]++;
        }
    }
}

int main ( ) {
    int T;
    cin >> T;

    while ( T-- ) {
        int n;
        cin >> n;
        make_set(n);

        char command;
        int x, y;

        int successful = 0, unsuccessful = 0;
        string line;
        getline(cin, line);
        while ( getline(cin, line) && line != "" ) {
            istringstream iss(line);
            iss >> command >> x >> y;

            if ( command == 'c' )
                union_set(--x, --y);
            else {
                int x_root = find_set(--x);
                int y_root = find_set(--y);
                if ( x_root == y_root ) successful++;
                else unsuccessful++;
            }
        }

        cout << successful << ',' << unsuccessful << '\n';
        if ( T ) cout << '\n';
    }
}
