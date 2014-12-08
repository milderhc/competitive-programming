#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>

using namespace std;

struct element {
    int index;
    string number;

    element(int in) : index(in) {}

    bool operator < ( const element& e ) const {
        return index < e.index;
    }
};

int main() {
    int T, n;
    string s;
    cin >> T;
    while( T-- ) {
        cin.ignore();
        getline(cin, s);
        vector<element> numbers;
        getline(cin, s);
        stringstream ss, ss2;
        ss << s;
        while( ss >> n )
            numbers.push_back( element(n) );

        for( int i=0; i<numbers.size(); i++ )
            cin >> numbers[i].number;

        sort( numbers.begin(), numbers.end() );
        for( int i=0; i<numbers.size(); i++ )
            cout << numbers[i].number << endl;

        if( T > 0 )
            cout << endl;
    }
}
