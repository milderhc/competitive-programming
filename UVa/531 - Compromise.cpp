#include <bits/stdc++.h>
#define pb      push_back
#define mp      make_pair
#define MAX     102
#define INF     0x3fffffff

using namespace std;

int dp[MAX][MAX];
string a[MAX];
string b[MAX];

inline bool read ( int &n, int &m ) {
    n = 1;
    if ( !(cin >> a[1]) ) return 0;
    if ( a[1] != "#" )
    for ( n = 2; cin >> a[n] && a[n] != "#"; ++n );
    for ( m = 1; cin >> b[m] && b[m] != "#"; ++m );
    return true;
}

void solution ( int n, int m, vector<string> &v ) {
    if ( n == 0 || m == 0 ) return;
    if ( a[n] == b[m] ) {
        solution(n - 1, m - 1, v);
        v.pb(a[n]);
        return;
    }
    if ( dp[n - 1][m] > dp[n][m - 1] ) solution(n - 1, m, v);
    else solution(n, m - 1, v);
}

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while ( read(n, m) ) {
        for ( int i = 1; i < n; ++i )
            for ( int j = 1; j < m; ++j )
                if ( a[i] == b[j] ) dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            vector<string> v;
            solution(n - 1, m - 1, v);
            for ( int i = 0; i < v.size(); ++i ) {
                if ( i ) cout << ' ';
                cout << v[i];
            }
            cout << '\n';
    }
}




