#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10005;
int dp[MAXN];

int solve ( int N ) {
    for ( int i = 1; i < N; i++ )
        dp[i] = max( dp[i], dp[i] + dp[i - 1] );

    return *max_element( dp, dp + N );
}

int main ( ) {
    int N;

    while ( cin >> N && N != 0 ) {
        for ( int i = 0; i < N; i++ )
            cin >> dp[i];

        int answer = solve(N);
        if ( answer > 0 )
            cout << "The maximum winning streak is "
                 << answer << ".\n";
        else
            cout << "Losing streak.\n";
    }
}
