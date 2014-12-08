#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

const int MAX = 11;
pair<int, int> beepers[MAX];
int T, x, y, n;
pair<int, int> initial;

int dist ( pair<int, int> A, pair<int, int> B ) {
    return abs ( A.first - B.first ) + abs ( A.second - B.second );
}

int solve ( int seen, int distance_so_far, pair<int, int> current ) {

    if ( seen == ( 1 << n ) - 1 )
        return distance_so_far + dist( initial, current );

    int ans = INT_MAX;
    for ( int i = 0; i < n; i++ )
        if ( !(seen & 1 << i) )
           ans = min ( ans, solve( seen | 1 << i,
                       distance_so_far + dist( beepers[i], current ),
                       beepers[i] ) );

    return ans;
}

int main ( ) {

    cin >> T;
    while ( T-- ) {
        cin >> x >> y;
        cin >> x >> y;

        cin >> n;
        for ( int i = 0; i < n; i++ )
            cin >> beepers[i].first >> beepers[i].second;

        int ans = INT_MAX;
        int seen = 0;

        initial = make_pair( x, y );
        for ( int i = 0; i < n; i++ )
            ans = min ( ans, solve( seen | 1 << i,
                        dist( beepers[i], initial ), beepers[i] ) );

        cout << "The shortest path has length " << ans << '\n';
    }
}
