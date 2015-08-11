#include <bits/stdc++.h>
#define INF         0x3fffffff
#define pb          push_back
#define mp          make_pair

using namespace std;

long long sum[11][10], p[11];

long long compute ( int n ) {
    if ( n < 10 ) return sum[1][n];
    long long c = log10(n) + 1;
    long long digit = n / p[c - 1];
    return sum[c][digit - 1] + digit * (n % p[c - 1] + 1) + compute(n % p[c - 1]);
}

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;

    p[0] = 1;
    for ( int i = 1; i < 11; ++i ) p[i] = 10 * p[i - 1];
    for ( int i = 1; i < 10; ++i ) sum[1][i] = sum[1][i - 1] + i;

    for ( int i = 2; i < 11; ++i ) {
        sum[i][0] = sum[i - 1][9];
        for ( int j = 1; j < 10; ++j )
            sum[i][j] = j * p[i - 1] + sum[i - 1][9] + sum[i][j - 1];
    }

    while ( cin >> m >> n && n )
        cout << compute(n) - compute(m - 1) << '\n';
}
