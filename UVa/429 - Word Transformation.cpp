#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MAX = 200;
int G[MAX+5][MAX+5];

map<string,int> mp;

bool valid_link ( string A, string B ) {
     if ( A.size() != B.size() )
          return false;
     int n = 0;
     for  ( int i = 0; i < A.size(); i++ )
         if ( A[i] != B[i] )
             n++;
     if ( n == 1 )
          return true;
     return false;
}

void add ( string A ) {
     if ( mp.size() == 0 ) {
          mp[A] = 0;
          return;
     }
     map<string,int>::iterator node;
     int index = mp.size();
     for ( node=mp.begin(); node!=mp.end(); node++ ) {
         string B = (*node).first;
         if ( valid_link( A, B ) ) {
              G[ index ][ mp[B] ] = 1;
              G[ mp[B] ][ index ] = 1;
         }
     }
     mp[A] = index;
}

int solution ( string A, string B, int size ) {
    int start = mp[A];
    int end = mp[B];
    
    int distance[MAX+5];
    memset( distance, 0, sizeof(distance) );
    distance[start] = 1;
    queue<int> q;
    q.push(start);
    while ( !q.empty() ) {
          int current = q.front();
          q.pop();
          for  ( int neighbor=0; neighbor<size; neighbor++ )
              if ( G[current][neighbor] && !distance[neighbor] ) {
                   q.push(neighbor);
                   distance[neighbor] = distance[current] + 1;
                   if ( neighbor == end )
                      return distance[end] - 1;
              }     
    }
    return 0;
}

int main ( ) {
    string input;
    int T;
    getline( cin, input );
    T = atoi( input.c_str() );
    getline( cin, input );
    while ( T-- ) {
         memset( G, 0, sizeof(G) ); 
         mp.clear();
         getline( cin, input );
         int size = 0;
         while ( input != "*" ) {
               add( input );
               getline( cin, input );
               size++;
         }
         getline( cin, input );
         while ( input != "" ) {
               int index = input.find( " " );
               cout << input << " " << solution( input.substr( 0, index ),  
                                                 input.substr( index+1, input.size()-index-1 ), size ) << endl; 
               getline( cin, input );
         }
         if ( T > 0 )
              cout << endl;
    }
}
