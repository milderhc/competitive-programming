#include <bits/stdc++.h>

using namespace std;

int main ( ) {
    string w;
    int t = 1;
    while ( cin >> w ) {
        if ( w[0] == '-' ) break;
        int c = 0, ans = 0;
        for ( int i = 0; i < w.size(); i++ ) {
            if ( w[i] == '{' ) c++;
            else if ( w[i] == '}' ) {
                if ( c == 0 ) {
                    ans++;
                    c = 1;
                }
                else c--;
            }
        }
        cout << t++ << ". " << ans + c/2 << '\n';
    }
}
