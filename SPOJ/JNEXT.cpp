#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000005;
int d[10], number[MAX];

int main ( ) {
    int t, n, ind, bf, change;
    memset(d, 0, sizeof(d));
    scanf("%d", &t);
    while ( t-- ) {
        scanf("%d", &n);
        for ( int i = 0; i < n; i++ ) scanf("%d", &number[i]);
        bf = -1;
        ind = n;
        for ( int i = n - 1; i >= 0; i-- ) {
            d[number[i]]++;
            if ( number[i] < bf ) {
                ind = i;
                break;
            }
            bf = number[i];
        }

        if ( ind == n ) {
            printf("-1\n");
            memset(d, 0, sizeof(d));
            continue;
        }

        int change = -1;
        for ( int i = 0; i < 10; i++ ) {
            if ( d[i] && i > number[ind] ) {
                change = i;
                d[i]--;
                break;
            }
        }

        for ( int i = 0; i < ind; i++ )
            printf("%d", number[i]);

        printf("%d", change);
        for ( int i = 0; i < 10; i++ )
            while ( d[i] ) {
                printf("%d", i);
                d[i]--;
            }
        printf("\n");
    }
}
