#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
    
const int INF = 1000000;

vector<vector<int> > D;
vector<vector<int> > F;
vector<vector<int> > G;

void initialize_distances ( int size ) {
     D.clear();
     F.clear();
     D.resize( size );
     F.resize( size );
     for ( int i = 0; i < size; i++ ) {
          D[i].clear();
          F[i].clear();
          D[i].resize( size );
          F[i].resize( size );
          for ( int j = 0; j < size; j++ ) {
               if ( i == j ) {
                   D[i][j] = 0;
                   F[i][j] = -1;
               } else {
                   F[i][j] = i;
                   if ( G[i][j] != 0 )
                       D[i][j] = G[i][j];
                   else
                       D[i][j] = INF;        
               }     
          }
     }
}

void floyd_warshall ( ) {
     int size = G.size();
     initialize_distances(size); 
     
     for ( int k = 0; k < size; k++ )
          for ( int i = 0; i < size; i++ )
               for ( int j = 0; j < size; j++ )
                    if ( i != k && j != k )
                        if ( D[i][j] > D[i][k] + D[k][j] ) {
                            D[i][j] = D[i][k] + D[k][j];
                            F[i][j] = F[k][j];    
                        }                    
}

void initialize_G ( int size ) {
     G.clear();
     G.resize(size);
     for ( int i = 0; i < size; i++ ) {
          G[i].clear();
          G[i].resize(size);  
     }   
}

bool solution ( ) {
     for ( int i = 0; i < D.size(); i++ )
          for ( int j = 0; j < D.size(); j++ )   
               if ( D[i][j] == INF )
                   return false;
     return true;  
}

int main ( ) {
    int N, M, V, W, P;
    while ( cin >> N >> M ) {
           if ( N == 0 && M == 0 )       
               break;
           initialize_G(N);
           while ( M-- ) {
                  cin >> V >> W >> P;
                  V--;
                  W--;
                  if ( P == 1 )
                      G[V][W] = 1;
                  else {
                      G[V][W] = 1;
                      G[W][V] = 1; 
                  }    
           }
           floyd_warshall();
           cout << solution() << endl;
    }    
}

