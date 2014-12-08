#include <iostream>

using namespace std;

int T, H, N;

void print ( int n ) {
    for ( int i = N - 1; i >= 0; i-- )
        cout << ( (n & ( 1 << i )) > 0 );
    cout << '\n';
}

void go ( int bits, int pos, int count, int value ) {
    if ( value ) bits |= value << pos;
    
    if ( pos == 0 ) {
        if ( count == H ) 
            print ( bits );
        return;
    }
    
    go ( bits, pos - 1, count, 0 );
    go ( bits, pos - 1, count + 1, 1 );
  
}

int main ( ) {    
    cin >> T;
    while ( T-- ) {
        cin >> N >> H;
        
        int bits = 0;
        go ( bits, N - 1, 0, 0 );
        go ( bits, N - 1, 1, 1 );
        
        if ( T > 0 ) cout << '\n';
    }
    
}
