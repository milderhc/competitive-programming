#include <iostream>

using namespace std;

const int MAXN = 200;
int board[MAXN][MAXN];
int dp[MAXN][MAXN];
int n;

void read ( ) {
    int limit = n/2 +1;

    int i = 0;
    for ( int k = 1; k < limit; i++, k++ )
        for ( int j = 0; j < k; j++ )
            cin >> board[i][j];

    for ( int k = limit; k >= 1; k--, i++ )
        for ( int j = 0; j < k; j++ )
            cin >> board[i][j];
}


int solve ( ) {
    int limit = n/2 + 1;

    dp[0][0] = board[0][0];
    int i = 0;
    for ( int k = 1; k <= limit; k++, i++ )
        for ( int j = 0; j < k; j++ ) {
            if ( j != 0 && j != k - 1 )
                dp[i][j] = max( dp[i - 1][j - 1], dp[i - 1][j] );
            else if ( j == 0 )
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - 1];

            dp[i][j] += board[i][j];
        }

    for ( int k = limit - 1; k >= 1; k--, i++ )
        for ( int j = 0; j < k; j++ )
            dp[i][j] = max( dp[i - 1][j], dp[i - 1][j + 1] ) + board[i][j];

    return dp[n - 1][0];
}

int main ( ) {

    int t;
    cin >> t;

    while ( t-- ) {
        cin >> n;

        read();
        cout << solve() << '\n';
    }
}
