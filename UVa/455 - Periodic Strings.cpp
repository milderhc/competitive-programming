#include <bits/stdc++.h>
#define pb  push_back

using namespace std;
typedef long long ll;

const int MAX = 85;
int F[MAX];
char text[2 * MAX], pattern[MAX];
int n, m;

void buildFF ( ) {
    F[0] = F[1] = 0;
    for ( int i = 2; i <= m; ++i )
        for ( int j = F[i - 1]; ; ) {
            if ( pattern[j] == pattern[i - 1] ) {
                F[i] = j + 1;
                break;
            }
            else if ( j ) j = F[j];
            else {
                F[i] = 0;
                break;
            }
        }
}

int KMP ( ) {
    buildFF();
    int matches = -1;
    for ( int i = 0, j = 0; i < n; ) {
        if ( text[i] == pattern[j] ) {
            ++j, ++i;
            if ( j == m ) {
                ++matches;
                j = F[j];
            }
        }
        else if ( j ) j = F[j];
        else ++i;
    }
    return matches;
}

int main ( ) {
    int T;
    scanf("%d", &T);
    while ( T-- ) {
        scanf("%s", pattern);
        m = strlen(pattern);
        n = m * 2;
        for ( int i = 0; i < m; ++i ) text[i] = pattern[i];
        for ( int i = m; i < n; ++i ) text[i] = pattern[i - m];
        printf("%d\n", m/KMP());
        if ( T ) printf("\n");
    }
}
