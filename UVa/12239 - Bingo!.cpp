#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <set>
#include <cstring>
 
using namespace std;
 
int v[95];
bool f[95];
 
int main()
{
    int N, B, b;
    while( true )
    {
        scanf( "%d", &N );
        scanf( "%d", &B );
        if( !N && !B ) 
            break;
        memset( f, false, sizeof(f) );
        bool zero = false, max = false;
        for( int i=0; i<B; i++ )
        {
            scanf( "%d", &v[i] );
            f[ v[i] ] = true;
            if( v[i] == 0 )
                zero = true;
            else if( v[i] == N )
                max = true;         
        }
        if( !zero || !max )
        {
            printf( "N\n" );
            continue;
        }
        for( int i=0; i<B; i++ )
            for( int j=i+1; j<B; j++ )
                f[ abs(v[i]-v[j]) ] = true;
         
        bool flag = true;       
        for( int i=0; i<N; i++ )
            if( !f[i] )
            {
                flag = false;
                printf( "N\n" );
                break;
            }
         
        if( flag )
            printf( "Y\n" );
    }
     
}
