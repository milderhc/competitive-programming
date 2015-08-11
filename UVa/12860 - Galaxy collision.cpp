#include <bits/stdc++.h>
#define pb      push_back
#define mp      make_pair
#define MAX     50005

using namespace std;
typedef long long ll;

pair<ll, ll> p[MAX];

#define x      first
#define y      second

ll sqr ( ll n ) { return n * n; }
ll dist ( int a, int b ) {
    return sqr(p[a].x - p[b].x) + sqr(p[a].y - p[b].y);
}

typedef vector<vector<int> > graph;

#define GREEN   1
#define RED     2

int seen[MAX];

int go ( int u, graph &G ) {
    seen[u] = RED;
    queue<int> q;

    q.push(u);
    q.push(RED);

    int color, red = 1, green = 0;
    while ( !q.empty() ) {
        u = q.front(); q.pop();
        color = q.front(); q.pop();

        for ( int i = 0; i < G[u].size(); ++i ) {
            int v = G[u][i];
            if ( !seen[v] ) {
                seen[v] = color % 2 + 1;
                if ( seen[v] == RED ) ++red;
                else ++green;

                q.push(v);
                q.push(seen[v]);
            }
        }
    }

    return min(red, green);
}

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<pair<ll, ll>, int> points;

    int N;
    while ( cin >> N ) {
        graph G(N);

        points.clear();
        memset(seen, 0, sizeof seen);
        for ( int i = 0; i < N; ++i ) {
            cin >> p[i].x >> p[i].y;
            points[p[i]] = i;
        }

        for ( int i = 0; i < N; ++i ) {
            for ( int j = -5; j < 6; ++j )
                for ( int k = -5; k < 6; ++k )
                    if ( j | k ) {
                        pair<ll, ll> nb = mp(p[i].x + j, p[i].y + k);
                        if ( points.count(nb) ) {
                            int t = points[nb];
                            if ( dist(i, t) <= 25LL ) {
                                G[i].pb(t);
                                G[t].pb(i);
                            }
                        }
                    }
        }

        int ans = 0;
        for ( int i = 0; i < N; ++i )
            if ( !seen[i] )
                ans += go(i, G);

        cout << ans << '\n';
    }
}
