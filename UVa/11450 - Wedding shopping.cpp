#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

const int MAX = 20;
vector<int> garments[MAX];
int dp[MAX][205];
int N, M, C, K;

int find_best ( int remaining, int index ) {

    if ( dp[index][remaining] == -1 ) {

        if ( index == C )
            return M - remaining;

        if ( remaining < 0 )
            return -1;

        int result = -1;
        for ( int i = 0; i < garments[index].size(); i++ ) {
            int tmp = find_best( remaining - garments[index][i], index + 1 );
            if ( tmp <= M ) result = max( result, tmp );
        }

        dp[index][remaining] = result;
    }

    return dp[index][remaining];
}

int main ( ) {

    cin >> N;
    while ( N-- ) {

        cin >> M >> C;
        memset( dp, -1, sizeof(dp) );

        for ( int i = 0; i < C; i++ ) {
            cin >> K;
            int tmp;

            garments[i].resize(0);
            for ( int j = 0; j < K; j++ ) {
                cin >> tmp;
                garments[i].push_back(tmp);
            }
        }

        int answer = find_best( M, 0 );

        if ( answer > 0 ) cout << answer << '\n';
        else              cout << "no solution\n";
    }
}
