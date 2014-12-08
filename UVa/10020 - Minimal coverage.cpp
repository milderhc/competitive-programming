#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segment {

    int left, right, index;
    segment( int a, int b, int i ) :
        left(a), right(b), index(i) {}

    bool operator < (segment const& other) const {
        return left < other.left;
    }
};

int main() {
    int T, l, r, M;

    cin >> T;
    while( T-- ) {

        cin >> M;
        vector<segment> segments, copy;
        int size = 0;
        while( cin >> l >> r && (l != 0 || r != 0) ) {
            segments.push_back( segment(l, r, size) );
            size++;
        }

        copy = segments;
        sort( segments.begin(), segments.end() );

        vector<segment> answer;
        int last = 0, best = 0, i_best = -1;
        for( int i = 0; i < segments.size(); i++ ) {
            if( segments[i].left <= last ) {
                if( segments[i].right > best ) {
                    best = segments[i].right;
                    i_best = segments[i].index;
                }
            } else {
                if( i_best == -1 || best >= M )
                    break;
                last = best;
                answer.push_back( copy[i_best] );
                i_best = -1;
                i--;
            }
        }
        if( i_best != -1 )
            answer.push_back( copy[i_best] );

        if( best >= M ) {
            cout << answer.size() << '\n';
            for( int i = 0; i < answer.size(); i++ )
                cout << answer[i].left << ' ' << answer[i].right << '\n';
        } else
            cout << 0 << '\n';

        if( T > 0 ) cout << '\n';
    }
}







