#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, number;
    map<int,int> m;
    cin >> n;
    while( n-- ) {
        cin >> number;
        m[number]++;
    }
    pair<int,int> max_flower = *m.rbegin();
    pair<int,int> min_flower = *m.begin();
    if( max_flower == min_flower ) {
        ll n = max_flower.second;
        cout << "0 " << n*(n - 1)/2;
        return 0;
    }
    cout << max_flower.first - min_flower.first << ' '
         << ll(max_flower.second) * ll(min_flower.second);
}
