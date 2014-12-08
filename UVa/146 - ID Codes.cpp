#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    while( cin >> s && s != "#" ) {
        string temp = s;
        sort( temp.begin(), temp.end() );
        next_permutation( s.begin(), s.end() );
        cout << (s != temp ? s : "No Successor") << endl;
    }
}
