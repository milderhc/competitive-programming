#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 100;
char cities[MAX][5];
int limit;

int changes( int a ) {
    int c = 0;
    for( int i = 0; i < limit; i++ )
        for( int j = 0; j < 5; j++ )
            if( cities[a][j] != cities[i][j] )
                c++;
    return c;
}

int main() {
    string line;
    limit = 0;

    while( getline(cin, line) ) {
        if( line == "#" )
            break;

        if( line[0] == 'e' ) {
            int ans = 5 * MAX, index, t;

            for( int i = 0; i < limit; i++ ) {
                t = changes( i );
                if( t < ans ) {
                    ans = t;
                    index = i;
                }
            }

            limit = 0;
            cout << index + 1 << endl;

            continue;
        }

        char color, r, t;
        istringstream iss(line);

        do {
            iss >> color >> t >> r;
            if( r == 'P' ) cities[limit][0] = color;
            else if( r == 'G' ) cities[limit][1] = color;
            else if( r == 'A' ) cities[limit][2] = color;
            else if( r == 'S' ) cities[limit][3] = color;
            else cities[limit][4] = color;    //N
        } while( iss >> t );

        limit++;
    }

}







