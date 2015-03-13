#include <bits/stdc++.h>
#define  MAX            100005

using namespace std;

int parent[MAX], rank[MAX], size[MAX];
void make_set ( int n ) {
    for ( int i = 0; i < n; ++i ) {
        parent[i] = i;
        size[i] = 1;
        rank[i] = 0;
    }
}

int find_set ( int x ) {
    if ( parent[x] == x ) return x;
    return parent[x] = find_set(parent[x]);
}

void union_set ( int x, int y ) {
    int x_root = find_set(x);
    int y_root = find_set(y);
    if ( x_root == y_root ) return;
    if ( rank[x_root] < rank[y_root] ) {
        parent[x_root] = y_root;
        size[y_root] += size[x_root];
    } else {
        parent[y_root] = x_root;
        size[x_root] += size[y_root];
        if ( rank[x_root] == rank[y_root] )
            rank[x_root]++;
    }
}

int main ( ) {
    int T, F;
    cin >> T;
    while ( T-- ) {
        cin >> F;
        make_set(F + 1);
        map<string, int> mp;
        int idx = 1;
        string a, b;
        for ( int i = 0; i < F; ++i ) {
            cin >> a >> b;
            int &p = mp[a];
            int &q = mp[b];
            if ( p == 0 ) p = idx++;
            if ( q == 0 ) q = idx++;
            union_set(p, q);
            cout << size[find_set(p)] << '\n';
        }
    }
}
