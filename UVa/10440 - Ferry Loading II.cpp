#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1445;
int cars[MAX];

int main() {
    int n, t, m, c;

    cin >> c;
    while ( c-- ) {

        cin >> n >> t >> m;

        for ( int i = 0; i < m; i++ )
            cin >> cars[i];

        int time, i = 0;
        if( m % n ) i = m % n - 1;
        else        i = n - 1;

        time = cars[i] + 2 * t;
        i += n;
        for( ; i < m; i += n ) {
            if( cars[i] > time )
                time = cars[i];
            time += 2 * t;
        }

        cout << time - t << ' ' << ( m % n ? m / n + 1 : m / n ) << '\n';
    }
}



