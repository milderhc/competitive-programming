#include <bits/stdc++.h>
#define  MAX    10005
#define  pb     push_back
#define  x      first
#define  y      second

using namespace std;

pair<double, double> p[MAX];
pair<double, double> strip[MAX];
inline double sqr ( double n ) { return n * n; }
inline double dist ( pair<double, double> &a, pair<double, double> &b ) {
    return sqrt( sqr(a.x - b.x) + sqr(a.y - b.y) );
}

bool cmp ( const pair<double, double> &a, const pair<double, double> &b ) {
    return a.y < b.y;
}

double closest ( int l, int r ) {
    if ( l >= r ) return MAX;
    if ( l == r - 1 ) return dist(p[l], p[r]);
    int middle = (l + r)/2;
    double dl = closest(l, middle);
    double dr = closest(middle + 1, r);
    double d = min(dl, dr);
    int c = 0;
    for ( int i = l; i <= r; i++ )
        if ( abs(p[i].x - p[middle].x) < d )
            strip[c++] = p[i];
    sort(strip, strip + c, cmp);
    for ( int i = 0; i < c; i++ )
        for ( int j = i + 1, h = 0; j < c && h < 7; j++, h++ )
            d = min( d, dist(strip[i], strip[j]) );
    return d;
}

int main ( ) {
    int N;
    while ( scanf("%d", &N) ) {
        if ( !N ) break;
        for ( int i = 0; i < N; i++ )
            scanf("%lf %lf", &p[i].x, &p[i].y);
        sort(p, p + N);
        double d = closest(0, N - 1);
        if ( d < 10000 ) printf("%.4lf\n", d);
        else printf("INFINITY\n");
    }
}
