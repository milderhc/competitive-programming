#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct box {
    int index;
    vector<int> d;

    box ( int size ) { d = vector<int>(size); }

    bool operator < ( const box& other ) const {
        for ( int i = 0; i < d.size(); i++ )
            if ( d[i] > other.d[i] )
                return false;

        return true;
    }

    bool operator > ( const box& other ) const {
        for ( int i = 0; i < d.size(); i++ )
            if ( d[i] <= other.d[i] )
                return false;

        return true;
    }
};

int main ( ) {

    int n, k;
    while ( cin >> k >> n ) {

        vector<box> boxes( k, box(n) );

        for ( int i = 0; i < k; i++ ) {
            for ( int j = 0; j < n; j++ )
                cin >> boxes[i].d[j];

            boxes[i].index = i + 1;
            sort( boxes[i].d.begin(), boxes[i].d.end() );
        }

        sort( boxes.begin(), boxes.end() );

        vector<int> dp(k, -1);
        vector<int> sol(k);

        dp[0] = 1;
        for ( int i = 0; i < k; i++ )
            for ( int j = 0; j < i; j++ )
                if ( boxes[i] > boxes[j]  ) {
                    if ( dp[j] + 1 > dp[i] ) {
                        dp[i] = dp[j] + 1;
                        sol[i] = j;
                    }
                }

        int current = 0, best = -1;
        for ( int i = 0; i < k; i++ )
            if ( dp[i] > best ) {
                best = dp[i];
                current = i;
            }

        vector<int> longest;
        while ( dp[current] > 1 ) {
            longest.push_back( boxes[current].index );
            current = sol[current];
        }
        longest.push_back( boxes[current].index );

        cout << best << '\n';
        for ( int i = longest.size() - 1; i >= 0; i-- ) {
            cout << longest[i];
            if ( i > 0 ) cout << ' ';
        }

        cout << '\n';
    }
}
