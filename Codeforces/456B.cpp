#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int two[] = {2, 4, 3, 1};
int three[] = {3, 4, 2, 1};
int four[] = {4, 1};

int main() {
     string s;
     int n;
     cin >> s;
     if( s.size() == 1 ) {
         n = s[s.size()-1] - 48;
         if( !n ) {
             cout << 4;
             return 0;    
         }
     } else
         n = atoi( s.substr(s.size()-2, 2).c_str() );
     if( n != 0 )
         n = (n-1)%4;
     else
         n = 3;
     cout << ( 1 + two[n] + three[n] + four[n%2] )%5;      
}
