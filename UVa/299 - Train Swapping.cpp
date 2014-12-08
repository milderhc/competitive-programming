#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int swaps;
vector<int> _merge( vector<int> left, vector<int> right ) {
    int p_left = 0,
        p_right = 0;

    vector<int> items;
    while( p_left < left.size() && p_right < right.size() ) {
        if( left[p_left] <= right[p_right] )
            items.push_back( left[p_left++] );
        else {
            swaps += left.size() - p_left;
            items.push_back( right[p_right++] );
        }
    }

    while( p_left < left.size() )
        items.push_back( left[p_left++] );

    while( p_right < right.size() )
        items.push_back( right[p_right++] );

    return items;
}

vector<int> merge_sort( vector<int>& v, int from, int to ) {
    int size = to - from;
    if( size == 1 )
        return vector<int>(1, v[from]);

    return _merge( merge_sort( v, from, from + size/2 ),
                   merge_sort( v, from + size/2, to ) );
}

int main() {
    int T, N;
    cin >> T;
    while( T-- ) {
        cin >> N;
        vector<int> v(N);
        swaps = 0;
        for( int i=0; i<N; i++ )
            cin >> v[i];
        if( N > 0 )
            merge_sort( v, 0, v.size() );
        cout << "Optimal train swapping takes " << swaps << " swaps.\n";
    }
}
