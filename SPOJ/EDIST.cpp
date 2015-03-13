#include <bits/stdc++.h>

using namespace std;

const int MAX = 2005;
int D[MAX][MAX];
char a[MAX], b[MAX];

int ed ( int n, int m ) {
    for ( int i = 0; i <= n; i++ ) D[i][0] = i;
    for ( int j = 0; j <= m; j++ ) D[0][j] = j;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
            D[i][j] = min( min(D[i][j - 1] + 1, D[i - 1][j] + 1),
                            (D[i - 1][j - 1] + (a[i - 1] != b[j - 1])) );

    return D[n][m];
}

int main ( ) {
    int T;
    scanf("%d", &T);
    while ( T-- ) {
        scanf("%s", a);
        scanf("%s", b);
        printf( "%d\n", ed(strlen(a), strlen(b) ) );
    }
}
