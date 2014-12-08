#include <iostream>
#include <cstring>
#define left(x)     x * 2 + 1
#define right(x)     x * 2 + 2

using namespace std;

const int MAX = 524289;
const int SIZE = 1048575;
bool tree[SIZE];
int answers[21][MAX];

int stop_position( int d, int D, int node ) {
    if( d == D )
        return node;

    if( !tree[node] ) {
        tree[node] = true;
        return stop_position( d + 1, D, left(node) );
    }
    tree[node] = false;
    return stop_position( d + 1, D, right(node) );
}

int main() {
    int T, D, I;

    for( int i = 2; i < 21; i++ ) {
        memset( tree, false, sizeof(tree) );
        for( int j = 1; j < MAX; j++ )
            answers[i][j] = stop_position(1, i, 0) + 1;
    }

    cin >> T;
    while( cin >> D >> I ) {
        cout << answers[D][I] << '\n';
    }
}







