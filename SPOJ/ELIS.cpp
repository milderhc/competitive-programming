#include <bits/stdc++.h>

using namespace std;

const int MAX = 10005;
int D[MAX], B[MAX];
int n, m, t;

pair<int, int> go ( int number ) {
    if ( number == m ) return make_pair(1, 0);
    if ( number == n ) return make_pair(n/m, 0);
    if ( number < m ) return make_pair(0, number);
    if ( D[number] == 0 ) {
        pair<int, int> a, b;
        if ( number - m > 0 ) a = go( number - m );
        if ( number - n > 0 ) b = go( number - n );

        if ( number - m > 0 && number - n > 0 ) {
            D[number] = max(a.first, b.first) + 1;
            B[number] = min(a.second, b.second);
        } else if ( number - m > 0 ) {
            D[number] = a.first + 1;
            B[number] = a.second;
        } else {
            D[number] = b.first + 1;
            B[number] = b.second;
        }
    }
    return make_pair(D[number], B[number]);
}

int main ( ) {
    while ( cin >> n >> m >> t ) {
        memset( D, 0, sizeof(D) );
        for ( int i = 0; i < MAX; i++ ) B[i] = 10;
        if ( n < m ) swap(n, m);
        D[m] = 1;
        D[n] = n/m;

        cout << go(t).first << ' ' << go(t).second << '\n';
        //cout<< ' '<< B[t] << '\n';
        /*int beer = 0;
        while ( !cache[t] ) beer++, t--;
        if ( beer == 0 ) cout << cache[t] << '\n';
        else cout << cache[t] << ' ' << beer << '\n';*/
    }
}
