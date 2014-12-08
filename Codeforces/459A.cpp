#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if( y1 == y2 ) {
        int dist = abs(x1 - x2);
        cout << x1 << ' ' << y1 + dist << ' '
             << x2 << ' ' << y2 + dist;
        return 0;
    }
    if( x1 == x2 ) {
        int dist = abs(y1 - y2);
        cout << x1 + dist << ' ' << y1 << ' '
             << x2 + dist << ' ' << y2;
        return 0;
    }
    if( abs(x1 - x2) == abs(y1 - y2) ) {
        cout << x1 << ' ' << y2 << ' '
             << x2 << ' ' << y1;
        return 0;
    }
    cout << -1;
}
