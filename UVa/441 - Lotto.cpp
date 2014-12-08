#include <iostream>

using namespace std;

const int MAX = 12;
int numbers[MAX];

int main() {
    int k;
    bool blank = false;

    while( cin >> k && k != 0 ) {

        if( blank ) cout << '\n';
        else blank = true;

        for( int i = 0; i < k; i++ )
            cin >> numbers[i];

        for( int i = 0; i < k; i++ )
            for( int j = i + 1; j < k; j++  )
                for( int l = j + 1; l < k; l++ )
                    for( int m = l + 1; m < k; m++ )
                        for( int n = m + 1; n < k; n++ )
                            for( int o = n + 1; o < k; o++ )
                                cout << numbers[i] << ' ' << numbers[j] << ' '
                                     << numbers[l] << ' ' << numbers[m] << ' '
                                     << numbers[n] << ' ' << numbers[o] << '\n';

    }
}







