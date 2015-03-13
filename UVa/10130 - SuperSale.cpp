#include <bits/stdc++.h>
#define MAX_N   1005
#define MAX_W   32

using namespace std;

int P[MAX_N], W[MAX_N], dp[MAX_W];

int main ( ) {
    int T, N, G, MW;
    cin >> T;
    while ( T-- ) {
        cin >> N;
        for ( int i = 0; i < N; i++ )
            cin >> P[i] >> W[i];

        memset( dp, 0, sizeof(dp) );
        for ( int i = 0; i < N; i++ )
            for ( int j = MAX_W; j > 0; j-- )
                if ( j >= W[i] )
                    dp[j] = max( dp[j], dp[j - W[i]] + P[i] );

        cin >> G;
        int ans = 0;
        while ( G-- ) {
            cin >> MW;
            ans += dp[MW];
        }
        cout << ans << '\n';
    }
}
