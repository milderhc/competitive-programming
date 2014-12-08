#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000;
    
struct edge {
       int u, v, w;
} edges[2005];

bool bellman_ford ( int n, int m, int s ) {
     vector<int> D(n, INF);
     D[s] = 0;
     for ( int i = 0; i < n-1; i++ )
          for ( int j = 0; j < m; j++ )
               if ( D[ edges[j].v ] > D[ edges[j].u ] + edges[j].w )
                   D[ edges[j].v ] = D[ edges[j].u ] + edges[j].w;
                   //F[v] = u; 
               
     for ( int j = 0; j < m; j++ )
           if ( D[ edges[j].v ] > D[ edges[j].u ] + edges[j].w )
               return false;  
           
     return true;
}

int main( ) {
    int c, n, m;
    cin >> c;
    while ( c-- ) {
           cin >> n >> m;
           for ( int i = 0; i < m; i++ )
                  cin >> edges[i].u >> edges[i].v >> edges[i].w;       
           if ( !bellman_ford(n, m, 0) )
               cout << "possible" << endl;
           else
               cout << "not possible" << endl;  
    }    
}
