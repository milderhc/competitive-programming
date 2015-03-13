#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main ( ) {
	cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);
    int N;
    cin >> N;
    double x1, x2, x3, x4, y1, y2, y3, y4;
    cout << "INTERSECTING LINES OUTPUT\n";
    while ( N-- ) {
    	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    	double A1 = y2 - y1;
    	double B1 = x1 - x2;
    	double C1 = A1*x1 + B1*y1;
    	double A2 = y4 - y3;
    	double B2 = x3 - x4;
    	double C2 = A2*x3 + B2*y3;
    	double det = A1*B2 - A2*B1;
    	if ( det != 0 ) {
    		double x = (B2*C1 - B1*C2)/det;
        	double y = (A1*C2 - A2*C1)/det;
    		cout << "POINT " << x << ' ' << y << '\n';
    	} else {
    		double A3 = y3 - y1;
    		double B3 = x1 - x3;
    		det = A1*B3 - A3*B1;
    		if ( det == 0 ) cout << "LINE\n";
    		else cout << "NONE\n";
    	}
    }
	cout << "END OF OUTPUT\n";
}
