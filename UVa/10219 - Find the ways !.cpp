#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int count ( double a, double b ) {
    double ans = 0;
    while ( b )
           ans += log10( (a--)/(b--) );       
    return int(ans) + 1;  
}

int main ( ) {
    double n, m;
    while ( cin >> n >> m ) {
           if ( n == m ) {
               cout << 1 << endl;
               continue;    
           }
           cout << count( n, min(m, n-m) ) << endl;       
    }
}

