#include <iostream>
#include <cstring>
#include <cmath>
#define  index_of(x)    x + 32000

using namespace std;

const int MAX = 102;
bool cache[MAX][64005];
int numbers[MAX];
char ans[MAX];
int goal, p;

bool check( int number, int index ) {
    return abs(number) < 32000 && !cache[index][ index_of(number) ];
}

bool solution( int n, int index, char op ) {

    if( index == p - 1 ) {
        if( n == goal ) {
            ans[index] = op;
            return true;
        }
        return false;
    }

    cache[index][ index_of(n) ] = true;

    int next = n + numbers[index + 1];
    if( check(next, index + 1) && solution( next, index + 1, '+' ) ) {
        ans[index] = op;
        return true;
    }

    next = n - numbers[index + 1];
    if( check(next, index + 1) && solution( next, index + 1, '-' ) ) {
        ans[index] = op;
        return true;
    }

    next = n * numbers[index + 1];
    if( check(next, index + 1) && solution( next, index + 1, '*' )  ) {
        ans[index] = op;
        return true;
    }

    if( n % numbers[index + 1] != 0 ) return false;

    next = n / numbers[index + 1];
    if( check(next, index + 1) && solution( next, index + 1, '/' ) ) {
        ans[index] = op;
        return true;
    }

    return false;
}

int main() {
    int n;

    cin >> n;
    for( int k = 0; k < n; k++ ) {

        memset( cache, false, sizeof(cache) );

        cin >> p;
        for( int i = 0; i < p; i++ )
            cin >> numbers[i];

        cin >> goal;
        if( p == 1 ) {
            if( numbers[0] == goal )
                cout << goal << '=' << goal << '\n';
            else
               cout << "NO EXPRESSION\n";
            continue;
        }

        bool flag = false;
        int init = numbers[0] + numbers[1];
        if( abs(init) < 320000 && solution( init, 1, '+' ) ) flag = true;

        init = numbers[0] - numbers[1];
        if( !flag && abs(init) < 320000 && solution( init, 1, '-' ) ) flag = true;

        init = numbers[0] * numbers[1];
        if( !flag && abs(init) < 32000 && solution( init, 1, '*' ) ) flag = true;

        init = numbers[0] / numbers[1];
        if( !flag && numbers[0] % numbers[1] == 0 && numbers[1] != 1 &&
                 solution( numbers[0] / numbers[1], 1, '/' ) ) flag = true;

        if( flag ) {
            ans[p] = '=';
            for( int i = 1; i <= p; i++ )
                cout << numbers[i - 1] << ans[i];
            cout << goal << '\n';
        } else
            cout << "NO EXPRESSION\n";
    }
}



