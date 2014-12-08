#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 10;
int mass[MAX];

int main() {
    int C, S, cases = 1;

    while( scanf( "%d", &C ) != EOF ) {
        scanf( "%d", &S );
        double sum = 0, imbalance = 0;
        for( int i = 0; i < S; i++ ) {
            scanf( "%d", &mass[i] );
            sum += mass[i];
        }

        for( int i = S; i < 2 * C; i++ )
            mass[i] = 0;

        sort( mass, mass + 2 * C );

        sum /= C;
        printf( "Set #%d\n", cases++ );
        for( int i = 0; i < C; i++ ) {
            printf( " %d:", i );
            if( mass[i] ) printf( " %d", mass[i] );
            if( mass[2 * C - i - 1] ) printf( " %d", mass[2 * C - i - 1] );
            printf( "\n" );
            imbalance += abs(sum - (mass[i] + mass[2 * C - i - 1]) );
        }
        printf( "IMBALANCE = %.5lf\n\n", imbalance );
    }

}







