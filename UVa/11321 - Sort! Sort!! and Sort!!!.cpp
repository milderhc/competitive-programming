#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
 
using namespace std;
 
int N, M;
int v[10005];
 
bool cmp ( int a, int b ) {
    int A = a%M;
    int B = b%M;
    if ( A!=B )
        return A<B;
    if ( (a-b)%2 == 0 ) {
        if ( a%2==0 )
            return a<b;
        else
            return a>b;
    }
    if ( a%2!=0 )
        return true;
    else
        return false;
}
 
int main ( ) {
    while ( scanf( "%d %d", &N, &M ) ) {
        printf( "%d %d\n", N, M );
        if ( !N && !M )
            break;
        for ( int i = 0; i < N; i++ )
            scanf( "%d", &v[i] );
        sort( v, v+N, cmp );
        for ( int i = 0; i < N; i++ )
            printf( "%d\n", v[i] );
    }
}
