#include <iostream>
#include <algorithm>
#define  INF     9999999

using namespace std;

const int MAX = 205;
char board[MAX][MAX];
int dp[MAX][MAX];

int n, m;

void read ( ) {
    char input;
    for ( int i = 0; i < m; i++ )
        for ( int j = 0; j < n; j++ ) {
            cin >> board[i][j];
            dp[i][j] = -INF;
        }
}

int solve ( ) {
    if ( board[0][0] == '#' ) return 0;

    dp[0][0] = ( board[0][0] == 'T' ? 1 : 0 );
    for ( int j = 1; j < n; j++ ) {
        if ( board[0][j] == '#' ) break;
        dp[0][j] = ( board[0][j] == 'T' ? dp[0][j - 1] + 1 : dp[0][j - 1] );
    }

    for ( int i = 1; i < m; i++ ) {
        int change, start;
        if ( i%2 == 0 ) {
            change = 1;
            start = 0;
        } else  {
            change = -1;
            start = n - 1;
        }

        if ( board[i][start] != '#' )
            dp[i][start] = ( board[i][start] == 'T' ? dp[i - 1][start] + 1 : dp[i - 1][start] );

        for ( int j = start + change; j < n && j >= 0; j += change ) {
            if ( board[i][j] == '#' ) {
                dp[i][j] = -INF;
                continue;
            }

            dp[i][j] = max( dp[i - 1][j], dp[i][j - change] );

            if ( board[i][j] == 'T' )
                dp[i][j]++;
        }
    }

    int maximum = 0;
    for ( int i = 0; i < m; i++ )
        maximum = max( maximum, *max_element( dp[i], dp[i] + n ) );

    return maximum;
}

int main ( ) {
    int t;
    cin >> t;
    while ( t-- ) {
        cin >> m >> n;

        read();
        cout << solve() << '\n';
    }
}
