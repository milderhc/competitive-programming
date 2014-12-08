#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    string s;
    while( getline(cin, s) ) {
        int ans = 0;
        for( int i=0; i<s.size(); )
            if( isalpha(s[i++]) ) {
                ans++;
                while( isalpha(s[i++]) );
            }

        cout << ans << endl;
    }
}
