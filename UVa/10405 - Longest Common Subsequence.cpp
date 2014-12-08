#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

const int MAX = 1005;
int dp[MAX][MAX];

int LCS ( string a, string b ) {
    int n = a.size(),
        m = b.size();
    
    memset( dp, 0, sizeof(dp) );
    for ( int i = 1; i <= n; i++ )
         for ( int j = 1; j <= m; j++ ) {
              if ( a[i-1] != b[j-1] )
                  dp[i][j] = max( dp[i][j-1], dp[i-1][j] );    
              else
                  dp[i][j] = dp[i-1][j-1] + 1;    
         } 
    return dp[n][m];
}

int main ( ) {
    string a, b;
    while ( getline(cin, a) && getline(cin, b) )
        cout << LCS(a, b) << endl;  
}
