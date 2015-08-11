#include <bits/stdc++.h>
#define INF         0x3fffffff
#define pb          push_back
#define mp          make_pair
#define MAX         10004

using namespace std;

int dp_burguers[MAX], dp_beers[MAX];

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    while ( cin >> n >> m >> t ) {
        for ( int i = 1; i <= t; ++i ) {
            dp_beers[i] = INF;
            dp_burguers[i] = 0;
        }

        for ( int i = 0; i < min(n, m); ++i )
            dp_beers[i] = i;

        for ( int i = 1; i <= t; ++i ) {
            if ( i - n >= 0 ) {
                if ( dp_beers[i - n] < dp_beers[i] ) {
                    dp_beers[i] = dp_beers[i - n];
                    dp_burguers[i] = dp_burguers[i - n] + 1;
                } else if ( dp_beers[i - n] == dp_beers[i]
                            && dp_burguers[i - n] + 1 > dp_burguers[i] )
                    dp_burguers[i] = dp_burguers[i - n] + 1;
            }
            if ( i - m >= 0 ) {
                if ( dp_beers[i - m] < dp_beers[i] ) {
                    dp_beers[i] = dp_beers[i - m];
                    dp_burguers[i] = dp_burguers[i - m] + 1;
                } else if ( dp_beers[i - m] == dp_beers[i]
                            && dp_burguers[i - m] + 1 > dp_burguers[i] )
                    dp_burguers[i] = dp_burguers[i - m] + 1;
            }
        }

        cout << dp_burguers[t];
        if ( dp_beers[t] ) cout << ' ' << dp_beers[t];
        cout << '\n';
    }
}
