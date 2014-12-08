#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
#include <cctype>
#include <iostream>

using namespace std;

bool m[35][35];
bool visit[35];
int nodes;

int solution ( ) {
    int ans = 0;
    for ( int i = 0; i < nodes; i++ )
         ans += visit[i];
    return nodes-ans;
}

int bfs ( int start, int lim ) {
    queue< pair<int,int> > q;
    q.push( make_pair(start,lim) );
    visit[start] = true;
    while ( !q.empty() ) {
           pair<int,int> current = q.front();
           q.pop();
           if ( current.second == 0 )
               continue;
           int c = current.first;
           lim = current.second - 1;
           for ( int i = 0; i < nodes; i++ ) {
                if ( m[i][c] && !visit[i] ) {
                    visit[i] = true;
                    q.push( make_pair(i,lim) );
                }
           }
    }
    return solution();
}


int main ( ) {
    int NC, count = 1;
    while ( scanf( "%d", &NC ) ) {
           if ( !NC )
               break;
           memset( m, false, sizeof(m) );
           int a, b;
           nodes = 0;
           map<int,int> mp;
           for ( int i = 0; i < NC; i++ ) {
                  scanf( "%d", &a );
                  scanf( "%d", &b );
                  int na, nb;
                  if ( !mp.count(a) ) {
                      mp[a] = nodes, na = nodes;
                      nodes++;
                  }   
                  else
                      na = mp[a];
                  if ( !mp.count(b) ) {
                      mp[b] = nodes, nb = nodes;
                      nodes++;
                  }
                  else
                      nb = mp[b];
                  m[na][nb] = m[nb][na] = true;                   
           }
           while ( scanf( "%d", &a ) && scanf( "%d", &b ) ) {
                  if ( !a && !b )
                      break;
                  memset( visit, false, sizeof(visit) );
                  printf( "Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
                          count++, bfs(mp[a],b), a, b );
           }
    }   
}
