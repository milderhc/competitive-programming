#include <bits/stdc++.h>
#define  MAX            10005

using namespace std;

int l[MAX], r[MAX], m[MAX], a[MAX];

int main ( ) {
    int N;
    while ( cin >> N ) {
        for ( int i = 0; i < N; ++i ) cin >> a[i];
        int size = 1;
        m[0] = a[0];
        l[0] = 1;
        for ( int i = 1; i < N; ++i ) {
            int pos = lower_bound(m, m + size, a[i]) - m;
            if ( pos == size ) ++size;
            l[i] = max(l[i - 1], pos + 1);
            m[pos] = a[i];
        }
        size = 1;
        m[0] = a[N - 1];
        r[N - 1] = 1;
        for ( int i = N - 2; i >= 0; --i ) {
            int pos = lower_bound(m, m + size, a[i]) - m;
            if ( pos == size ) ++size;
            r[i] = max(r[i + 1], pos + 1);
            m[pos] = a[i];
        }
        int ans = 1;
        for ( int i = 0; i < N; ++i )
            if ( l[i] == r[i] )
                ans = max(ans, l[i] + r[i] - 1);
        cout << ans << '\n';
    }
}
