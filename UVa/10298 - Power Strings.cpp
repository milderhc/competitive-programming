#include <bits/stdc++.h>

using namespace std;

set<int> divs;
void divisors ( int n ) {
    divs.clear();
    for ( int i = 1; i * i <= n; ++i )
        if ( n % i == 0 ) {
            divs.insert(i);
            divs.insert(n/i);
        }
}


int main ( ) {
    string line;
    set<int>::iterator i;
    while ( getline(cin, line) ) {
        if ( line == "." ) break;
        divisors(line.size());

        for ( i = divs.begin(); i != divs.end(); i++ ) {
            bool ok = true;
            for ( int k = 0, j = 0; k < line.size() && ok; k++, j = (j + 1)%(*i) )
                ok &= line[k] == line[j];
            if (ok) {
                cout << line.size()/(*i) << '\n';
                break;
            }
        }
    }
}
