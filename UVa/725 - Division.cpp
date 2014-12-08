#include <iostream>
#include <set>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

set<int> permutations;
void generate_permutations( int n, int m, string s ) {
    if( s.size() == m ) {
        permutations.insert( atoi( s.c_str() ) );
        return;
    }
    for( int i=0; i<n; i++ ) {
        if( s.find( char(i + 48) ) == string::npos )
            generate_permutations( n, m, s + char(i + 48) );
    }
}

string solution( int a, int b, int c ) {
    stringstream ss;
    if( a < 10000 )
        ss << '0';
    ss << a;
    string A = ss.str();
    ss.str("");
    if( b < 10000 )
        ss << '0';
    ss << b;
    string B = ss.str();
    ss.str("");
    if( A.find_first_of( B ) != string::npos )
        return "";

    ss << a << " / ";
    if( b < 10000 )
        ss << '0';
    ss << b << " = " << c << '\n';
    return ss.str();
}

int main() {
    int N;
    for( int i=0; i<10; i++ )
        generate_permutations( 10, 5, string(1, char(i + 48)) );

    bool first = true;
    while( cin >> N && N != 0 ) {
        if( !first )
            cout << '\n';
        else
            first = false;

        vector<string> ans;

        set<int>::iterator it;
        string s;
        for( it=permutations.begin(); it!=permutations.end(); it++ )
            if( permutations.count( N * (*it) ) ) {
                s = solution(N * (*it), *it, N);
                if( s != "" )
                    ans.push_back(s);
            }

        if( ans.size() == 0 )
            cout << "There are no solutions for " << N  << ".\n";

        for( int i=0; i<ans.size(); i++ )
            cout << ans[i];
    }
}

