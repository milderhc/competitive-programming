#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, x, k;
    cin >> n >> k >> x;
    vector<int> balls(n);
    vector<int> index;
    for( int i=0; i<n; i++ ) {
         cin >> balls[i];
         if( balls[i] == x ) {
             if( ( i == 0 ) || ( i > 0 && balls[i-1] != x  ) )
                 index.push_back(i);
         }     
    }
    int ans = 0;
    for( int i=0; i<index.size(); i++ ) {
         int temp = 0;
         int row = 1;
         for( int j=index[i]+1; j<n; j++ )
              if( balls[j] == balls[j-1] )
                  row++;
              else
                  break;
         if( row >= 2 ) {
             temp += row;
             int l = index[i]-1;
             int r = index[i]+row;
             do {
                 if( l < 0 || r >= balls.size() )
                     break;
                 row = 0;
                 int color = balls[l];
                 while( l >= 0 || r < balls.size() ) {
                       bool flag = false;
                       if( l >= 0 && balls[l] == color ) {
                           l--;
                           row++;
                           flag = true;
                       }
                       if( r < balls.size() && balls[r] == color ) {
                           r++;
                           row++;
                           
                           flag = true;
                       }
                       if( !flag )
                           break;
                 }
                 if( row >= 3 )
                    temp += row;
             } while( row >= 3 );
             if( temp > ans )
                 ans = temp;
         }
    }
    cout << ans;
}   
