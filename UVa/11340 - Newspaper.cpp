#include <iostream>
#include <map>

using namespace std;

int main() {
    int T, n, value, M;
    char character;
    string s;
    cin >> T;
    while( T-- ) {
        cin >> n;
        map<char, int> m;
        while( n-- ) {
            cin >> character >> value;
            m[character] = value;
        }
        cin >> M;
        int ans = 0;
        cin.ignore();
        while( M-- ) {
            getline(cin, s);
            for( int i=0; i<s.size(); i++ )
                ans += m[ s[i] ];
        }
        if( ans%100 > 9 )
            cout << ans/100 << '.' << ans%100 << '$' << endl;
        else
            cout << ans/100 << ".0" << ans%100 << '$' << endl;
    }
}
