#include <bits/stdc++.h>
#define  mp     make_pair

using namespace std;

struct line {
    int x0, y0, x1, y1, A, B, C;
    void create ( ) {
        A = y1 - y0;
        B = x0 - x1;
        C = A*x1 + B*y1;
    }

    int intersect ( line &other ) {
        double det = A*other.B  - other.A*B;
        if ( det != 0 ) {
            double x = (other.B*C - B*other.C)/det;
            double y = (A*other.C - other.A*C)/det;
            if ( x >= min(x0, x1) && x <= max(x0, x1) &&
                 y >= min(y0, y1) && y <= max(y0, y1) &&
                 x >= min(other.x0, other.x1) && x <= max(other.x0, other.x1) &&
                 y >= min(other.y0, other.y1) && y <= max(other.y0, other.y1) )
                return 1;
            return 0;
        }
        double A2 = other.y0 - y0;
        double B2 = x1 - other.x1;
        det = A*B2 + A2*B;
        bool overlap = (det == 0 && (min(x0, x1) <= max(other.x0, other.x1) ||
                                     min(other.x0, other.x1) <= max(x0, x1) ) );
        return (overlap ? -1 : 0);
    }
};

int main ( ) {
    int T;
    cin >> T;
    while ( T-- ) {
        int n;
        cin >> n;
        vector<line> v(n);
        for ( int i = 0; i < n; ++i ) {
            cin >> v[i].x0 >> v[i].y0 >> v[i].x1 >> v[i].y1;
            v[i].create();
        }
        int ans = 0;
        for ( int i = 0; i < n; ++i ) {
            int c = 0;
            bool flag = true;
            for ( int j = 0; j < i; ++j ) {
                int x = v[i].intersect(v[j]);
                if ( x == -1 ) { continue; flag = false; }
                if ( x == 1 ) {
                    ++c;
                    if ( c > 1 ) ans += 2;
                    else ans += 3;
                }
            }
            if ( c == 0 ) ans += flag;
        }
        cout << ans << '\n';
        if ( T ) cout << '\n';
    }
}
