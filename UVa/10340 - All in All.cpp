#include <iostream>

using namespace std;

bool valid( string& s, string& t ) {
    int i = 0, j = 0;
    while( i < s.size() && j < t.size() ) {
        if( s[i] == t[j] ) {
            i++;
            j++;
        } else
            j++;
    }
    if( i == s.size() ) return true;
    return false;
}

int main() {
    string s, t;
    while( cin >> s >> t ) {

        if( valid( s, t ) )
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}







