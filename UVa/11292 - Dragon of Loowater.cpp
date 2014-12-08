#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 20005;
int heads[MAX];
int knights[MAX];

int main ( ) {
    
    int n, m;
    while ( cin >> n >> m ) {
        if ( !n && !m )
            break;
            
        for ( int i = 0; i < n; i++ )
            cin >> heads[i];
        
        for ( int i = 0; i < m; i++ )
            cin >> knights[i];
            
        if ( m < n ) {
            cout << "Loowater is doomed!\n";
            continue;
        }
         
        sort ( heads, heads + n );
        sort ( knights, knights + m );
        
        int ans = 0, k, i;
        for ( i = 0, k = 0; i < n && k < m; k++ )
            if ( knights[k] >= heads[i] ) {
                ans += knights[k];
                i++;
            }
            
        if ( i == n ) cout << ans << '\n';
        else          cout << "Loowater is doomed!\n";
    }
}