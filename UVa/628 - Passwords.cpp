#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;
string words[MAX];
string rule;
int n, m;

void find_password ( int index, string current ) {
    if ( index == rule.size() ) {
        cout << current << '\n';
        return;
    }

    if ( rule[index] == '0' ) {
        for ( int i = 0; i <= 9; i++ )
            find_password( index + 1, current + char(i + 48) );
    } else  {
        for ( int i = 0; i < n; i++ )
            find_password( index + 1, string(current) + words[i] );
    }
}

int main ( ) {
    while ( cin >> n ) {
        for ( int i = 0; i < n; i++ )
            cin >> words[i];

        cin >> m;
        cout << "--\n";
        while ( m-- ) {
            cin >> rule;
            find_password( 0, "" );
        }
    }
}
