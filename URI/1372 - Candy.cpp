#include <iostream>
#include <cmath>

using namespace std;

int special_case( int M )
{
    int max_sum, bf, bftemp, t;
    if( M==1 )
    {
        cin >> t;
        return t;
    }
    cin >> max_sum >> bf;
    for( int j=2; j<M; j++ )
    {
         cin >> t;
         bftemp = bf;
         bf = max_sum + t;
         max_sum = max( max_sum, bftemp );
    }
    return max(bf, max_sum);
}

int main()
{
    int M, N;
    while( cin >> M >> N )
    {
           if( !M && !N )
               break;
           if( N == 1 )
           {
               cout << special_case(M) << endl;
               continue;
           }
           int max_sum, bf, bftemp, t, ans1=0, ans2=0, anstemp;
           for( int i=0; i<M; i++ )
           {
                cin >> max_sum >> bf;
                for( int j=2; j<N; j++ )
                {
                     cin >> t;
                     bftemp = bf;
                     bf = max_sum + t;
                     max_sum = max( max_sum, bftemp );
                }
                if( i>1 )
                {  
                   anstemp = ans2;
                   ans2 = ans1 + max(bf,max_sum);
                   ans1 = max( ans1, anstemp );
                }
                else if( i==0 )
                     ans1 = max(bf,max_sum);
                else
                     ans2 = max(bf,max_sum);    
           }
           cout << max(ans1, ans2) << endl;
    }
}
