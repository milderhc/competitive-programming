#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> sequence;
bool flag;

void f ( int n, int m ) {
    if ( !flag )
        return;
    if ( n == 1 ) {
        sequence.push_back( 1 );
        return;
    }
    if ( n % m != 0 ) {
        flag = false;
        return;
    }
    sequence.push_back( n );
    f( n/m, m );
}

int main ( ) {
    int n, m;
    while ( cin >> n >> m ) {
           sequence.clear();
           flag = true;
           if ( m < 2 || n < 2 || m > n ) {
               cout << "Boring!" << endl;
               continue;    
           }      
           f( n, m );
           if ( !flag )
               cout << "Boring!" << endl;
           else {
               for ( int i = 0; i < sequence.size(); i++ ) {
                    cout << sequence[i];
                    if ( i < sequence.size()-1 )
                        cout << " ";
               }
               cout << endl;
           }
    }
}
