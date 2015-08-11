#include <bits/stdc++.h>
#define pb      push_back
#define mp      make_pair
#define MAX     51
#define INF     0x3ffffff
#define MOD     1000000007

using namespace std;

int dp[MAX][MAX][MAX];
int n, c[MAX], sum[MAX];

int go ( int left, int right ) {
    int remaining = right - left - 1;
    if ( remaining == 1 ) return c[right] - c[left];
    if ( remaining == 0 ) return 0;

    int &r = dp[left][right][remaining];

    if ( r == -1 ) {
        r = INF;
        for ( int i = 1; i <= n; ++i ) {
            if ( c[i] > c[left] && c[i] < c[right] )
                r = min( r, go(left, i) + go(i, right) );
        }

        r += c[right] - c[left];
    }

    return r;
}

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l;
    while ( cin >> l && l ) {
        memset(dp, -1, sizeof dp);

        cin >> n;
        for ( int i = 1; i <= n; ++i )
            cin >> c[i];
        c[0] = 0, c[n + 1] = l;

        cout << "The minimum cutting is " << go(0, n + 1) << ".\n";
    }
}
