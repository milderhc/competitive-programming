#include <bits/stdc++.h>
#define  MAX            100005

using namespace std;

vector<vector<int> > solutions;
void go ( int col, vector<int> current ) {
    if ( col == 8 ) {
        solutions.push_back(current);
        return;
    }
    if ( current[col] != -1 ) { go(col + 1, current); return; }
    for ( int r = 0; r < 8; ++r ) {
        bool ok = true;
        for ( int c = 0; c < 8; ++c ) {
            if ( current[c] == -1 ) continue;
            int row = current[c];
            if ( r == row || abs(r - row) == abs(c - col) ) {
                ok = false;
                break;
            }
        }
        if ( ok ) {
            current[col] = r;
            go(col + 1, current);
        }
    }
}

int main ( ) {
    int T;
    cin >> T;
    while ( T-- ) {
        int r, c;
        cin >> r >> c;
        --c, --r;
        solutions.clear();
        vector<int> current(8, -1);
        current[c] = r;
        go(0, current);
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        for ( int i = 0; i < solutions.size(); ++i ) {
            if ( i < 9 ) cout << ' ';
            cout << i + 1 << "     ";
            for ( int j = 0; j < 8; ++j )
                cout << ' ' << solutions[i][j] + 1;
            cout << '\n';
        }
        if ( T > 0 ) cout << '\n';
    }
}
