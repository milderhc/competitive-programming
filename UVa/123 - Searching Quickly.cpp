#include <bits/stdc++.h>
#define  pb     push_back
using namespace std;

struct title {
    vector<string> words;
    string keyword;
    int index, j;

    title ( vector<string> v, string k, int i, int h ) {
        words = v, keyword = k, index = i, j = h;
    }

    bool operator < ( const title &other ) const {
        if ( keyword != other.keyword ) return keyword < other.keyword;
        if ( index != other.index ) return index < other.index;
        return j < other.j;
    }
};

set<string> ignore;

int main() {
	string s;
	while ( getline(cin, s) ) {
        if ( s == "::" ) break;
        ignore.insert(s);
	}
	vector<title> titles;
    for ( int i = 0; getline(cin, s); ++i ) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        istringstream iss(s);
        vector<string> t;
        while ( iss >> s ) t.pb(s);
        for ( int j = 0; j < t.size(); ++j ) {
            if ( !ignore.count(t[j]) ) {
                string temp = t[j];
                transform(t[j].begin(), t[j].end(), t[j].begin(), ::toupper);
                titles.pb( title(t, t[j], i, j) );
                t[j] = temp;
            }
        }
    }
    sort(titles.begin(), titles.end());
    for ( int i = 0; i < titles.size(); ++i ) {
        for ( int j = 0; j < titles[i].words.size(); ++j ) {
            if ( j ) cout << ' ';
            cout << titles[i].words[j];
        }
        cout << '\n';
    }
}
