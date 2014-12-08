#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 10002;

struct sprinkler {
    double left, right;

    sprinkler( ) {}
    sprinkler( double a, double b ) : left(a), right(b) {}

    bool operator < (sprinkler const& other) const {
        return left < other.left;
    }

} sprinklers[MAX];

int main() {
    int n;
    double l, w, x, r;

    while( cin >> n >> l >> w ) {

        for( int i = 0; i < n; i++ ) {
            cin >> x >> r;
            double range = sqrt( r*r - w*w/4.0 );
            sprinklers[i] = sprinkler(x - range, x + range);
        }

        sort( sprinklers, sprinklers + n );

        double current = 0,
               best = 0;
        int ans = 0;

        for( int i = 0; i < n; i++ ) {
            if( sprinklers[i].left <= current ) {
                if( sprinklers[i].right > best )
                    best = sprinklers[i].right;
            }
            else {
                if( best == current || best >= l )
                    break;
                i--;
                current = best;
                ans++;
            }
        }

        if( best != current )
            ans++;

        if( best >= l ) cout << ans << '\n';
        else cout << -1 << '\n';
    }
}
