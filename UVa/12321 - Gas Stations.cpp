#include <bits/stdc++.h>
#define INF         0x3fffffff
#define pb          push_back
#define mp          make_pair
#define MAX         10004

using namespace std;

struct gas {
    int l, x, rd, r;

    bool operator < ( const gas &other ) const {
        if ( l == other.l ) return r < other.r;
        return l < other.l;
    }
} station[MAX];

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    gas init;
    init.l = init.r = 0;

    int l, g;
    while ( cin >> l >> g ) {
        if ( l + g == 0 ) break;

        for ( int i = 0; i < g; ++i ) {
            cin >> station[i].x >> station[i].rd;
            station[i].l = max(0, station[i].x - station[i].rd);
            station[i].r = min(l, station[i].x + station[i].rd);
        }

        sort(station, station + g);

        int ok = station[0].l == 0, maxr = station[0].r;
        for ( int i = 1; i < g; ++i ) {
            ok &= station[i].l <= maxr;
            maxr = max(maxr, station[i].r);
        }

        if ( !ok || maxr < l ) { cout << "-1\n"; continue; }

        int left = 0, right = 0;

        vector<gas> v;
        v.pb(init);

        gas current;
        bool flag = false;
        for ( int i = 0; i < g; ++i ) {
            if ( station[i].r > v.back().r ) {
                if ( !flag ) {
                    flag = 1;
                    current = station[i];
                } else if ( station[i].l > v.back().r ) {
                    v.pb(current);
                    flag = 0;
                    --i;
                } else if ( station[i].l <= v.back().r && station[i].r > current.r ) {
                    current = station[i];
                }
            }
        }

        if ( flag ) v.pb(current);
        cout << g - (v.size() - 1) << '\n';
    }
}
