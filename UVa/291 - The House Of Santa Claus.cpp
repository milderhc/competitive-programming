#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

const int DIM = 6;
vector<vector<int> > G(DIM);

void fill ( ) {
    G[1].push_back(2);
    G[1].push_back(3);
    G[1].push_back(5);

    G[2].push_back(1);
    G[2].push_back(3);
    G[2].push_back(5);

    G[3].push_back(1);
    G[3].push_back(2);
    G[3].push_back(4);
    G[3].push_back(5);

    G[4].push_back(3);
    G[4].push_back(5);

    G[5].push_back(1);
    G[5].push_back(2);
    G[5].push_back(3);
    G[5].push_back(4);
}

bool visited ( string s, int current, int n ) {
    for ( int i = 0; i < s.size() - 1; i++ )
        if ( (s[i] - '0' == n && s[i+1] - '0' == current) ||
            (s[i] - '0' == current && s[i+1] - '0' == n) )
            return true;
    return false;
}

void house ( int current, string s ) {
    string temp;
    for ( int i = 0; i < G[current].size(); i++ ) {
        if ( !visited(s, current, G[current][i]) ) {
            temp = s + char(G[current][i] + '0');
            if ( temp.size() == 9 ) {
                cout << temp << endl;
                return;
            }
            house( G[current][i], temp );
        }
    }
}

int main ( ) {
    fill();
    string s("1");
    for ( int i = 0; i < G[1].size(); i++ )
        house( G[1][i], s + char(G[1][i] + '0') );
}
