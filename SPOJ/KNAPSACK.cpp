#include <bits/stdc++.h>

using namespace std;

const int MAX = 2005;
int W[MAX], V[MAX], dp[MAX];

int main ( ) {
    int S, N;
    cin >> S >> N;
    memset(dp, 0, sizeof(dp));
    for ( int i = 0; i < N; i++ )
        cin >> W[i] >> V[i];
    for ( int i = 0; i < N; i++ )
        for ( int w = S; w >= 0 && w >= W[i]; w-- )
            dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
    cout << dp[S] << '\n';
}
