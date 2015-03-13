#include <bits/stdc++.h>

using namespace std;

int ans = 0;
string line;
void go ( int index, int ns, int left, int right ) {
    ans++;
    for ( int i = index; i < line.size(); i++ ) {
        left += line[i] - 48;
        right -= line[i] - 48;
        if ( left <= right && left >= ns && i < line.size() - 1 )
            go( i + 1, left, 0, right );
    }
}

int main ( ) {
    int cases = 1;
    while ( cin >> line ) {
        if ( line == "bye" ) break;
        int sum = 0;
        for ( int i = 0; i < line.size(); i++ )
            sum += line[i] - 48;

        ans = 0;
        go(0, 0, 0, sum);
        cout << cases++ << ". " << ans << '\n';
    }
}
