#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

int main ( ) {
    int n;
    cin >> n;
    string s;
    while ( n-- ) {
        cin >> s;
        sort( s.begin(), s.end() );
        do {
            cout << s << endl;
        } while ( next_permutation( s.begin(), s.end() ) );
        cout << endl;
    }
}
