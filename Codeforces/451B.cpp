#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100005;
int a[MAX];
int b[MAX];

int main() {
    int n;
    cin >> n;
    for( int i=0; i<n; i++ ) {
         cin >> a[i];
         b[i] = a[i];
    }
    sort( a, a+n );
    int start = 0, end = 0;
    for( int i=0; i<n; i++ )
         if( a[i] != b[i] ) {
             start = i;
             break;    
         }
    for( int i=n-1; i>=0; i-- )
         if( a[i] != b[i] ) {
             end = i;
             break;    
         }
    for( int i=start, j=end; i<=end; i++, j-- )
         if( a[i] != b[j] ) {
             cout << "no";
             return 0;
         }      
    cout << "yes" << endl << start + 1 << " " << end + 1;              
}