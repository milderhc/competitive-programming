#include <iostream>
#include <vector>

using namespace std;

int solution( vector<int> v ) {
    int sum = 0, ans = 0;
    for ( int i = 0; i < v.size()-1; i++ ) {
        if ( sum + v[i] < v[i+1] ) {
            sum += v[i];
            ans++;
        }
    }
    return ans + 1;
}

int main ( ) {
    int n, s;
    cin >> n;
    while ( n-- ) {
        cin >> s;
        vector<int> v(s);
        for ( int i = 0; i < s; i++ )
            cin >> v[i];
        cout << solution(v) << endl;
    }
}
