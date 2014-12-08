#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool is_correct ( string &s ) {
    stack<char> st;
    for( int i=0; i<s.size(); i++ ) {
        char p = s[i];
        if( p == '(' || p == '[' )
            st.push(p);
        else if( p == ')' ) {
            if( !st.empty() && st.top() == '(' )
                st.pop();
            else
                return false;
        }
        else if( p == ']' ) {
            if( !st.empty() && st.top() == '[' )
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}

int main ( ) {
    int N;
    string s;
    cin >> N;
    cin.ignore();
    while ( N-- ) {
        getline(cin, s);
        if ( is_correct(s) )
            cout << "Yes\n";
        else
            cout << "No\n";        
    }
}