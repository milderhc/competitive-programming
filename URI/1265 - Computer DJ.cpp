#include <iostream>
#include <cmath>
#include <cstring>
#include <limits>

using namespace std;

int s[25];
string songs[26];

int leng( int number )
{
    int i = 1;
    while( number > s[i++] );
    return i-1;
}

int N, Q;
string solution( int number, int l )
{
    if( l==1 )
        return songs[ number-1 ];
    int x = (s[l]-s[l-1])/l;
    
    if( (number-s[l-1]-1)%l == 0 )
        return songs[ int(ceil( ceil(double(number-s[l-1])/double(l) )/(x/N) ))-1 ];
        
    int n = ceil( double(number-s[l-1])/double(l) );
    number = (number-s[l-1]-n)%(x/N*(l-1));
    if( number==0 )
        number = s[l-1];
    else
        number += s[l-2]; 
    return solution(number,l-1);
}

int main()
{
    while( cin >> N >> Q )
    {
        if( !N && !Q )
            break;
        if( N > 1 )
        {
            long long sum = 0;
            int i=0;
            while( sum <= 100000000 )
            {
                sum += pow(double(N),i)*(i);
                s[i] = sum;
                i++;
            }
            for( int i=0; i<N; i++ )
                cin >> songs[i];
            int q;
            for( int i=0; i<Q; i++ )
            {
                cin >> q;
                cout << solution( q, leng(q) ) << endl;
            }
        }else{
            cin >> songs[0];
            int q;
            for( int i=0; i<Q; i++ )
            {
                cin >> q;
                cout << songs[0] << endl;
            }       
        }
        cout << endl;
    }    
}
