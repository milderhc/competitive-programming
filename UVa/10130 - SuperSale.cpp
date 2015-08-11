#include <bits/stdc++.h>
#define INF         0x3fffffff
#define pb          push_back
#define mp          make_pair
#define MAXN        1002
#define MAXW        32

using namespace std;

int P[MAXN], W[MAXN], dp[MAXW];

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string line;

    int T, MW, G, N;
    cin >> T;
    while ( T-- ) {
        cin >> N;
        for ( int i = 0; i < N; ++i )
            cin >> P[i] >> W[i];

        memset(dp, 0, sizeof dp);
        for ( int i = 0; i < N; ++i )
            for ( int j = MAXW; j >= W[i]; --j )
                dp[j] = max(dp[j], dp[j - W[i]] + P[i]);

        int ans = 0;

        cin >> G;
        while ( G-- ) {
            cin >> MW;
            ans += dp[MW];
        }

        cout << ans << '\n';
    }

}
