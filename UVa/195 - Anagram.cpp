#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

bool cmp ( char a, char b ) {
    if ( (islower(a) && islower(b)) || (isupper(a) && isupper(b)) )
        return a < b;
    if ( islower(a) && isupper(b) ) {
        if ( tolower(a) == tolower(b) )
            return false;
        return tolower(a) < tolower(b);
    }
    if ( tolower(a) == tolower(b) )
        return true;
    return tolower(a) < tolower(b);
}

int main() {
    int n;
    cin >> n;
    string s;
    while ( n-- ) {
        cin >> s;
        sort( s.begin(), s.end(), cmp );
        do {
            cout << s << endl;
        } while ( next_permutation( s.begin(), s.end(), cmp ) );
    }
}
