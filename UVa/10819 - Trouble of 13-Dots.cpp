#include <bits/stdc++.h>
#define pb      push_back
#define mp      make_pair
#define MAXN    103
#define MAXM    10203
#define INF     0x3ffffff

using namespace std;

int dp[MAXM], p[MAXN], f[MAXN];

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while ( cin >> m >> n ) {
        for ( int i = 0; i < n; ++i )
            cin >> p[i] >> f[i];

        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        for ( int i = 0; i < n; ++i )
            for ( int j = m + 201; j >= p[i]; --j )
                dp[j] = max(dp[j], dp[j - p[i]] + f[i]);

        int ans = 0;
        for ( int i = 0; i < m + 201; ++i )
            if ( i <= m || (i > 2000 && m + 200 >= i) )
                ans = max(ans, dp[i]);

        cout << ans << '\n';
    }
}




