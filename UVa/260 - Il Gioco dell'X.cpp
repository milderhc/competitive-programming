#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool black_wins ( vector<vector<char> >& m, int n ) {
    map<pair<int,int>, bool> marked;
    vector<pair<int,int> > queue;
    for ( int k = 1; k <= n; k++ ) {
        pair<int, int> current(1, k);
        if ( m[1][k] == 'b' && !marked[current] ) {
            queue.push_back( current );
            marked[current] = true;
            while ( queue.size() > 0 ) {
                int i = queue[0].first,
                    j = queue[0].second;
                queue.erase( queue.begin() );
                current = make_pair(i-1, j-1);
                if ( m[i-1][j-1] == 'b' && !marked[current] ) {
                    queue.push_back(current);
                    marked[current] = true;
                }
                current = make_pair(i-1, j);
                if ( m[i-1][j] == 'b' && !marked[current] ) {
                    queue.push_back(current);
                    marked[current] = true;
                }
                current = make_pair(i, j-1);
                if ( m[i][j-1] == 'b' && !marked[current] ) {
                    queue.push_back(current);
                    marked[current] = true;
                }
                current = make_pair(i, j+1);
                if ( m[i][j+1] == 'b' && !marked[current] ) {
                    queue.push_back(current);
                    marked[current] = true;
                }
                current = make_pair(i+1, j);
                if ( m[i+1][j] == 'b' && !marked[current] ) {
                    if ( i + 1 == n )
                        return true;
                    queue.push_back(current);
                    marked[current] = true;
                }
                current = make_pair(i+1, j+1);
                if ( m[i+1][j+1] == 'b' && !marked[ current ] ) {
                    if ( i + 1 == n )
                        return true;
                    queue.push_back(current);
                    marked[current] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n, cases = 1;
    char in;
    while ( cin >> n && n != 0 ) {
        vector<vector<char> > m(n + 2, vector<char>(n + 2) );
        for ( int i = 0; i < n + 2; i++ )
            m[0][i] = m[i][0] = m[n + 1][0] = m[0][n - 1] = '*';
        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= n; j++ )
                cin >> m[i][j];

        cout << cases++ << (black_wins(m, n) ? " B" : " W") << endl;
    }
}
