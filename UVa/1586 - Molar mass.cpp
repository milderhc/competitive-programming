#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cctype>

#define CARBON 		12.01
#define HYDROGEN 	1.008
#define OXYGEN 		16.00
#define NITROGEN 	14.01

using namespace std;

vector<string> split ( string s ) {
	vector<string> v;
	int size = s.size();
	stringstream ss;
	for ( int i = 0; i < size; i++ ) {
		if ( isalpha( s[i] ) ) {	
			if ( i > 0 ) {
				string temp = ss.str();
				if ( temp.size() > 0 )
					v.push_back( temp );
				else
					v.push_back( "1" );	
			}
			v.push_back ( string(1,s[i]) );
			ss.str( "" );
		}
		else
			ss << s[i];
	}
	string temp = ss.str();
	if ( temp.size() > 0 )
		v.push_back( temp );
	else
		v.push_back( "1" );
	return v;
}


int main ( ) {
	string input;
	getline( cin, input );
	int T = atoi( input.c_str() );
	while ( T-- ) {
		getline( cin, input );
		double ans = 0.0;
		vector<string> v = split(input);
		for ( int i = 0; i < v.size(); i+=2 ) {
			switch( v[i][0] ) {
				case 'C':
					ans += atof( v[i+1].c_str() )*CARBON;
					break;
				case 'H':
					ans += atof( v[i+1].c_str() )*HYDROGEN;
					break;
				case 'O':
					ans += atof( v[i+1].c_str() )*OXYGEN;
					break;
				case 'N':
					ans += atof( v[i+1].c_str() )*NITROGEN;
					break;
			}
		}
		printf( "%.3f\n", ans );
	}
}

