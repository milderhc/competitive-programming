#include <bits/stdc++.h>

using namespace std;

const int MAX = 30;
int parent[MAX], rank[MAX];

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

void union_set ( int x, int y ) {
    int x_root = find_set(x);
    int y_root = find_set(y);

    if ( rank[x_root] > rank[y_root] )
        parent[y_root] = x_root;
    else {
        parent[x_root] = y_root;
        if ( rank[x_root] == rank[y_root] )
            rank[y_root]++;
    }
}

int components ( int n ) {
    int ans = 0;
    for ( int i = 0; i < n; i++ )
        if ( parent[i] == i ) ans++;

    return ans;
}

int main ( ) {
    int N;

    cin >> N;
    while ( N-- ) {
        char A;
        cin >> A;

        make_set(A - 64);

        string s;
        getline( cin, s );

        while ( getline( cin, s ) ) {
            if ( s == "" ) break;
            union_set( s[0] - 65, s[1] - 65 );
        }

        cout << components(A - 64) << '\n';
        if ( N > 0 ) cout << '\n';
    }

}
