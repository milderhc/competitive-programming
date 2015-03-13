#include <bits/stdc++.h>

using namespace std;

const int MAX = 2005;
int dp[MAX][MAX], a[MAX], b[MAX];

int LCS ( int n, int m ) {
    for ( int i = 0; i <= n; i++ ) dp[i][0] = 0;
    for ( int i = 0; i <= m; i++ ) dp[0][i] = 0;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            if ( a[i - 1] != b[j - 1] )
                dp[i][j] = max( dp[i][j - 1], dp[i - 1][j] );
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;

    return dp[n][m];
}

int main ( ) {
    int d;
    cin >> d;
    while ( d-- ) {
        int n = 0, ans = 0;
        while ( cin >> a[n] && a[n] != 0 ) n++;
        while ( cin >> b[0] && b[0] != 0 ) {
            int m = 1;
            while ( cin >> b[m] && b[m] != 0 ) m++;
            ans = max( ans, LCS(n, m) );
        }
        cout << ans << '\n';
    }
}

