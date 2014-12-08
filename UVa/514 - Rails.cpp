#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool simulate( queue<int>& A, stack<int>& B, vector<int>& C ) {
    int p = 0;
    while( A.size() > 0 ) {
        while( A.size() > 0 && C[p] != A.front() ) {
            B.push( A.front() );
            A.pop();
        }
        if( A.size() == 0 )
        	break;
        A.pop();
        p++;
        while( B.size() > 0 && B.top() == C[p] ) {
	        B.pop();
	        p++;    
	    }    
    }   
    while( B.size() > 0 && B.top() == C[p] ) {
        B.pop();
        p++;    
    }
    return p == C.size();
}

int main() {
    int n;
    while( cin >> n && n != 0 ) {
        vector<int> C(n);
        while( cin >> C[0] && C[0] != 0 ) {
            queue<int> A;
            stack<int> B;
            
            A.push(1);
            for( int i=1; i<n; i++ ) {
                cin >> C[i];
                A.push( i + 1 );
            }
            
            if( simulate(A, B, C) )
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }   
        cout << endl;
    }   
}