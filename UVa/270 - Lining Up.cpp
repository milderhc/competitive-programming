#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 707;
struct point { int x, y; } p[MAX];
struct line {
    int A, B, C;
    line ( point &a, point &b ) {
        A = b.y - a.y;
        B = a.x - b.x;
        C = a.x*A + a.y*B;
    }

    bool point_on_line ( point &a ) {
        return a.x*A + a.y*B == C;
    }
};

bool seen[MAX][MAX];
int main ( ) {
    int T, N;
    cin >> T;
    string x;
    getline(cin, x);
    getline(cin, x);
    while ( T-- ) {
        N = 0;
        while ( getline(cin, x) ) {
            if ( x == "" ) break;
            istringstream iss(x);
            iss >> p[N].x >> p[N].y;
            ++N;
        }
        memset(seen, 0, sizeof(seen));
        int ans = -1;
        for ( int i = 0; i < N; ++i )
            for ( int j = i + 1; j < N; ++j ) {
                if ( seen[i][j] ) continue;
                seen[i][j] = seen[j][i] = 1;
                int c = 2;
                line l(p[i], p[j]);
                for ( int k = j + 1; k < N; ++k ) {
                    if ( l.point_on_line(p[k]) ) {
                        seen[i][k] = seen[k][i] = 1;
                        seen[j][k] = seen[k][j] = 1;
                        ++c;
                    }
                }
                ans = max(ans, c);
            }
        cout << ans << '\n';
        if ( T ) cout << '\n';
    }
}
