#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, t, p = 0, d = 0;
    cin >> n;
    while ( n-- ) {
          cin >> t;
          if ( t > 0 ) {
               p += t;
               continue;
          }
          if ( p == 0 )
              d++;
          else
              p--;
    }
    cout << d;
}
