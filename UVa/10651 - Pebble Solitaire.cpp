#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int solve ( string s ) {
    int ans = 0, temp = 0;
    for ( int i = 0; i < s.size()-1; i++ )
         if ( s[i] == 'o' && s[i+1] == 'o' ) {
             if ( i > 0 && i < s.size()-2 ) {
                 if ( s[i-1] == 'o' && s[i+2] == 'o' )
                     continue;
                 string A, B;
                 A = B = s;
                 int a = 0, b = 0;
                 if ( s[i-1] == '-' ) {
                     A[i-1] = 'o';
                     A[i] = A[i+1] = '-';
                     a = solve( A );
                 }
                 if ( s[i+2] == '-' ) {
                     B[i+2] = 'o';
                     B[i] = B[i+1] = '-';
                     b = solve( B );
                 }
                 temp = 1 + max( a, b );
             } else if ( i > 0 && s[i-1] == '-' ) {
                 string A = s;
                 A[i-1] = 'o';
                 A[i] = A[i+1] = '-'; 
                 temp = 1 + solve( A ); 
             } else if ( i < s.size()-2 && s[i+2] == '-' ) {
                 string B = s;
                 B[i+2] = 'o';
                 B[i] = B[i+1] = '-';
                 temp = 1 + solve( B );
             }
             if ( temp > ans )
                 ans = temp;
         }
    return ans;
}

int count ( string s ) {
    int c = 0;
    for ( int i = 0; i < s.size(); i++ )
         if ( s[i] == 'o' )
             c++;
    return c;
}

int main ( ) {
    int n;
    string s;
    cin >> n;
    while ( n-- ) {
           cin >> s;
           cout << count( s ) - solve( s ) << endl;
    }
}
