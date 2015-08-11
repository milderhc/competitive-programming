#include <bits/stdc++.h>
#define INF         0x3fffffff
#define pb          push_back
#define mp          make_pair
#define MAX         100005

using namespace std;

vector<vector<int> > dp, unsafe;

int go ( int n, int m ) {
    if ( n == 0 && m == 0 ) return 1;
    if ( n < 0 || m < 0 ) return 0;
    if ( unsafe[n][m] ) return 0;

    int &r = dp[n][m];
    if ( r == -1 )
        r = go(n - 1, m) + go(n, m - 1);
    return r;
}

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string line;

    int T, t, w, n;
    cin >> T;
    while ( T-- ) {
        cin >> w >> n;

        dp = vector<vector<int> >(w, vector<int>(n, -1));
        unsafe = vector<vector<int> >(w, vector<int>(n, 0));

        getline(cin, line);
        for ( int i = 0; i < w; ++i ) {
            getline(cin, line);
            istringstream iss(line);
            iss >> t;
            while ( iss >> t ) unsafe[i][t - 1] = 1;
        }

        cout << go(w - 1, n - 1) << '\n';
        if ( T ) cout << '\n';
    }

}
