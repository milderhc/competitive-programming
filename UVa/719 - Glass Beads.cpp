#include <bits/stdc++.h>

using namespace std;

const int MAX = 20010;
struct entry {
    int L, R, index;
    bool operator < ( const entry &other ) const {
        if ( L == other.L ) return R < other.R;
        return L < other.L;
    }
} SA[MAX];

int RA[MAX];
string T;
void buildSA ( ) {
    int n = T.size();
    for ( int i = 0; i < n; ++i ) {
        SA[i].L = RA[i] = T[i];
        SA[i].index = i;
    }
    for ( int k = 1, r, bfL, bfR; k < n; k <<= 1 ) {
        for ( int i = 0, next; i < n; ++i ) {
            next = SA[i].index + k;
            SA[i].R = (next < n ? RA[next] : 0);
        }
        sort(SA, SA + n);
        r = 0;
        bfL = SA[0].L;
        bfR = SA[0].R;
        SA[0].L = RA[SA[0].index] = 0;
        for ( int i = 1; i < n; ++i ) {
            if ( SA[i].L != bfL || SA[i].R != bfR ) ++r;
            bfL = SA[i].L;
            bfR = SA[i].R;
            SA[i].L = RA[SA[i].index] = r;
        }
    }
}

int main ( ) {
    int n, x;
    cin >> n;
    while ( n-- ) {
        cin >> T;
        x = T.size();
        T += T;
        T.push_back('z' + 1);
        buildSA();
        for ( int i = 0; i < T.size(); ++i )
            if ( SA[i].index < x ) {
                cout << SA[i].index + 1 << '\n';
                break;
            }
    }
}
