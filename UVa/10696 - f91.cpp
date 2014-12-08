#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1000000;
int m[MAX+5];

int f91 ( int N ) {
    if ( m[N] )
        return m[N];
    if ( N > 100 )
        return N - 10;
    m[N] = f91( f91( N + 11 ) );
    return m[N];
}

int main ( ) {
    int N;
    memset( m, 0, sizeof(m) );
    while ( scanf( "%d", &N ) ) {
           if ( N == 0 )
               break;
           printf( "f91(%d) = %d\n", N, f91( N ) );
    }
}
