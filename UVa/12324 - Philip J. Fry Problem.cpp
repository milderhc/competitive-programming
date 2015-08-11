#include <bits/stdc++.h>
#define INF         0x3fffffff
#define pb          push_back
#define mp          make_pair
#define MAX         103

using namespace std;

typedef long long ll;

int t[MAX], b[MAX];

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while ( cin >> n && n ) {
        priority_queue<pair<int, int> > q;
        for ( int i = 0; i < n; ++i ) {
            cin >> t[i] >> b[i];
            q.push( mp(t[i], i) );
        }

        int ans = 0;
        while ( !q.empty() ) {
            int h = q.top().first,
                i = q.top().second - 1;
            q.pop();

            bool found = 0;
            for ( ; i >= 0; --i ) {
                if ( b[i] ) {
                    --b[i];
                    found = 1;
                    ans += h >> 1;
                    break;
                }
            }

            if ( !found ) ans += h;
        }

        cout << ans << '\n';
    }
}
