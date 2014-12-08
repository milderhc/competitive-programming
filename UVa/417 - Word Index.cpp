#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;
int indx = 1;

void generate_strings( vector<string> src, vector<string>& dst ) {
	dst.clear();
	for ( int i = 0; i < src.size(); i++ )
		for ( char j = src[i][ int(src[i].size() - 1) ] + 1; j < 123; j++ ) {
			string next = src[i] + j;
			dst.push_back( next );
			m[next] = indx++;
		}
}

int main ( ) {
	vector<string> A;
	vector<string> B;
	for ( char i = 97; i < 123; i++ ) {
		string next(1, i);
		A.push_back(next);
		m[next] = indx++;
	}
	generate_strings( A, B );
	generate_strings( B, A );
	generate_strings( A, B );
	generate_strings( B, A );
	string s;
	while ( cin >> s )
		cout << m[s] << endl;    
}
