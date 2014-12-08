#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
void f ( int a, int b ) {
    if ( b == 0 ) return;
    ans.push_back(a/b);
    f( b, a%b );
}

int main ( ) {
    int a, b;
    while ( cin >> a >> b ) {
        ans = vector<int>();
        f(a, b);
        cout << '[' << ans[0] << ';';
        for ( int i = 1; i < ans.size(); i++ ) {
            if ( i > 1 ) cout << ',';
            cout << ans[i];
        }
        cout << "]\n";
    }
}
