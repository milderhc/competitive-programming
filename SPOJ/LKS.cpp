#include <bits/stdc++.h>

using namespace std;

const int MAX = 705, MAX_W = 2000005;
int V[MAX], W[MAX], dp[MAX_W];

int main ( ) {
    int K, N;
    cin >> K >> N;
    for ( int i = 0; i < N; i++ )
        cin >> V[i] >> W[i];

    memset(dp, 0, sizeof(dp));
    for ( int i = 0; i < N; i++ )
        for ( int w = K; w >= 0 && w >= W[i]; w-- )
            dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
    cout << dp[K] << '\n';
}
